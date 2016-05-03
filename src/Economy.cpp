#include <iostream>
#include "Economy.hpp"

Economy::Economy() :
	households(N_HOUSEHOLDS, *this),
	firms(N_FIRMS, *this),
    labourMarket(*this)
{
}

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
