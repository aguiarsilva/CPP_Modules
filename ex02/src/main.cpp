#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "colors.hpp"
#include <iostream>

int main ()
{
    //Class construction tests:
    std::cout << GREEN << "Initiating constructor tests" << RESET << std::endl;
    std::cout << GREEN << "=== Testing ClapTrap constructors ===" << RESET << std:: endl;
        //ClapTrap with parameter constructor
    std::cout << GREEN << "Testing constructor with parameter name" << RESET << std::endl;
    ClapTrap h = ClapTrap("Bob");
    std::cout << "ClapTrap " << h.getName() << " with " << h.getHitPoints() 
            << " Hit Points, " << h.getEnergyPoints() 
            << " Energy Points and " << h.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    std::cout << std::endl;

    std::cout << GREEN << "=== Testing ScavTrap constructors ===" << RESET << std:: endl;
        //ScavTrap with default constructor
    std::cout << "Testing default constructor" << std::endl;
    ScavTrap a = ScavTrap();
    std::cout << "ScavTrap " << a.getName() << " with " << a.getHitPoints() 
            << " Hit Points, " << a.getEnergyPoints() 
            << " Energy Points and " << a.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    std::cout << std::endl;

        //ScavTrap with parameter constructor
    std::cout << GREEN << "Testing constructor with parameter name" << RESET << std::endl;
    ScavTrap b = ScavTrap("Robot");
    std::cout << "ScavTrap " << b.getName() << " with " << b.getHitPoints() 
            << " Hit Points, " << b.getEnergyPoints() 
            << " Energy Points and " << b.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    std::cout << std::endl;

        //ScavTrap copy constructor
    std::cout << GREEN << "Testing copy constructor" << RESET << std::endl;
    ScavTrap c(b);
    std::cout << "ScavTrap " << c.getName() << " with " << c.getHitPoints() 
            << " Hit Points, " << c.getEnergyPoints() 
            << " Energy Points and " << c.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    std::cout << std::endl;

        //Create new ScavTrap and assing an exist one to it
    std::cout << GREEN << "Testing assignement operator" << RESET << std::endl;
    ScavTrap d;
    d = a;
    std::cout << "ScavTrap " << d.getName() << " with " << d.getHitPoints() 
            << " Hit Points, " << d.getEnergyPoints() 
            << " Energy Points and " << d.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    std::cout << std::endl;

    std::cout << GREEN << "=== Testing FragTrap constructors ===" << RESET << std:: endl;

    std::cout << GREEN << "Testing FragTrap default constructor" << RESET << std::endl;
    FragTrap frag1;
    std::cout << "FragTrap " << frag1.getName() << " with " << frag1.getHitPoints() 
            << " Hit Points, " << frag1.getEnergyPoints() 
            << " Energy Points and " << frag1.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    std::cout << std::endl;

    // FragTrap with parameter constructor
    std::cout << GREEN << "Testing FragTrap constructor with parameter name" << RESET << std::endl;
    FragTrap frag2("FragMaster");
    std::cout << "FragTrap " << frag2.getName() << " with " << frag2.getHitPoints() 
            << " Hit Points, " << frag2.getEnergyPoints() 
            << " Energy Points and " << frag2.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    std::cout << std::endl;

    // FragTrap copy constructor
    std::cout << GREEN << "Testing FragTrap copy constructor" << RESET << std::endl;
    FragTrap frag3(frag2);
    std::cout << "FragTrap " << frag3.getName() << " with " << frag3.getHitPoints() 
            << " Hit Points, " << frag3.getEnergyPoints() 
            << " Energy Points and " << frag3.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    std::cout << std::endl;

    // Create new FragTrap and assign an existing one to it
    std::cout << GREEN << "Testing FragTrap assignment operator" << RESET << std::endl;
    FragTrap frag4;
    frag4 = frag1;
    std::cout << "FragTrap " << frag4.getName() << " with " << frag4.getHitPoints() 
            << " Hit Points, " << frag4.getEnergyPoints() 
            << " Energy Points and " << frag4.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    std::cout << std::endl;

    //Action tests
    std::cout << GREEN << "Starting Action Tests" << RESET << std::endl;

        //ScavTrap attacks someone and the attacked takes different amounts of damage
    ScavTrap e("Alice");
    ScavTrap f("Raul");
    std::cout << YELLOW << e.getName() << " has " << e.getHitPoints() << " Hit Points" << RESET << std::endl;
    std::cout << RED << f.getName() << " has " << f.getEnergyPoints() << " Energy Points" << RESET << std::endl;
    f.attack("Alice");
    e.takeDamage(20);
    std::cout << RED << f.getName() << " has " << f.getEnergyPoints() << " Energy Points" << RESET << std::endl;
    std::cout << YELLOW << e.getName() << " has " << e.getHitPoints() << " Hit Points" << RESET << std::endl;
    h.attack("Raul");
    f.attack("Bob");
    h.takeDamage(20);
    std::cout << RED << f.getName() << " has " << f.getEnergyPoints() << RESET << std::endl;
    std::cout << YELLOW << e.getName() << " has " << e.getHitPoints() << " Hit Points" << RESET << std::endl;
    std::cout << std::endl;

      // FragTrap attacks and takes damage
    FragTrap frag5("Destroyer");
    FragTrap frag6("Defender");
    
    std::cout << YELLOW << frag5.getName() << " has " << frag5.getHitPoints() << " Hit Points" << RESET << std::endl;
    std::cout << RED << frag6.getName() << " has " << frag6.getEnergyPoints() << " Energy Points" << RESET << std::endl;
    
    frag5.attack("Defender");
    frag6.takeDamage(30);
    
    std::cout << YELLOW << frag6.getName() << " has " << frag6.getHitPoints() << " Hit Points" << RESET << std::endl;
    std::cout << RED << frag5.getName() << " has " << frag5.getEnergyPoints() << " Energy Points" << RESET << std::endl;
    std::cout << std::endl;

    //Test if a change in ScavTrap copy doesn't affect the original
    std::cout << YELLOW << c.getName() << " has " << c.getHitPoints() << " Hit Points" << RESET << std::endl;
    std::cout << YELLOW << b.getName() << " has " << b.getHitPoints() << " Hit Points" << RESET << std::endl;
    c.takeDamage(20);
    std::cout << YELLOW << c.getName() << " has " << c.getHitPoints() << " Hit Points" << RESET << std::endl;
    std::cout << YELLOW << b.getName() << " has " << b.getHitPoints() << " Hit Points" << RESET << std::endl;
    std::cout << std::endl;

      // Test if a change in FragTrap copy doesn't affect the original
    std::cout << GREEN << "Testing FragTrap copy independence" << RESET << std::endl;
    std::cout << YELLOW << frag3.getName() << " has " << frag3.getHitPoints() << " Hit Points" << RESET << std::endl;
    std::cout << YELLOW << frag2.getName() << " has " << frag2.getHitPoints() << " Hit Points" << RESET << std::endl;
    frag3.takeDamage(25);
    std::cout << YELLOW << frag3.getName() << " has " << frag3.getHitPoints() << " Hit Points" << RESET << std::endl;
    std::cout << YELLOW << frag2.getName() << " has " << frag2.getHitPoints() << " Hit Points" << RESET << std::endl;
    std::cout << std::endl;

    //ScavTrap gets repaired
    c.takeDamage(7);
            //Try different repair amounts
    std::cout << BLUE << c.getName() << " has " << c.getHitPoints() << " Hit Points and " << c.getEnergyPoints() << " Energy Points" << RESET << std::endl;
    c.beRepaired(3);
    std::cout << BLUE << c.getName() << " has " << c.getHitPoints() << " Hit Points and " << c.getEnergyPoints() << " Energy Points" << RESET << std::endl;
    c.beRepaired(8);
    std::cout << BLUE << c.getName() << " has " << c.getHitPoints() << " Hit Points and " << c.getEnergyPoints() << " Energy Points" << RESET << std::endl;
    std::cout << std::endl;

        // FragTrap gets repaired
    std::cout << GREEN << "Testing FragTrap repair" << RESET << std::endl;
    frag3.takeDamage(15);
    std::cout << BLUE << frag3.getName() << " has " << frag3.getHitPoints() << " Hit Points and " << frag3.getEnergyPoints() << " Energy Points" << RESET << std::endl;
    frag3.beRepaired(5);
    std::cout << BLUE << frag3.getName() << " has " << frag3.getHitPoints() << " Hit Points and " << frag3.getEnergyPoints() << " Energy Points" << RESET << std::endl;
    frag3.beRepaired(10);
    std::cout << BLUE << frag3.getName() << " has " << frag3.getHitPoints() << " Hit Points and " << frag3.getEnergyPoints() << " Energy Points" << RESET << std::endl;
    std::cout << std::endl;

    //ScavTrap's function guardGate()
    std::cout << GREEN << "Testing ScavTrap specific guardGate() function" << RESET << std::endl;
    b.guardGate();
    std::cout << std::endl;

    // FragTrap's function highFivesGuys()
    std::cout << GREEN << "Testing FragTrap specific highFivesGuys() function" << RESET << std::endl;
    frag2.highFivesGuys();
    std::cout << std::endl;

//Edge cases
    std::cout << GREEN << "Testing edge cases" << RESET << std::endl;

    //Attack until out of energy
    std::cout << RED << f.getName() << " has " << f.getEnergyPoints() << " Energy Points" << RESET << std::endl;
    while (f.getEnergyPoints() > 0)
        f.attack("Alice");
    std::cout << RED << f.getName() << " has " << f.getEnergyPoints() << " Energy Points" << RESET << std::endl;
    //Try to attack after depletion of energy
    f.attack("Bob");
    std::cout << std::endl;

    // FragTrap attack until out of energy
    std::cout << GREEN << "Testing FragTrap energy depletion" << RESET << std::endl;
    std::cout << RED << frag5.getName() << " has " << frag5.getEnergyPoints() << " Energy Points" << RESET << std::endl;
    while (frag5.getEnergyPoints() > 0)
        frag5.attack("Target");
    std::cout << RED << frag5.getName() << " has " << frag5.getEnergyPoints() << " Energy Points" << RESET << std::endl;
      // Try to attack after depletion of energy
    frag5.attack("Target"); 
    std::cout << std::endl;

    //Damage until 0 hit points
    std::cout << GREEN << "Testing ScavTrap death" << RESET << std::endl;
    std::cout << YELLOW << b.getName() << " has " << b.getHitPoints() << " Hit Points" << RESET << std::endl;
    b.takeDamage(50);
    b.takeDamage(50);
    std::cout << YELLOW << b.getName() << " has " << b.getHitPoints() << " Hit Points" << RESET << std::endl;
    //Try to attack after 0 hitPoints
    b.attack("Raul");
    //Try to repair after 0 hitPoints
    b.beRepaired(7);
    std::cout << std::endl;

    // FragTrap damage until 0 hit points
    std::cout << GREEN << "Testing FragTrap death" << RESET << std::endl;
    std::cout << YELLOW << frag6.getName() << " has " << frag6.getHitPoints() << " Hit Points" << RESET << std::endl;
    frag6.takeDamage(50);
    frag6.takeDamage(50);
    std::cout << YELLOW << frag6.getName() << " has " << frag6.getHitPoints() << " Hit Points" << RESET << std::endl;
    frag6.attack("Target"); // Try to attack after 0 hitPoints
    frag6.beRepaired(10); // Try to repair after 0 hitPoints
    frag6.highFivesGuys(); // Try special ability after 0 hitPoints
    std::cout << std::endl;

    //Create a ScavTrap and assign it to itself
    std::cout << GREEN << "Self assignement test" << RESET << std::endl;
    ScavTrap g("Selfie");
    std::cout << "ScavTrap " << g.getName() << " with " << g.getHitPoints() 
            << "Hit Points, " << g.getEnergyPoints() 
            << " Energy Points and " << g.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    g = g; // self-assignement
    std::cout << "ScavTrap " << g.getName() << " with " << g.getHitPoints() 
            << "Hit Points, " << g.getEnergyPoints() 
            << " Energy Points and " << g.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    std::cout << std::endl;

    // Create a FragTrap and assign it to itself
    std::cout << GREEN << "FragTrap self assignment test" << RESET << std::endl;
    FragTrap selfFrag("FragSelfie");
    std::cout << "FragTrap " << selfFrag.getName() << " with " << selfFrag.getHitPoints() 
            << " Hit Points, " << selfFrag.getEnergyPoints() 
            << " Energy Points and " << selfFrag.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    selfFrag = selfFrag; // self-assignment
    std::cout << "FragTrap " << selfFrag.getName() << " with " << selfFrag.getHitPoints() 
            << " Hit Points, " << selfFrag.getEnergyPoints() 
            << " Energy Points and " << selfFrag.getAttackDamage() 
            << " Attack Damage created" << std::endl;
    std::cout << std::endl;

    //Test the destructor by letting objects go out of scope
    std::cout << GREEN << "Destructor Test" << RESET << std::endl;
    {
        ScavTrap temp("inScope");
        std::cout << "Inside Block: " << temp.getName() << " exists." << std::endl;
    }
    std::cout << "Exited block. inScope should be destroyed above" << std::endl;
    std:: cout << std::endl;

    std::cout << GREEN << "Testing destructor with dynamic allocation" << RESET << std::endl;
    ScavTrap* dynamicTrap = new ScavTrap("HeapTrap");
    delete dynamicTrap;
    std::cout << "HeapTrap deleted" << std::endl;
    std::cout << std::endl;

    
    // Test FragTrap destructor by letting objects go out of scope
    std::cout << GREEN << "FragTrap Destructor Test" << RESET << std::endl;
    {
        FragTrap tempFrag("FragInScope");
        std::cout << "Inside Block: " << tempFrag.getName() << " exists." << std::endl;
    }
    std::cout << "Exited block. FragInScope should be destroyed above" << std::endl;
    std::cout << std::endl;

    // Test FragTrap destructor with dynamic allocation
    std::cout << GREEN << "Testing FragTrap destructor with dynamic allocation" << RESET << std::endl;
    FragTrap* dynamicFragTrap = new FragTrap("FragHeapTrap");
    delete dynamicFragTrap;
    std::cout << "FragHeapTrap deleted" << std::endl;
    std::cout << std::endl;

    // Test inheritance hierarchy destruction order
    std::cout << GREEN << "Testing proper destruction order" << RESET << std::endl;
    {
        std::cout << "Creating a FragTrap to demonstrate destruction order:" << std::endl;
        FragTrap inheritTest("InheritanceTest");
        std::cout << "FragTrap created, it will now be destroyed when leaving scope" << std::endl;
    }
    std::cout << "FragTrap should be destroyed first, then ClapTrap" << std::endl;
    std::cout << std::endl;

    return 0;
}
