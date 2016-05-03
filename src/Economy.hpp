#ifndef ECONOMY_HPP
#define ECONOMY_HPP

//#include <eigen3/Eigen/Dense>
#include <vector>
#include <random>

#include "Household.hpp"
#include "Firm.hpp"
#include "LabourMarket.hpp"
#include "AgentSet.hpp"

class Economy {
public:
    struct Config {
        std::vector<Firm::Config>       firmConfigs;
        std::vector<Household::Config>  hhConfigs;
    };

public:
	Economy(const std::vector<Firm::Config> &fConfs, const std::vector<Household::Config> &hhConfs);//int N_HOUSEHOLDS,int N_FIRMS);
    Economy(const Config &conf);

	void step();
	void print();

//    const int       N_HOUSEHOLDS = 2;
  //  const int       N_FIRMS = 2;

	AgentSet<Household>		households;	    // Households
	AgentSet<Firm>			firms;		    // Firms
	LabourMarket	        labourMarket;	    // Market for labour and factors

//    Eigen::Matrix<double,6,6>   SAM;            // Social accounting matrix
//    Eigen::RowVector<double,6>  prices;         // unit prices
//    Eigen::RowVector<double,6>  production;     // rate of production of each product/factor
};

#endif
