#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H

//#include <eigen3/Eigen/Dense>
#include "Agent.hpp"

class Household : public Agent {
public:
	Household(Economy &e) : Agent(e) {};
	Household(const Household &other) : Agent(other) {};

	void step();

	std::vector<double> beta; 		// utility coefficients for consumption u = sum c_i^beta_i
	std::vector<double> endowments;	// endowment of factors (per time step)

protected:
	void consume();
	double earnings();
};

#endif
