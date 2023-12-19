#include "complex.h"

int main() {
    Complex c1, c2;
    std::cout << "Enter the first complex number (real +/- imaginary): ";
    std::cin >> c1;

    std::cout << "Enter the second complex number (real +/- imaginary): ";
    std::cin >> c2;

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;
    Complex quotient = c1 / c2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Quotient: " << quotient << std::endl;

    return 0;
}
