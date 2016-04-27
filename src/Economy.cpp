#include <iostream>
#include "Economy.hpp"

Economy::Economy() : labourMarket(*this) {
	Household 	h(*this);
	Firm 		f(*this);

	for(int i=0; i<2; ++i) {
		households.push_back(h);
		firms.push_back(f);
	}
}

void Economy::step() {
	households.front().step();
	households.back().step();
	firms.front().step();
	firms.back().step();
	labourMarket.step();
}

void Economy::print() {
	std::cout 	<< firms.front().price << " " << firms.back().price << " "
				<< labourMarket.prices[0] << " " << labourMarket.prices[1] << " "
				<< firms.front().production << " " << firms.back().production
				<< std::endl;
}
