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
    virtual ~Expression();

    bool isRoot(double x) const;
      
    virtual explicit operator std::string() const = 0;

    virtual double operator()(double d) const = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const Expression& E);

    virtual Expression* clone() const = 0;

    // Return number of existing instances of class Expression
    // Used only for debug purposes
    static std::size_t get_count_expressions();

protected:
    // Default constructor
    Expression();

    // Copy constructor
    Expression(const Expression&);

    // total number of existing expressions -- only to help to detect bugs in the code
    static std::size_t count_expressions;
};
