#ifndef FIRM_H
#define FIRM_H

#include <eigen3/Eigen/Dense>
#include "Agent.hpp"

class Firm : public Agent {
public:
	Firm(Economy &e);
	Firm(const Firm &other);

	double	order(double amnt);
	void 	step();
	void 	optimiseFactorMix();

	double 		price;  		// current sale price per unit output
	Eigen::Vector3d inputs;		// raw materials per unit output (inc Value added)
	Eigen::Vector2d alpha;		// Cobb-Douglas coefficients
	double  	production;		// current production quantity per unit time 

protected:
	double 		sales;			// sales quantity per unit time
	Eigen::Vector2d factors;    // factors per unit output;
};

/*****
******/
inline Firm::Firm(Economy &e) : Agent(e) {
	price = randNextPrice();
	production = randNextDouble()*100;
	sales = 0;
}

inline Firm::Firm(const Firm &other) : Firm(other.root) {

}

/*****
******/
inline double Firm::order(double amnt) {
	sales += amnt;
	return(amnt); // return amount supplied
}

#endif
