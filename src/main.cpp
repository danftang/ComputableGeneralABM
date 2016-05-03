#include <iostream>
//#include <eigen3/Eigen/Dense>
#include "Economy.hpp"
#include "Experiments.hpp"

int main() {
	Economy myEconomy(Experiments::chapter3);

	for(int t=0; t<100; ++t) {
		myEconomy.step();
		myEconomy.print();
	}
}
