#include "Sed.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "\nUsage: " << argv[0] << " <filename> <search_string> <replace_string>" << std::endl;
        return 1;
    }

    Sed toReplace(argv[1], argv[2], argv[3]);
    if (toReplace.replaceStr())
        return 0;
    else
        return 1;
}