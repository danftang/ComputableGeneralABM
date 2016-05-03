#include <iostream>
#include "Household.hpp"
#include "Economy.hpp"

void Household::step() {
	consume();
	root.labourMarket.labour.offer(conf.endowments[0]);
	root.labourMarket.capital.offer(conf.endowments[1]);
}

void Household::consume() {
	int i=0;
	double e = earnings();

	for(Firm &f : root.firms) {
		buy(f, conf.beta[i]*e/f.price);
		++i;
	}
}

double Household::earnings() {
	return(root.labourMarket.labour.price * conf.endowments[0] + root.labourMarket.capital.price * conf.endowments[1]);
}
