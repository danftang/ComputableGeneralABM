#ifndef FIRM_H
#define FIRM_H

//#include <eigen3/Eigen/Dense>
#include "Agent.hpp"
#include <vector>

class Firm : public Agent, public Market {
public:
    struct Config {
        std::vector<double>     alpha;	    // Cobb-Douglas coefficients for factors
        std::vector<double>     inputs;     // raw materials per unit output (inc Value added)
    };

public:
	Firm(Economy &e);
	Firm(const Firm &other);

	void 	step();
	void 	optimiseFactorMix();
//	std::vector<double>     inputs;// raw materials per unit output (inc Value added)
//	std::vector<double>     alpha;	    // Cobb-Douglas coefficients for factors
    Config  conf;
	double  factors[2];      // factors per unit output;
};

/*****
******/
inline Firm::Firm(Economy &e) : Agent(e), Market(randNextPrice()) {
	offers = randNextDouble()*100;
}

inline Firm::Firm(const Firm &other) : Firm(other.root) {
}

#endif
