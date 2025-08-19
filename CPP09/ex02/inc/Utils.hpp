/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:58:09 by baguiar-          #+#    #+#             */
/*   Updated: 2025/08/19 22:33:43 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <climits>
#include <cmath>

class Utils
{
    private:

        //Orthodox Canonical Form
        Utils();
        ~Utils();
        Utils(Utils const& other);
        Utils &operator=(Utils const& other);

    public:

        static std::vector<int> inputParsing(int argc, char **argv);
        static void inputValidation(std::vector<int> const& input);
        static bool isValidNum(std::string const& str);
        static int strToInt(std::string const& str);
        static void displayErr(std::string const& msg);
        static void displayVec(std::vector<int> const& vec, std::string const& label);
        //static bool duplicatesCheck(std::vector<int> const& input);
        static int calculateFordJohnsonBound(int n);
        static int calculateInformationTheoreticMinimum(int n);
};

#endif
