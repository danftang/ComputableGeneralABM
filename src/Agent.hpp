#include "Economy.hpp"

#include <random>

class Agent {
public:
	Agent(Economy &e) : root(e), realDist(0.0,1.0) {}

	static double nextDouble() {return(realDist(randGen));}

	Economy &root;
	static std::default_random_engine		randGen;
	static std::uniform_real_distribution 	realDist;
}