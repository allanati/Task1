#include <iostream>
#include "Header.hpp"

using namespace lab;

int main()
{
    std::string a, b;
    std::cout << "Enter two numbers\n";
    std::cin >> a >> b;
    std::cout << "Sum or multiplication?";
    std::string s;
    std::cin >> s;
    if (s == "Sum") {
        Summa(a, b, a.length(), b.length());
        printResult(b);
    }
    else {

    }
}
