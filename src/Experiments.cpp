#include "Experiments.hpp"

const Economy::Config Experiments::chapter3 =
{
    {                       //---- Firm configs
        {
            {0.8,0.2},          // alphas
            {0.2,0.3,0.5}       // inputs
        },{
            {0.4,0.6},          //...
            {0.5,0.25,0.25}
        }
    },{                     //---- Household configs
        {
            {0.3, 0.7},         // betas
            {30.0, 20.0}        // endowments
        },{
            {0.6, 0.4},         //...
            {20.0, 5.0}
        }
    }
};

