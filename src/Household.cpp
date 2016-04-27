#include <iostream>
#include "Household.hpp"
#include "Economy.hpp"

void Household::step() {
	consume();
	root.labourMarket.offer(endowments);
}

void Household::consume() {
	int i=0;
	double e = earnings();
	double consumption;

	for(Firm &f : root.firms) {
		consumption = beta[i]*e/f.price;
		f.order(consumption);
//		std::cout << "Consumption = " << consumption << std::endl;
		++i;
	}
}

double Household::earnings() {
	return(root.labourMarket.prices * endowments);
}