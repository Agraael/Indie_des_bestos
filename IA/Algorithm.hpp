//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include <utility>
#include <vector>
#include <functional>

typedef struct s_choice {
	int first;
	int second;
} t_choice;

class Algorithm {
public:
	Algorithm() {};
	std::pair<int, int> defensiveMove(std::vector<std::string> &,
					   std::vector<std::string> &,
					   std::pair<int, int> &);
	std::pair<int, int> find_nearest_safe_point(std::vector<std::string> &,
                                           std::vector<std::string> &,
						    std::pair<int, int> &,
						    std::pair<int, int> &);
};
