#ifndef ECONOMY_HPP
#define ECONOMY_HPP

#include <eigen3/Eigen/Dense>
#include <list>
#include <random>

#include "Household.hpp"
#include "Firm.hpp"
#include "LabourMarket.hpp"

class Economy {
public:
	Economy();

	void step();
	void print();

	std::list<Household>		households;	// Households
	std::list<Firm>				firms;		// Firms
	LabourMarket				labourMarket;	// Market for labour and factors
};

#endif