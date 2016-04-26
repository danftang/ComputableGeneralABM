#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H

#include <eigen3/Eigen/Dense>
#include "Agent.hpp"
#include "Economy.hpp"

class Household : public Agent {
public:
	Household(Economy &e) : Agent(e) {};

	void step();

//	double consumption(int good, Eigen::vector2d &goodsPrices, Eigen::vector2d &factorPrices);

protected:
	void consume();
	double earnings();

	double earnings;
	Eigen::vector2d endowments;	// endowment of factors (per time step)
	Eigen::vector2d beta; 		// utility coefficients u = sum c_i^beta_i
};

inline Household::consumption(int good, Eigen::vector2d &goodsPrices, Eigen::vector2d &factorPrices) {
		return(beta[good]*earnings/goodsPrices[good]); // TODO: finish
}

#endif