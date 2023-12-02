/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>

#include "expression.h"

class Polynomial : public Expression {
    public:

        std::vector<double> coeff;

        Polynomial(const std::vector<double>& v);

        Polynomial(double d);

        Polynomial(const Polynomial& p);

	    ~Polynomial() override = default; 

        explicit operator std::string() const override;

        double operator()(double d) const override;

        Expression* clone() const override;

        Polynomial& operator =(Polynomial p);

        Polynomial operator +=(const Polynomial& p);

        Polynomial operator +=(double d);

	    friend Polynomial operator+(Polynomial a, const Polynomial& b);

	    friend Polynomial operator+(Polynomial& a, double b);

        double& operator [](int i);

        const double& operator [](int i) const;
};