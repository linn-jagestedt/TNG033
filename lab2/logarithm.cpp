/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "logarithm.h"
#include "polynomial.h"

#include <cmath>
#include <format>

Logarithm::Logarithm() {
    c1 = 0;
    c2 = 0;
    b = 2;

	std::vector<double> coeff = { 0,1 };
	E = new Polynomial{coeff};
}

Logarithm::Logarithm(const Expression& E, double c1, double c2, unsigned int b) {
    this->c1 = c1;
    this->c2 = c2;
    this->b = b;
    
    this->E = E.clone();
}

Logarithm::Logarithm(const Logarithm& l) : Expression() {
    c1 = l.c1;
    c2 = l.c2;
    b = l.b;

    delete E;
    E = (*l.E).clone();
}

Logarithm::~Logarithm() { 
	c1 = 0;
	c2 = 0;
	b = 0;
	delete E;
	E = nullptr;
}

Logarithm::operator std::string() const {
    return std::format("{:.2} + {:.2} * Log_{:1}({})", c1, c2, b, (std::string)(*E));
}

double Logarithm::operator()(double d) const {
    return c1 + c2 * (log10((*E)(d)) / log10(b));
}

Expression* Logarithm::clone() const {
    return new Logarithm(*this);
}

Logarithm& Logarithm::operator =(Logarithm l) {
    c1 = l.c1;
    c2 = l.c2;
    b = l.b;
    E = l.E->clone();

    return *this;
}

void Logarithm::set_base(unsigned int b) {
    this->b = b;
}