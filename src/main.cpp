#include <iostream>
#include <eigen3/Eigen/Dense>
#include "Economy.hpp"

using namespace Eigen;

int main() {
	Economy myEconomy;

	myEconomy.firms.front().alpha << 0.8, 0.2;
	myEconomy.firms.front().inputs << 0.2, 0.3, 0.5;

	myEconomy.firms.back().alpha << 0.4, 0.6;
	myEconomy.firms.back().inputs << 0.5, 0.25, 0.25;

	myEconomy.households.front().beta << 0.3, 0.7;
	myEconomy.households.front().endowments << 30.0, 20.0;

	myEconomy.households.back().beta << 0.6, 0.4;
	myEconomy.households.back().endowments << 20.0, 5.0;
	
	for(int t=0; t<100; ++t) {
		myEconomy.step();
		myEconomy.print();
	}
}