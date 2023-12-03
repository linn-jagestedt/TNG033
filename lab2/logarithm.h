/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

#include "expression.h"

class Logarithm : public Expression {
    public:

        double c1, c2;

        unsigned int b;

        Expression* E;

        Logarithm();

        Logarithm(const Expression& E, double c1, double c2, unsigned int b);

        Logarithm(const Logarithm& l);

	    ~Logarithm() override; 
        
        explicit operator std::string() const override;

        double operator()(double d) const override;

        Expression* clone() const override;

        Logarithm& operator =(const Logarithm& l);

        void set_base(unsigned int b);
};
