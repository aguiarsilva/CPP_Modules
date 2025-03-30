#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain 
{
    public:
        Brain();
        Brain(const Brain& obj);
        ~Brain();
        Brain& operator=(const Brain& other); 
        
    private:
        std::string ideas[100];
};

#endif
