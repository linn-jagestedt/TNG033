/******************************* 
 * Lab 3: exercise 2            *
 * Polynomial class             *
 * Header file                  *
 *******************************/

#include <map>
#include <vector>
#include <string>

class Polynomial 
{
    public: 
        ~Polynomial() = default;

        Polynomial() = default; 
        
        Polynomial(const int);
        
        Polynomial(const int, const int); 
        
        Polynomial(const std::initializer_list<std::pair<int, int>>&); // no loops
        
        Polynomial(const Polynomial&) = default;

        int degree() const;

        explicit operator std::string() const;

        Polynomial& operator +=(const Polynomial&);

        Polynomial& operator -=(const Polynomial&);
        
        Polynomial& operator *=(const Polynomial&);
        
        bool operator ==(const Polynomial&) const;

        bool operator !=(const Polynomial&) const;
        
        inline Polynomial& operator =(const Polynomial&) = default;

        friend std::ostream& operator<<(std::ostream&, const Polynomial&);

        friend Polynomial operator+(Polynomial, const Polynomial&);
        
        friend Polynomial operator-(Polynomial, const Polynomial&);

        friend Polynomial operator*(Polynomial, const Polynomial&);

        friend Polynomial operator +(int, const Polynomial&);
        
        friend Polynomial operator -(int, const Polynomial&);
        
        friend Polynomial operator *(int, const Polynomial&);

        friend bool operator ==(Polynomial, int);
    
    private:

        std::map<int, int> m_coeffs; // non-zero terms only
};