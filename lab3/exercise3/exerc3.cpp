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

int main() {
    std::cout << "Enter number of terms: ";
    int n;
    std::cin >> n;

    // create a vector and fill with values from 0 to n
    std::vector<double> power_terms(n);
    std::iota(power_terms.begin(), power_terms.end(), 0); 

    std::vector<double> sum_terms(n);

    //calculate sum for each value of n and store in sum_terms
    std::transform(power_terms.begin(), power_terms.end(), sum_terms.begin(), [](double d) {
        return 
            4.0 / (8*d + 1.0) -
            2.0 / (8*d + 4.0) -
            1.0 / (8*d + 5.0) -
            1.0 / (8*d + 6.0);
    });

    //calculate power for each value of n and store in power_terms
    std::transform(power_terms.begin(), power_terms.end(), power_terms.begin(), [](double d) { return std::pow(16.0, -d); });

    //calculate the product for each sum_term and power_term
    double product = std::inner_product(sum_terms.begin(), sum_terms.end(), power_terms.begin(), 0.0);

    std::cout << std::format("pi = {:.16f}\n", product);
}