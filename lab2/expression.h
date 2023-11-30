/*************************
 * Class Expression       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

constexpr double Epsilon = 1.0e-5;
class Expression {
public:
    // Destructor
    virtual ~Expression() {
        --count_expressions;
    }

    virtual bool isRoot(double x);
      
    virtual explicit operator std::string();

    virtual double operator()(double d);
    
    friend std::ostream& operator<<(std::ostream& os, const Expression& E);

    virtual Expression& clone(Expression E);

    // Return number of existing instances of class Expression
    // Used only for debug purposes
    static std::size_t get_count_expressions();

protected:
    // Default constructor
    Expression() {
        ++count_expressions;
    }

    // Copy constructor
    Expression(const Expression&) {
        ++count_expressions;
    }

    // total number of existing expressions -- only to help to detect bugs in the code
    static std::size_t count_expressions;
};
