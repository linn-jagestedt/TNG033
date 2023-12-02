/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"
#include <cmath>
#include <format>

Polynomial::Polynomial(const std::vector<double>& v) {
	for (double coeff : v) {
		this->coeff.push_back(coeff);
	}
}

Polynomial::Polynomial(double d) {
    coeff = {d};
}

Polynomial::Polynomial(const Polynomial& p) : Expression() {
	for (double coeff : p.coeff) {
		this->coeff.push_back(coeff);
	}
}

Polynomial::operator std::string() const {
    std::string result = "";

    for (size_t i = 0; i < coeff.size(); i++) {

        if (i == 0) {
            result += std::format("{:.2f}", coeff[i]);
        } else {
            std::string s1 = coeff[i] < 0 ? " - " : " + ";
            std::string s2 = " * X^" + std::to_string(i);
            result += std::format("{}{:.2f}{}", s1, std::abs(coeff[i]), s2);
        }
    }

    return result;
}

double Polynomial::operator()(double d) const {
    double result = 0;

    for (size_t i = 0; i < coeff.size(); i++) {
        result += coeff[i] * std::pow(d, i);
    }

    return result;
}

Expression* Polynomial::clone() const {
    return new Polynomial(*this);
}

Polynomial& Polynomial::operator =(Polynomial p) {
    std::swap(coeff, p.coeff);
    return *this;
}

Polynomial Polynomial::operator +=(const Polynomial& p)
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

Polynomial Polynomial::operator +=(double d) {
    coeff[0] += d;
    return *this;
}

Polynomial operator+(Polynomial a, const Polynomial& b){ //Mixed-mode arithmetic
	return a += b;
}

Polynomial operator+(Polynomial& a, double b){
	return a + Polynomial(b);
}

double& Polynomial::operator [](int i) {
    return coeff[i];
}

const double& Polynomial::operator [](int i) const {
    return coeff[i];
}