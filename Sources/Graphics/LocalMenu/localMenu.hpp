//
// Created by Ludovica Pagliarani on 31/05/2018.
//

#ifndef LOCALSMENU_HPP
#define LOCALSMENU_HPP

#include <vector>
#include <functional>
#include <unordered_map>
#include "IrrlichtLib.hpp"
#include "EventManager.hpp"
#include "Gen.hpp"

namespace graphic
{
	enum sizeMap {
		SMALL,
		MEDIUM,
		LARGE
	};

	enum entityMap {
		STANDARD,
		DISTRUCTIBLE
	};

	class localMenu
	{
		public:
			localMenu(graphic::IrrlichtLib *&lib) : _lib(lib) {}
			void					display();
			void					updateDisplay();
			std::string	const		&getMapName() const noexcept { return _name; }
			GenerationSize const	&getGenSize() const noexcept { return _genSizeTab[_genSize]; }
			GenerationMod const		&getGenMode() const noexcept { return _genModeTab[_genMode]; }
			int	const				&getPlayerNb() const noexcept { return _playersNb; }
			int	const				&getIaNb() const noexcept { return _aisNb; }
		private:
			graphic::IrrlichtLib	*_lib;
			std::string		_name;
			int	_genSize;
			int	_genMode;
			irr::gui::IGUIImage *_iaNbImg;
			irr::gui::IGUIImage *_playerNbImg;
			irr::gui::IGUIImage *_mapSizeImg;
			irr::gui::IGUIImage *_mapModImg;
			graphic::infos_t _iaNbInfos;
			graphic::infos_t _playerNbInfos;
			graphic::infos_t _mapSizeInfos;
			graphic::infos_t _mapModInfos;
			int				_playersNb;
			int				_aisNb;

			const std::unordered_map<graphic::controllerUser, std::function<void()>>	_updateNumberEntity = {
				{graphic::controllerUser::PLAYER_DOWN, [this](){ (_playersNb == 1) ? _playersNb = 1 : _playersNb--; }},
				{graphic::controllerUser::PLAYER_UP, [this](){ (_playersNb == 2) ? _playersNb = 2 : _playersNb++; }},
				{graphic::controllerUser::IA_DOWN, [this](){ (_aisNb == 0) ? _aisNb = 0 : _aisNb--; }},
				{graphic::controllerUser::IA_UP, [this](){ (_aisNb == 3) ? _aisNb = 3 : _aisNb++; }},
				{graphic::controllerUser::MAP_NEXT, [this](){ (_genMode == 1) ? _genMode-- : _genMode++; }},
				{graphic::controllerUser::MAP_PREV, [this](){ (_genMode == 0) ? _genMode++ : _genMode--; }},
				{graphic::controllerUser::MAP_SIZE_UP, [this](){ (_genSize == 2) ? _genSize = 0 : _genSize++; }},
				{graphic::controllerUser::MAP_SIZE_DOWN, [this](){ (_genSize == 0) ? _genSize = 2 : _genSize--; }}
			};

			const std::vector<GenerationSize>	_genSizeTab = {GenerationSize::Small, GenerationSize::Medium, GenerationSize::Big};
			const std::vector<GenerationMod>	_genModeTab = {GenerationMod::FullDest, GenerationMod::Standard};

			void	printNumber(graphic::infos_t &, irr::gui::IGUIImage *&, int);
			void	printGoodOneMod();
			void	printGoodOneSize();
			void	printBackground();
			void	printMenuTitle();
			void	printMapName();
			void	printButtonsPlayer();
			void	printButtonsIa();
			void	printButtonsChooseMap();
			void	printCoreButtons();
	};
}

#endif //LOCALMENU_HPP
