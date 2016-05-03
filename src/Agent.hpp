#ifndef AGENT_HPP
#define AGENT_HPP

#include <random>
#include "Market.hpp"

class Economy;

class Agent {
public:
	Agent(Economy &e) : root(e), cost(0.0) {}
	Agent(const Agent &other) : root(other.root) {};

	void buy(Market &m, double amnt) {m.bid(amnt); cost += amnt*m.price;}

	static double randNextDouble() {return(realDist(randGen));}
	static double randNextPrice() {return(priceDist(randGen));}

	Economy &root;
	double cost;
	static std::default_random_engine				randGen;
	static std::uniform_real_distribution<double> 	realDist;
	static std::uniform_real_distribution<double>	priceDist;
};

#endif
