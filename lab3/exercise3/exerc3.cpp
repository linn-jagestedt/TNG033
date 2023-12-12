/*********************************************
 * Lab 3: exercise 3                         *
 * Program to compute an approximation of pi *
 * STL-algorithms should be used             *
 *********************************************/

#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <algorithm>
#include <format>

double calculate(double n) {
    std::vector<double> terms {
        4.0 / (8*n + 1.0),
        -2.0 / (8*n + 4.0),
        -1.0 / (8*n + 5.0),
        -1.0 / (8*n + 6.0)
    };

    return std::accumulate(terms.begin(), terms.end(), 0.0);
}

int main() {
    std::cout << "Enter number of terms: ";
    int n;
    std::cin >> n;

    std::vector<double> sum(n);
    std::iota(sum.begin(), sum.end(), 0);
    std::transform(sum.begin(), sum.end(), sum.begin(), calculate);

    std::vector<double> exponents(n);
    std::iota(exponents.begin(), exponents.end(), 0);
    std::transform(exponents.begin(), exponents.end(), exponents.begin(), [](double d) { return std::pow(16.0, -d); });

    double product = std::inner_product(sum.begin(), sum.end(), exponents.begin(), 0.0);

    std::cout << std::format("pi = {:.16f}\n", product);
}