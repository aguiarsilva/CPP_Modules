/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:03:33 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/27 14:34:01 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

# define DEBUG 0

class RPN
{
    private:
        std::stack<int> m_num_stack;

        //Helper functions
        bool isOperator(std::string const& token);
        bool isNum(std::string const& token);
        int strToInt(std::string const& str); // exception should throw if invalid numbers
        void executeOperation(std::string const& op); // exception should throw if not enough operators

    public:
        RPN();
        RPN(RPN const &other);
        RPN &operator=(RPN const &other);
        ~RPN();

        int rpnCalculate(std::string const& expression); //exception throws std::runtime_error
};

#endif
