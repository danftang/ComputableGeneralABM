#ifndef LABOURMARKET_HPP
#define LABOURMARKET_HPP

#include "Agent.hpp"

class LabourMarket : public Agent {
public:
	LabourMarket(Economy &);
//	double overSupply(); // current total over-supply of factors
	void step();
	void offer(const Eigen::Vector2d &);	// offer factors for sale
	void bid(const Eigen::Vector2d &);	// bid to buy factors

	Eigen::RowVector2d  prices;
	Eigen::Vector2d  	offers;
	Eigen::Vector2d  	sales;
protected:

};

inline LabourMarket::LabourMarket(Economy &e) : Agent(e) {
	prices[0] = 1.0; // unit of price is 0th factor (1 unit of labour)
	prices[1] = randNextPrice(); // arbitrary initial condition
	offers.setZero();
	sales.setZero();
}

inline void LabourMarket::offer(const Eigen::Vector2d &off) {
	offers += off;
}

inline void LabourMarket::bid(const Eigen::Vector2d &sale) {
	sales += sale;

}

inline void LabourMarket::step() {
	prices[1] *= (sales[1]*offers[0])/(offers[1]*sales[0]);

	//prices[1] = 1.0;

//	if(sales[1]/sales[0] > offers[1]/offers[0]) {
//		prices[1] *= 1.1;
//	}
	offers.setZero();
	sales.setZero();
}

#endif
