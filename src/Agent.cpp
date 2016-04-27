
#include "Agent.hpp"

std::default_random_engine				Agent::randGen;
std::uniform_real_distribution<double> 	Agent::realDist(0.0,1.0);
std::uniform_real_distribution<double>	Agent::priceDist(0.01,1.0);	
