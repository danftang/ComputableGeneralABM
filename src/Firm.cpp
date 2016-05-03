#include "Firm.hpp"
#include "Economy.hpp"

/*****
******/
void Firm::step() {
	offer(0.5*(bids - offers));
	bids = 0;
	optimiseFactorMix();
	cost = 0.0;
	unsigned int m;
	for(m=0; m<conf.inputs.size()-1; ++m) {
        buy(root.firms[m], offers*conf.inputs[m]);
	}
	buy(root.labourMarket.labour, offers*factors[0]);
	buy(root.labourMarket.capital, offers*factors[1]);
	price = 0.5*price + 0.5*cost/offers;
}

void Firm::optimiseFactorMix() {
	factors[0] = conf.inputs.back()*conf.alpha[0]*pow(root.labourMarket.capital.price, conf.alpha[1]);
	factors[1] = conf.inputs.back()*conf.alpha[1]*pow(1.0/root.labourMarket.capital.price, conf.alpha[0]);
}
