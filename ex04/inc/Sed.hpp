#ifndef SED_HPP
# define SED_HPP

#include <string>

class Sed
{
    public:
        Sed(const std::string& file, const std::string& s1, const std::string& s2);
        bool replaceStr();
    
    private:
        std::string fileName;
        std::string searchString;
        std::string replaceString;
        bool validateArgs() const;
        std::string replaceExec(const std::string& line) const;
};

#endif