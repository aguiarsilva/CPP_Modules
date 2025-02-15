#include <iostream>
#include <string>

int main()
{
    std::string introBrain = "HI THIS IS BRAIN";

    std::string* stringPTR = &introBrain;
    std::string& stringREF = introBrain;

    std::cout << "\nAddresses: " << std::endl;
    std::cout << "Memory address of variable: " << &introBrain << std::endl;
    std::cout << "Memory address of stringPTR: " << &stringPTR << std::endl;
    std::cout << "Memory address of stringREF: " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "\nValues: " << std::endl;
    std::cout << "Value of introBrain: " << introBrain << std::endl;
    std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed by stringREF: " << stringREF << std::endl;

    return 0;
}