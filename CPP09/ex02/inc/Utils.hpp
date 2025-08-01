/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:58:09 by baguiar-          #+#    #+#             */
/*   Updated: 2025/08/01 12:12:18 by baguiar-         ###   ########.fr       */
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

};

#endif
