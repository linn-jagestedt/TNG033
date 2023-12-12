/******************************* 
 * Lab 3: exercise 2            *
 * Polynomial class             *
 * Header file                  *
 *******************************/

#include <map>
#include <vector>
#include <string>

class Polynomial {

    unsigned int _n;
    std::map<int, int> _coefficients_table; // non-zero terms only

    public: 
        Polynomial(); 
        ~Polynomial() = default;

        Polynomial(const std::vector<int>& coeffs); // no loops

        Polynomial(const Polynomial& p) = default;

        operator int() const; 
        explicit operator std::string() const;

        inline Polynomial& operator =(const Polynomial&) = default;

        inline int degree();
};