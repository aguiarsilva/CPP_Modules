#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "\nUsage: ./harlFilter <level>" << std::endl;
        return 1;
    }

    Harl test;
    test.complain(argv[1]);

    return 0;
}