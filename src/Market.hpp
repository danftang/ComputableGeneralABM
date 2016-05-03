#ifndef MARKET_H
#define MARKET_H

class Market
{
public:
    Market(double initPrice);

    void clear();
	void offer(double);	    // offer for sale
	double bid(double);	    // bid to buy

	double  price;
	double  offers;
	double  bids;

};

inline Market::Market(double initPrice) : price(initPrice) {
    offers = 0.0;
    bids = 0.0;
}

inline void Market::offer(double off) {
	offers += off;
}

inline double Market::bid(double sale) {
	bids += sale;
	return(sale);
}

inline void Market::clear() {
    offers = 0.0;
    bids = 0.0;
}

#endif // MARKET_H
