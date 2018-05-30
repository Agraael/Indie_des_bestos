/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef EVENTMANAGER_HPP_
	#define EVENTMANAGER_HPP_

#include <queue>

namespace IndieEvents
{
	enum IndieKeys
	{
		SETTINGS,
		BRIGTHNESS_DOWN,
		BRIGTHNESS_UP,
		SOUND_DOWN,
		SOUND_UP,
		ENTER_NAME1,
		ENTER_NAME2,
		EXIT_MAINMENU,
		START_SOLO,
		START_LOCAL,
		PLAYER_DOWN,
		PLAYER_UP,
		IA_DOWN,
		IA_UP,
		NORMAL_MAP,
		DEMOLITON_MAP,
		START_LOCAL_GAME,
		EXIT_SETTINGS,
		EXIT_LOCAL,
		ARROW_DOWN,
		ARROW_UP,
		ARROW_LEFT,
		ARROW_RIGHT,
		SPACEBAR,
		KEY_Z,
		KEY_Q,
		KEY_S,
		KEY_D,
		ENTER,
		ECHAP,
		RESTART,
		CONTINUE,
		MENU,
		QUIT,
		NO_INPUT
	};

	class EventManager
	{
		public:
			EventManager() {}
			void	setIndieKey(IndieKeys key) {_keys.push(key); }
			void	resetKey() noexcept {
				while (!_keys.empty())
					_keys.pop();
			}
			std::queue<IndieKeys>	&getKey() noexcept { return _keys; }
		private:
			std::queue<IndieKeys>	_keys;
	};
};

#endif /* !EVENTMANAGER_HPP_ */