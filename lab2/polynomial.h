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

        Polynomial(std::vector<double> v);

        Polynomial(double d);

        Polynomial(const Polynomial& p);

        virtual bool isRoot(double x);

        virtual explicit operator std::string();

        virtual double operator()(double d);

        Polynomial& operator =(Polynomial p);

        Polynomial& operator +=(Polynomial p);
        
        Polynomial& operator +(Polynomial p);

        Polynomial& operator +(double p);

        Polynomial& operator [](int i);
};