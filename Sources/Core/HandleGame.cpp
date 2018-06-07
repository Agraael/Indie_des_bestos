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

	generator.runGeneration(game.g_size, game.g_mod);
	generator.setPlayers(game.nb_player, game.nb_ia);
	if (_threeDMap)
		_threeDMap.reset();
	_threeDMap = std::make_shared<Map>(Map(interpret.createMap(generator.getMap())));
	initMapGround(game.g_size, id);
	for (auto line : _threeDMap->get3dMap()) {
		for (auto tab : line) {
			for (auto shared : tab) {
				entities::Entity *entity = shared.get();
				entity->setMap(_threeDMap);
				entity->setId(id);
				addCubeToMap(*entity, id);
		//		if (shared.get()->getType() == entities::entityType::PLAYER_TYPE)
		//			std::static_pointer_cast<Player>(shared).get()->setLibEventManager(lib);
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
	_lib->setCamera({(static_cast<double>(max.x) / 2), - (static_cast<double>(max.y) / 2) + 4, 13}, {static_cast<double>(max.x) / 2, static_cast<double>(max.y) / 2, 0});
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

void	HandleGame::updateMap()
{
	for (auto line : _threeDMap->get3dMap()) {
		for (auto tab : line) {
			for (auto shared : tab) {
		//		if (shared.get()->getType() == entities::entityType::PLAYER_TYPE)
		//			std::static_pointer_cast<Player>(shared).get()->interpretEvent();
				if (shared.get()->getType() == entities::entityType::IA_TYPE) {
					std::static_pointer_cast<Ia>(shared).get()->turn();
					updateEntity(shared.get());
				}
				//if (shared.get()->getType() == entities::entityType::BOMBS_TYPE)
				//	std::static_pointer_cast<Bombs>(shared).get()->checkExplosion();
			}
		}
	}
}

void	HandleGame::updateEntity(const entities::Entity *entity)
{
	for (auto elem : _disp) {
		if (elem->getID() == static_cast<irr::s32>(entity->getId())) {
			elem->setPosition(irr::core::vector3df(entity->getPos().second, entity->getPos().first, 1));
			elem->setMaterialTexture(0, _lib->getDevice()->getTexture(entity->getTexture()));
			//
		}
	}
}
