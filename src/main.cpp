#include <iostream>
//#include <eigen3/Eigen/Dense>
#include "Economy.hpp"

int main() {
	Economy myEconomy;

	myEconomy.firms[0].alpha = {0.8, 0.2};
	myEconomy.firms[0].inputs = {0.2, 0.3, 0.5};

	myEconomy.firms[1].alpha = {0.4, 0.6};
	myEconomy.firms[1].inputs = {0.5, 0.25, 0.25};

	myEconomy.households[0].beta = {0.3, 0.7};
	myEconomy.households[0].endowments = {30.0, 20.0};

	myEconomy.households[1].beta = {0.6, 0.4};
	myEconomy.households[1].endowments = {20.0, 5.0};

	for(int t=0; t<100; ++t) {
		myEconomy.step();
		myEconomy.print();
	}
}
