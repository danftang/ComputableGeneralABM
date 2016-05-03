#include <iostream>
#include "Economy.hpp"

Economy::Economy(const Config &conf) :
	households(conf.hhConfigs, *this),
	firms(conf.firmConfigs, *this),
    labourMarket(*this)
{}

void Economy::step() {
	households.step();
	firms.step();
	labourMarket.step();
}

void Economy::print() {
	std::cout 	<< firms[0].price << " " << firms[1].price << " "
				<< labourMarket.labour.price << " " << labourMarket.capital.price << " "
				<< firms[0].offers << " " << firms[1].offers
				<< std::endl;
}
