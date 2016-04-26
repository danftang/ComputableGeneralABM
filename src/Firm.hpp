#ifndef FIRM_H
#define FIRM_H

#include <eigen3/Eigen/Dense>
#include "Agent.hpp"

class Firm : public Agent {
public:
	Firm(Economy &e) : Agent(e) {};

//	double 	production();
	double	order(double amnt);
	void 	step();

protected:
	double 		price;  		// current sale price of output
	double  	production;		// current production quantity per unit time 
	double 		sales;			// sales quantity per unit time
	double 		orders;			// sales orders this timestep
	Eigen::Vector3d inputs;		// raw materials per unit output (inc Value added)
	Eigen::Vector2d factors;    // factors per unit output;
};

/*****
******/
inline Firm::Firm() {
	price = nextDouble() + 1.0;
}

/*****
******/
inline double Firm::order(double amnt) {
	orders += amnt;
	return(amnt); // return amount supplied
}

/*****
******/
inline void step() {
	sales = orders;
	orders = 0.0;
	production = production + 0.5*(sales - production);
	price = 
}

#endif
