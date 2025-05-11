/* 
Implement a class Complex which represents the Complex Number data type. 
Implement the following 
1. Constructor (including a default constructor which creates the complex number 0+0i). 
2. Overload operator* to multiply two complex numbers. 
3. Overload operators << and >> to print and read Complex Numbers. c++ 
*/ 
#include <iostream> 
class Complex { 
private: 
double real; 
double imag; 
public: 
// Default constructor 
Complex() : real(0.0), imag(0.0) {} 
// Parameterized constructor 
Complex(double r, double i) : real(r), imag(i) {} 
// Overloaded operator+ for addition of complex numbers 
Complex operator+(const Complex& other) const { 
return Complex(real + other.real, imag + other.imag); 
} 
    // Overloaded operator* for multiplication of complex numbers 
    Complex operator*(const Complex& other) const { 
        return Complex((real * other.real - imag * other.imag), (real * other.imag + imag * other.real)); 
    } 
 
    // Overloaded operator<< for output 
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) { 
        os << c.real; 
        if (c.imag >= 0) { 
            os << "+" << c.imag << "i"; 
        } else { 
            os << c.imag << "i"; 
        } 
        return os; 
    } 
 
    // Overloaded operator>> for input 
    friend std::istream& operator>>(std::istream& is, Complex& c) { 
        char sign, i; 
        is >> c.real >> sign >> c.imag >> i; // e.g., 3 + 4i or 3 - 4i 
        if (sign == '-') { 
            c.imag = -c.imag; 
        } 
        return is; 
    } 
}; 
 
int main() { 
Complex c1, c2; 
std::cout << "Enter first complex number (format: a + bi or a - bi): "; 
std::cin >> c1; 
std::cout << "Enter second complex number (format: a + bi or a - bi): "; 
std::cin >> c2; 
Complex sum = c1 + c2; 
Complex product = c1 * c2; 
std::cout << "Sum: " << sum << std::endl; 
std::cout << "Product: " << product << std::endl; 
return 0; 
}
