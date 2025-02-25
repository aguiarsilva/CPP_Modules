#include "ClapTrap.hpp"
#include "colors.hpp"
#include <iostream>

int main ()
{
    //Class construction tests:
    std::cout << GREEN << "Initiating constructor tests" << RESET << std::endl;

        //ClapTrap with default constructor
    std::cout << "Testing default constructor" << std::endl;
    ClapTrap a = ClapTrap();
    std::cout << "ClapTrap " << a.getName() << " with " << a.getHitPoints() 
            << "Hit Points, " << a.getEnergyPoints() 
            << " Energy Points and " << a.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    std::cout << std::endl;

        //ClapTrap with parameter constructor
    std::cout << GREEN << "Testing constructor with parameter name" << RESET << std::endl;
    ClapTrap b = ClapTrap("Bob");
    std::cout << "ClapTrap " << b.getName() << " with " << b.getHitPoints() 
            << "Hit Points, " << b.getEnergyPoints() 
            << " Energy Points and " << b.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    std::cout << std::endl;

        //ClapTrap copy constructor
    std::cout << GREEN << "Testing copy constructor" << RESET << std::endl;
    ClapTrap c(b);
    std::cout << "ClapTrap " << c.getName() << " with " << c.getHitPoints() 
            << "Hit Points, " << c.getEnergyPoints() 
            << " Energy Points and " << c.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    std::cout << std::endl;

        //Create new ClapTrap and assing an exist one to it
    std::cout << GREEN << "Testing assignement operator" << RESET << std::endl;
    ClapTrap d;
    d = a;
    std::cout << "ClapTrap " << d.getName() << " with " << d.getHitPoints() 
            << "Hit Points, " << d.getEnergyPoints() 
            << " Energy Points and " << d.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    std::cout << std::endl;

    //Action tests
    std::cout << GREEN << "Starting Action Tests" << RESET << std::endl;

        //ClapTrap attacks someone and the attacked takes different amounts of damage
    ClapTrap e("Alice");
    ClapTrap f("Raul");
    std::cout << YELLOW << e.getName() << " has " << e.getHitPoints() << " Hit Points" << RESET << std::endl;
    std::cout << RED << f.getName() << " has " << f.getEnergyPoints() << RESET << std::endl;
    f.attack("Alice");
    e.takeDamage(5);
    std::cout << RED << f.getName() << " has " << f.getEnergyPoints() << RESET << std::endl;
    std::cout << YELLOW << e.getName() << " has " << e.getHitPoints() << " Hit Points" << RESET << std::endl;
    f.attack("Alice");
    e.takeDamage(6);
    std::cout << RED << f.getName() << " has " << f.getEnergyPoints() << RESET << std::endl;
    std::cout << YELLOW << e.getName() << " has " << e.getHitPoints() << " Hit Points" << RESET << std::endl;
    std::cout << std::endl;

    //Test if a change in ClapTrap copy doesn't affect the original
    std::cout << YELLOW << c.getName() << " has " << c.getHitPoints() << " Hit Points" << RESET << std::endl;
    std::cout << YELLOW << b.getName() << " has " << b.getHitPoints() << " Hit Points" << RESET << std::endl;
    c.takeDamage(2);
    std::cout << YELLOW << c.getName() << " has " << c.getHitPoints() << " Hit Points" << RESET << std::endl;
    std::cout << YELLOW << b.getName() << " has " << b.getHitPoints() << " Hit Points" << RESET << std::endl;
    std::cout << std::endl;

    //ClapTrap gets repaired
    c.takeDamage(7);
            //Try different repair amounts
    std::cout << BLUE << c.getName() << " has " << c.getHitPoints() << " Hit Points and " << c.getEnergyPoints() << " Energy Points" << RESET << std::endl;
    c.beRepaired(3);
    std::cout << BLUE << c.getName() << " has " << c.getHitPoints() << " Hit Points and " << c.getEnergyPoints() << " Energy Points" << RESET << std::endl;
    c.beRepaired(8);
    std::cout << BLUE << c.getName() << " has " << c.getHitPoints() << " Hit Points and " << c.getEnergyPoints() << " Energy Points" << RESET << std::endl;
    std::cout << std::endl;

//Edge cases
    std::cout << GREEN << "Testing edge cases" << RESET << std::endl;

    //Attack until out of energy
    std::cout << RED << f.getName() << " has " << f.getEnergyPoints() << RESET << std::endl;
    while (f.getEnergyPoints() > 0)
        f.attack("Alice");
    std::cout << RED << f.getName() << " has " << f.getEnergyPoints() << RESET << std::endl;
    //Try to attack after depletion of energy
    f.attack("Bob");
    std::cout << std::endl;

    //Damage until 0 hit points
    std::cout << YELLOW << b.getName() << " has " << b.getHitPoints() << " Hit Points" << RESET << std::endl;
    b.takeDamage(3);
    b.takeDamage(7);
    std::cout << YELLOW << b.getName() << " has " << b.getHitPoints() << " Hit Points" << RESET << std::endl;
    //Try to attack after 0 hitPoints
    b.attack("Raul");
    //Try to repair after 0 hitPoints
    b.beRepaired(7);
    std::cout << std::endl;

    //Create a ClapTrap and assign it to itself
    std::cout << GREEN << "Self assignement test" << RESET << std::endl;
    ClapTrap g("Selfie");
    std::cout << "ClapTrap " << g.getName() << " with " << g.getHitPoints() 
            << "Hit Points, " << g.getEnergyPoints() 
            << " Energy Points and " << g.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    g = g; // self-assignement
    std::cout << "ClapTrap " << g.getName() << " with " << g.getHitPoints() 
            << "Hit Points, " << g.getEnergyPoints() 
            << " Energy Points and " << g.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    std::cout << std::endl;

    //Test the destructor by letting objects go out of scope
    std::cout << GREEN << "Destructor Test" << RESET << std::endl;
    {
        ClapTrap temp("inScope");
        std::cout << "Inside Block: " << temp.getName() << " exists." << std::endl;
    }
    std::cout << "Exited block. inScope should be destroyed above" << std::endl;
    std:: cout << std::endl;

    std::cout << GREEN << "Testing destructor with dynamic allocation" << RESET << std::endl;
    ClapTrap* dynamicTrap = new ClapTrap("HeapTrap");
    delete dynamicTrap;
    std::cout << "HeapTrap deleted" << std::endl;

    return 0;
}
