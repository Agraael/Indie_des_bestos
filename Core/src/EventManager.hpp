/*
** EPITECH PROJECT, 2018
** indie
** File description:
** header
*/

#ifndef EVENTMANAGER_HPP_
	#define EVENTMANAGER_HPP_

#include <list>

namespace ArcadeEvents
{
	enum ArcadeKey
	{
		NO_INPUT
	};

	class EventManager
	{
		public:
			EventManager() {}

			void	setArcadeKey(ArcadeKey k) {
				_listKey.push_back(static_cast<char>(k));
			}

			void	resetKey() noexcept {
				if (!_listKey.empty())
					_listKey.clear();
			}

			std::list<char>	&getKey() noexcept { return _listKey; }
		private:
			std::list<char>	_listKey;
	};
};

#endif /* !EVENTMANAGER_HPP_ */
