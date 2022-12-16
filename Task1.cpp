#include <iostream>
#include <string>
#include "Header.hpp"

int main()
{
    std::cout << "Enter A and B:  ";
    std::string a, b;
    std::cin >> a >> b;
    std::cout << "If you want sum, enter S. If you want multiplication, enter M:  ";
    std::string S_M;
    std::cin >> S_M;
    if (S_M == "S")
    {
        std::cout << an::Sum(a, b);
    }
    else {
        std::cout << an::Mult(a, b);
    }
}
