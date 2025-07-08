/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:58:37 by baguiar-          #+#    #+#             */
/*   Updated: 2025/02/21 14:58:37 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

//public methods:
Harl::Harl()
{

}

Harl::~Harl()
{
    return ;
}

void Harl::complain(std::string level)
{
    void (Harl::*functPtr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*functPtr[i])();
            return;
        }
    }

    std::cout << "\nInvalid complaint level!" << std::endl;
}

//private methods:
void Harl::debug(void)
{
    std::cout << " [ DEBUG ] " << std::endl;
    std::cout << " I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
    return ;
}

void Harl::info(void)
{
    std::cout << " [ INFO ] " << std::endl;
    std::cout << " I cannot believe adding extra bacont costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
    return ;
}

void Harl::warning(void)
{
    std::cout << " [ WARNING ] " << std::endl;
    std::cout << " I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
    return ;
}

void Harl::error(void)
{
    std::cout << " [ ERROR ] " << std::endl;
    std::cout << " This is unacceptable! I want to speak to the manager now." << std::endl;
    return ;
}