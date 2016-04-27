#ifndef AGENT_HPP
#define AGENT_HPP

#include <random>

class Economy;

class Agent {
public:
	Agent(Economy &e) : root(e) {}
	Agent(const Agent &other) : root(other.root) {};

	static double randNextDouble() {return(realDist(randGen));}
	static double randNextPrice() {return(priceDist(randGen));}

	Economy &root;
	static std::default_random_engine				randGen;
	static std::uniform_real_distribution<double> 	realDist;
	static std::uniform_real_distribution<double>	priceDist;	
};

#endif
