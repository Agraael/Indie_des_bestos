/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

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
	std::size_t		id = 0;
	GameMap			threedmap;

	_timeDispWinner = false;
	_winnerName = std::string("");
	generator.runGeneration(game.g_size, game.g_mod);
	generator.setPlayers(game.nb_player, game.nb_ia);
	if (_threeDMap)
		_threeDMap.reset();
	interpret.createMap(threedmap, generator.getMap());
	_threeDMap = std::make_shared<Map>(Map(threedmap));
	initMapGround(game.g_size, id);
	for (auto line : _threeDMap->get3dMap()) {
		for (auto tab : line) {
			for (auto shared : tab) {
				entities::Entity *entity = shared.get();
				entity->setMap(_threeDMap);
				entity->setId(id);
				addCubeToMap(*entity, id);
				if (shared.get()->getType() == entities::entityType::PLAYER_TYPE)
					reinterpret_cast<Player &>(*shared).setLibEventManager(_lib);
			}
		}
	}
}


void	HandleGame::initMapGround(const GenerationSize &size, std::size_t &id)
{
	Vector_t	max = _hGameSizeTab.at(size);

	for (std::size_t y = 0; y < max.y; y++) {
		for (std::size_t x = 0; x < max.x; x++) {
			_disp.push_back(_lib->createCube({static_cast<double>(x), static_cast<double>(y), 0}, "./Assets/media/grass.png", id));
			id++;
		}
	}
//	_lib->setCamera({(static_cast<double>(max.x) / 2), - (static_cast<double>(max.y) / 2) + 4, 13}, {static_cast<double>(max.x) / 2, static_cast<double>(max.y) / 2, 0});
	_lib->setCamera({(static_cast<double>(max.x) / 2), (static_cast<double>(max.y) / 2), 13}, {static_cast<double>(max.x) / 2, static_cast<double>(max.y) / 2, 0});
}

void	HandleGame::addCubeToMap(const entities::Entity &entity, std::size_t &id)
{
	if (entity.getLayout() == 0) {
		entities::entityPosition	pos = entity.getPos();
		if (entity.getType() == entities::entityType::DESTRUCTIBLE_TYPE || entity.getType() == entities::entityType::INDESTRUCTIBLE_TYPE)
			_disp.push_back(_lib->createCube({static_cast<double>(pos.second), static_cast<double>(pos.first), 1}, _textureMap.at(entity.getType()), id));
		else
			_disp.push_back(_lib->createSphere({static_cast<double>(pos.second), static_cast<double>(pos.first), 1}, _textureMap.at(entity.getType()), id));
		id++;
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
			}
		}
	}
	for (auto line : _threeDMap->get3dMap()) {
		for (auto tab : line) {
			for (auto shared : tab)
				shared->setMooved();
		}
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
