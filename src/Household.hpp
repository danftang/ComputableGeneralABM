#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H

#include <eigen3/Eigen/Dense>

class Household {
public:

	double consumption(int good, Eigen::vector2d &goodsPrices, Eigen::vector2d &factorPrices) {
		return(beta[good]*(factorPrices.transpose.dotprod.endowment)/goodsPrices[good]); // TODO: finish
	}


protected:
	Eigen::vector2d endowment;	// endowment of factors
	Eigen::vector2d beta; 		// utility coefficients
};
#endif