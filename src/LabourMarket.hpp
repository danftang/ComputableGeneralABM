#ifndef LABOURMARKET_HPP
#define LABOURMARKET_HPP

#include "Agent.hpp"

class LabourMarket : public Agent {
public:
//	double overSupply(); // current total over-supply of factors
	void offer(Eigen::Vector2d &);

	Eigen::RowVector2d  prices;
	Eigen::RowVector2d  offers;
protected:

};
#endif
