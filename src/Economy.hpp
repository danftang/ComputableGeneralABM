#ifndef ECONOMY_H
#define ECONOMY_H

#include <eigen3/Eigen/Dense>

class Economy {
public:


	Household			household[2];	// Households
	Firm				firm[2];		// Firms
	Eigen::Vector2d		prices; 		// prices of goods
	Eigen::Vector2d		omega;			// prices of factors
};

#endif