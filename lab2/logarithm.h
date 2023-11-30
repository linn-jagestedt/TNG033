/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

#include "expression.h"

class Logarithm : public Expression {

    public:

        Logarithm();

        Logarithm(double c1, double c2, unsigned int b, Expression E);

        Logarithm(const Logarithm& p);

        Logarithm& Logarithm::operator =(Logarithm);

        void Logarithm::set_base(unsigned int b);
        
    private:

        double c1, c2;

        unsigned int b;

        Expression E;
};
