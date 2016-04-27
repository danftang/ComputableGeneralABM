#include "Firm.hpp"
#include "Economy.hpp"

/*****
******/
void Firm::step() {
	production = production + 0.5*(sales - production);
	optimiseFactorMix();
	price = 0.5*price + 0.5*(inputs[0]*root.firms.front().price + inputs[1]*root.firms.back().price + root.labourMarket.prices*factors);
	sales = 0;
	root.firms.front().order(production*inputs[0]);
	root.firms.back().order(production*inputs[1]);
	root.labourMarket.bid(production*factors);
}

void Firm::optimiseFactorMix() {
	factors[0] = inputs[2]*alpha[0]*pow(root.labourMarket.prices[1]/root.labourMarket.prices[0], alpha[1]);
	factors[1] = inputs[2]*alpha[1]*pow(root.labourMarket.prices[0]/root.labourMarket.prices[1], alpha[0]);
}
