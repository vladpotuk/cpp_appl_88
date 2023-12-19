#include "complex.h"

Complex::Complex() : real(0.0), imaginary(0.0) {}

Complex::Complex(double realPart, double imaginaryPart) : real(realPart), imaginary(imaginaryPart) {}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imaginary + other.imaginary);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imaginary - other.imaginary);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex((real * other.real) - (imaginary * other.imaginary),
        (real * other.imaginary) + (imaginary * other.real));
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    if (denominator == 0) {
        std::cerr << "Error: Division by zero." << std::endl;
        exit(1);
    }

    return Complex(
        (real * other.real + imaginary * other.imaginary) / denominator,
        (imaginary * other.real - real * other.imaginary) / denominator
    );
}

std::ostream& operator<<(std::ostream& os, const Complex& complex) {
    os << complex.real;
    if (complex.imaginary >= 0) {
        os << "+";
    }
    os << complex.imaginary << "i";
    return os;
}

std::istream& operator>>(std::istream& is, Complex& complex) {
    char plusSign;
    is >> complex.real >> plusSign >> complex.imaginary;
    if (plusSign != '+' && plusSign != '-') {
        complex.imaginary = 0; 
        is.putback(plusSign);
    }
    return is;
}
