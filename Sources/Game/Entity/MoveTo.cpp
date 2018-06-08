/*
** EPITECH PROJECT, 2018
** indie
** File description:
** source
*/

#include "MoveTo.hpp"

std::pair<int, int> MoveTo::try_move_up(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map,
                                  std::pair<int, int> pos_character)
{
        if (pos_character.first < 0 || pos_character.second < 0 || pos_character.first >= static_cast<int>(map.size()))
                return {};
        for (auto &entity : map[pos_character.first + 1][pos_character.second]) {
		if (entity.get()->IsKinematic() == true)
			return {};
        }
	std::pair<int, int> to_return;
        to_return.first = pos_character.first + 1;
        to_return.second = pos_character.second;
        return to_return;
}

std::pair<int, int> MoveTo::try_move_down(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map,
                                  std::pair<int, int> pos_character)
{
        if (pos_character.first <= 0 || pos_character.second < 0)
                return {};
        for (auto &entity : map[pos_character.first - 1][pos_character.second]) {
		if (entity.get()->IsKinematic() == true)
			return {};
        }
	std::pair<int, int> to_return;
        to_return.first = pos_character.first - 1;
        to_return.second = pos_character.second;
        return to_return;
}

std::pair<int, int> MoveTo::try_move_right(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map,
                                  std::pair<int, int> pos_character)
{
	if (pos_character.first < 0 || pos_character.second <= 0)
		return {};
	for (auto &entity : map[pos_character.first][pos_character.second - 1]) {
		if (entity.get()->IsKinematic() == true)
			return {};
	}
	std::pair<int, int> to_return;
        to_return.first = pos_character.first;
        to_return.second = pos_character.second - 1;
	return to_return;
}

std::pair<int, int> MoveTo::try_move_left(std::vector<std::vector<std::vector<std::shared_ptr<entities::Entity>>>> &map,
				  std::pair<int, int> pos_character)
{
	if (pos_character.first < 0 || pos_character.second < 0 || pos_character.second >= static_cast<int>(map[pos_character.first].size()))
		return {};
	for (auto &entity : map[pos_character.first][pos_character.second + 1]) {
		if (entity.get()->IsKinematic() == true)
			return {};
	}
	std::pair<int, int> to_return;
	to_return.first = pos_character.first;
	to_return.second = pos_character.second + 1;
	return to_return;
}

MoveTo::MoveTo()
{
}

MoveTo::~MoveTo()
{
}
