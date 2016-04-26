#ifndef ECONOMY_H
#define ECONOMY_H

#include <eigen3/Eigen/Dense>
#include <vector>
#include <random>

#include "Household.hpp"
#include "Firm.hpp"

class Economy {
public:
	Economy();

	std::vector<Household>		households;	// Households
	std::vector<Firm>			firms;		// Firms
	Eigen::Vector2d				prices; 	// prices of goods
	Eigen::Vector2d				omega;		// prices of factors


};

#endif