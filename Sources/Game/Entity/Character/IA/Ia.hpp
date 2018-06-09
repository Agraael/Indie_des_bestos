//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef IA_HPP_
#define IA_HPP_

#include <vector>
#include <iostream>
#include <utility>
#include <functional>
#include <memory>
#include "TimeManager.hpp"
#include "Map.hpp"
#include "Character.hpp"
#include "Gen.hpp"

class Ia : public Character {
public:
	Ia(entities::entityPosition, bool, std::size_t, std::string);
	void update();
	~Ia() final { std::cout << "IA destroyed" << std::endl;}
private:
	Singleton::ChronoId _chrono;
	Singleton::ChronoId _chronoBomb;
};

#endif /* !ia */
