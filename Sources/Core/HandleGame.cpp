/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "SaveGame.hpp"
#include "HandleGame.hpp"
#include "InterpreteGeneration.hpp"
#include "MapGenerator.hpp"
#include "Gen.hpp"
#include "IrrlichtLib.hpp"
#include "Player.hpp"
#include "Ia.hpp"
#include "Bombs.hpp"

void	HandleGame::InitGame(const gameType_t &game)
{
	InterpreteGeneration	interpret;
	MapGenerator		generator;
	std::size_t		id = 2;
	GameMap			threedmap;

	_timeDispWinner = false;
	_winnerName = std::string("");
	_gameName = game.game_name;
	generator.runGeneration(game.g_size, game.g_mod);
	generator.setPlayers(game.nb_player, game.nb_ia);
	if (_threeDMap)
		_threeDMap.reset();
	_map = generator.getMap();
	interpret.createMap(threedmap, generator.getMap());
	_threeDMap = std::make_shared<Map>(threedmap);
	initMapGround(game.g_size, id);
	for (auto line : _threeDMap->get3dMap()) {
		for (auto tab : line) {
			for (auto shared : tab) {
				entities::Entity *entity = shared.get();
				entity->setMap(_threeDMap);
				addCubeToMap(*entity, shared->getId());
				if (shared.get()->getType() == entities::entityType::PLAYER_TYPE)
					reinterpret_cast<Player &>(*shared).setLibEventManager(_lib);
			}
		}
	}
}


void	HandleGame::initMapGround(const GenerationSize &size, std::size_t &id)
{
	Vector3d<int>	max = _hGameSizeTab.at(size);

	for (int y = -2; y < max.y + 2; y++) {
		for (int x = -2; x <max.x + 2; x++) {
			_disp.push_back(_lib->createCube({static_cast<double>(x), static_cast<double>(y), 0}, "./Assets/media/BrickGround.jpg", id));
			id++;
		}
	}
	//_lib->setCamera({(static_cast<double>(max.x) / 2), - (static_cast<double>(max.y) / 2) + 4, static_cast<double>(max.z)}, {static_cast<double>(max.x) / 2, static_cast<double>(max.y) / 2, 0});
	_lib->setCamera({(static_cast<double>(max.x) / 2), (static_cast<double>(max.y) / 2), static_cast<double>(max.z)}, {static_cast<double>(max.x) / 2, static_cast<double>(max.y) / 2, 0});
}

void	HandleGame::addCubeToMap(const entities::Entity &entity, std::size_t &id)
{
	if (entity.getLayout() == 0) {
		entities::entityPosition	pos = entity.getPos();
		if (entity.getType() == entities::entityType::DESTRUCTIBLE_TYPE || entity.getType() == entities::entityType::INDESTRUCTIBLE_TYPE)
			_disp.push_back(_lib->createCube({static_cast<double>(pos.second), static_cast<double>(pos.first), 1}, _textureMap.at(entity.getType()), id));
		else
			_disp.push_back(_lib->createSphere({static_cast<double>(pos.second), static_cast<double>(pos.first), 1}, _textureMap.at(entity.getType()), id));
	}
}

void	HandleGame::quitGame()
{
	for (auto elem : _disp)
		elem->remove();
	_disp.clear();
}

void	HandleGame::updateMap(bool &state)
{
	if (gameEnd()) {
		state = false;
		return;
	}
	for (auto line : _threeDMap->get3dMap()) {
		for (auto tab : line) {
			for (auto shared : tab) {
				if (shared.get()->getType() == entities::entityType::PLAYER_TYPE) {
					reinterpret_cast<Player &>(*shared).update();
					updateEntity(shared.get());
				}
			 	if (shared.get()->getType() == entities::entityType::IA_TYPE) {
					reinterpret_cast<Ia &>(*shared).update();
					updateEntity(shared.get());
				}
				if (shared.get()->getType() == entities::entityType::BOMBS_TYPE)
					reinterpret_cast<Bombs &>(*shared).update();
			}
		}
	}
	for (auto line : _threeDMap->get3dMap()) {
		for (auto tab : line) {
			for (auto shared : tab)
				shared->setMooved();
		}
	}
	updateAddEntity();
	_threeDMap->clean();
	updateDeletedEntity();
}

void	HandleGame::updateDeletedEntity()
{
	std::vector<std::size_t>	idVec = _threeDMap->getDeleteEntities();

	for (auto elem = _disp.begin(); elem != _disp.end(); elem++) {
		for (auto id : idVec) {
			if (static_cast<irr::s32>(id) == (*elem)->getID()) {
				(*elem)->remove();
				_disp.erase(elem);
			}
		}
	}
}

void	HandleGame::updateAddEntity()
{
	std::vector<std::shared_ptr<entities::Entity>>	entVec = _threeDMap->getModifiedEntities();

	for (auto elem : entVec) {
		entities::entityPosition	pos = elem->getPos();
		if (elem->getType() == entities::entityType::GONNAEXPLOSE_TYPE)
			_disp.push_back(_lib->createCube({static_cast<double>(pos.second), static_cast<double>(pos.first), 1}, _textureMap.at(elem->getType()), elem->getId()));
		if (elem->getType() == entities::entityType::BOMBS_TYPE)
			_disp.push_back(_lib->createSphere({static_cast<double>(pos.second), static_cast<double>(pos.first), 1}, _textureMap.at(elem->getType()), elem->getId(), {0.5, false}));
		else
			_disp.push_back(_lib->createSphere({static_cast<double>(pos.second), static_cast<double>(pos.first), 1}, _textureMap.at(elem->getType()), elem->getId(), {0.25, true}));
	}
}

void	HandleGame::updateEntity(const entities::Entity *entity)
{
	for (auto elem : _disp) {
		if (elem->getID() == static_cast<irr::s32>(entity->getId())) {
			elem->setPosition(irr::core::vector3df(entity->getPos().second, entity->getPos().first, 1));
		}
	}
}

bool	HandleGame::gameEnd() noexcept
{
	int	count = 0;

	for (auto line : _threeDMap->get3dMap()) {
		for (auto tab : line) {
			for (auto shared : tab) {
				const entities::Entity	*ent = shared.get();
				if (ent->getLayout() == 0 &&
					(ent->getType() == entities::entityType::IA_TYPE
					|| ent->getType() == entities::entityType::PLAYER_TYPE)) {
					count++;
					_winnerName = ent->getName();
				}
			}
		}
	}
	if (count > 1)
		return false;
	return true;
}

void	HandleGame::dumpPlayerName()
{
	if (_timeDispWinner == false) {
		//irr::core::dimension2d<irr::u32> size = _lib->getDevice()->getCurrentRenderTargetSize();
		//_lib->drawText(size.width, size.Height, 0, std::string(_winnerName + " won the game !! " + "\n click on echap to leave."));
		_timeDispWinner = true;
	}
}

void	HandleGame::saveGame()
{
//	SaveGame	s;

	//s.save(_gameName, _map);
}