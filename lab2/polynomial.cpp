/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"
#include <math.h>
#include <format>

Polynomial::Polynomial(std::vector<double> v) {
    coeff = {v};
}

Polynomial::Polynomial(double d) {
    coeff = {d};
}

Polynomial::Polynomial(const Polynomial& p) {
    coeff = {p.coeff};
}

bool Expression::isRoot(double x) {
    return std::abs((*this)(x)) < Epsilon;
}

explicit Polynomial::operator std::string() {
    std::string result = "";

    for (size_t i = 0; i < coeff.size(); i++) {
        result += std::format("{:.2} ", coeff[i]);
        result += i != 0 ? "* X^" + i : "";
        result += " + ";
    }

    return result;
}

double Polynomial::operator()(double d) {
    double result = 0;

    for (size_t i = 0; i < coeff.size(); i++) {
        result += coeff[i] * std::pow(d, i);
    }

    return result;
}

Polynomial& Polynomial::operator =(Polynomial p) {
    std::swap(coeff, p.coeff);
    return *this;
}

Polynomial& Polynomial::operator +=(Polynomial p)
{
    for (size_t i = 0; p.coeff.size(); i++) {
        if (i < coeff.size()) {
            coeff[i] += p.coeff[i];
        } else {
            coeff.push_back(p.coeff[i]);
        }
    }

    return *this;
}
