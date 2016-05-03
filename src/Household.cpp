#include <iostream>
#include "Household.hpp"
#include "Economy.hpp"

void Household::step() {
	consume();
	root.labourMarket.labour.offer(endowments[0]);
	root.labourMarket.capital.offer(endowments[1]);
}

void Household::consume() {
	int i=0;
	double e = earnings();

	for(Firm &f : root.firms) {
		buy(f, beta[i]*e/f.price);
		++i;
	}
}

double Household::earnings() {
	return(root.labourMarket.labour.price * endowments[0] + root.labourMarket.capital.price * endowments[1]);
}
