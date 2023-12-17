/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 *******************************/

#include "polynomial.h"
#include <algorithm>
#include <numeric>
#include <format>

Polynomial::Polynomial(const int coeff) {
    m_coeffs[0] = coeff;
}

Polynomial::Polynomial(const int coeff, const int degree) {
    m_coeffs[degree] = coeff;
}

Polynomial::Polynomial(const std::initializer_list<std::pair<int, int>>& coeffs) {
    m_coeffs.insert(coeffs.begin(), coeffs.end());
}


int Polynomial::degree() const {
    if (m_coeffs.empty()) {
        return 0;
    }

    return m_coeffs.rbegin()->first;
}

Polynomial::operator std::string() const {
    if (m_coeffs.empty()) {
        return "0";
    }

    std::string result = "";

    for (const auto& c : m_coeffs) {
        std::string s1 = c.second < 0 ? (result == "" ? "-" : " - ") : (result == "" ? "" : " + ");
        std::string s2 = "X^" + std::to_string(c.first);
        result += std::format("{}{}{}", s1, std::abs(c.second), s2);
    }

    return result;
}

Polynomial& Polynomial::operator +=(const Polynomial& rhs) {
    for (const auto& c : rhs.m_coeffs) {
        m_coeffs[c.first] += c.second;
        if (m_coeffs[c.first] == 0) {
            m_coeffs.erase(c.first);
        }
    }

    return (*this);
}

Polynomial& Polynomial::operator -=(const Polynomial& rhs) {
    for (const auto& c : rhs.m_coeffs) {
        m_coeffs[c.first] -= c.second;
        if (m_coeffs[c.first] == 0) {
            m_coeffs.erase(c.first);
        }
    }

    return (*this);
}

Polynomial& Polynomial::operator *=(const Polynomial& rhs) {
    std::map<int, int> result;

    for (const auto& c1 : rhs.m_coeffs) {
        for (const auto& c2 : m_coeffs) {
            int degree = c1.first + c2.first;
            result[degree] += c1.second * c2.second;
            if (result[degree] == 0) {
                result.erase(degree);
            }
        }
    }

    m_coeffs = std::move(result);
    return (*this);
}
        
Polynomial operator +(Polynomial lhs, const Polynomial& rhs) {
    lhs += rhs;
    return lhs;
}
        
Polynomial operator -(Polynomial lhs, const Polynomial& rhs) {
    lhs -= rhs;
    return lhs;
}
        
Polynomial operator *(Polynomial lhs, const Polynomial& rhs) {
    lhs *= rhs;
    return lhs;
}
        
bool Polynomial::operator ==(const Polynomial& rhs) const {
    return m_coeffs == rhs.m_coeffs;
}

bool Polynomial::operator !=(const Polynomial& rhs) const {
    return m_coeffs != rhs.m_coeffs;
}
    
std::ostream& operator<<(std::ostream& o, const Polynomial& p) {
    o << static_cast<std::string>(p);
    return o;
}
        
Polynomial operator +(int lhs, const Polynomial& rhs) {
    return static_cast<Polynomial>(lhs) + rhs;
}
        
Polynomial operator -(int lhs, const Polynomial& rhs) {
    return static_cast<Polynomial>(lhs) - rhs;
}
    
Polynomial operator *(int lhs, const Polynomial& rhs) {
    return static_cast<Polynomial>(lhs) * rhs;
}

bool operator ==(Polynomial lhs, int rhs) {
    return lhs == static_cast<Polynomial>(rhs);
}