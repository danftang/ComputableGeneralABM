
#include "Household.hpp"

void Household::step() {
	int i;

	consume();
	economy.labourMarket.offer(endowments);
}

void Household::consume() {
	i=0;
	double e = earnings();
	for(Firm f : economy.firms) {
		f.order(beta[i]*e/f.price);
		++i;
	}

}

double Household::earnings() {
	return(economy.labourMarket.prices * endowments);
}