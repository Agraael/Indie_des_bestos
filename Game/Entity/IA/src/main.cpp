//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "Ia.hpp"

int main()
{
	std::vector<std::string> position_map;
	position_map.push_back("111111111111111111111");
	position_map.push_back("100000000000000000001");
	position_map.push_back("100000000000000000001");
	position_map.push_back("100000000000000000001");
	position_map.push_back("100000000000000000001");
	position_map.push_back("100000000000000000001");
	position_map.push_back("100000000000000000001");
	position_map.push_back("100000000000000000001");
	position_map.push_back("100000000000000000001");
	position_map.push_back("100000000000000000001");
	position_map.push_back("100000000000000000001");
	position_map.push_back("100000000000000000001");
	position_map.push_back("111111111111111111111");

	std::vector<std::string> dynamic_map;
	dynamic_map.push_back("000000000000000000000");
	dynamic_map.push_back("000000000000000000000");
	dynamic_map.push_back("000000000000000000000");
	dynamic_map.push_back("000000000000000000000");
	dynamic_map.push_back("000000000000000000000");
	dynamic_map.push_back("000000000000000000000");
	dynamic_map.push_back("000000000000000000000");
	dynamic_map.push_back("000000000000000000000");
	dynamic_map.push_back("000000000000000000000");
	dynamic_map.push_back("000000000000000000000");
	dynamic_map.push_back("000000000000000000000");
	dynamic_map.push_back("000000000000000000000");
	dynamic_map.push_back("000000000000000000000");
	
	Ia *new_ia = new Ia(position_map, dynamic_map);
}
