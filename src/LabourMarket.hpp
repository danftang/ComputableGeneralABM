#ifndef LABOURMARKET_HPP
#define LABOURMARKET_HPP

#include "Agent.hpp"

class LabourMarket : public Agent {
public:
	LabourMarket(Economy &);
	void step();

	Market labour;
	Market capital;
};

inline LabourMarket::LabourMarket(Economy &e) :
    Agent(e),
    labour(1.0),
    capital(randNextPrice())
{ }

inline void LabourMarket::step() {
    capital.price *= capital.bids*labour.offers/(capital.offers*labour.bids);
    labour.clear();
    capital.clear();
}

#endif
