#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H

#include <eigen3/Eigen/Dense>
#include "Agent.hpp"

class Household : public Agent {
public:
	Household(Economy &e) : Agent(e) {};
	Household(const Household &other) : Agent(other) {};

	void step();

	Eigen::Vector2d beta; 		// utility coefficients u = sum c_i^beta_i
	Eigen::Vector2d endowments;	// endowment of factors (per time step)

protected:
	void consume();
	double earnings();
};

#endif