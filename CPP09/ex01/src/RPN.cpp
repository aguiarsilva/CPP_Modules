/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:36:40 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/28 12:36:21 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN() : m_num_stack()
{}

RPN::RPN(RPN const& other) : m_num_stack(other.m_num_stack)
{}

RPN &RPN::operator=(RPN const& other)
{
    if (this != &other)
        this->m_num_stack = other.m_num_stack;
    return (*this);
}

RPN::~RPN() {}

bool RPN::isOperator(std::string const& token)
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNum(std::string const& token)
{
    if (token.empty())
        return false;

    for (size_t i = 0; i < token.length(); i++)
    {
        if (!isdigit(token[i]))
            return false;
    }
    return true;
}

int RPN::strToInt(std::string const& str)
{
    if (str.empty())
    {
        throw std::runtime_error("Error: Empty string cannot be converted to number");
    }

    std::istringstream iss(str);
    int result;
    if (!(iss >> result) || !iss.eof())
    {
        throw std::runtime_error("Error: Invalid number '" + str + "'");
    }
    return result;
}

void RPN::executeOperation(std::string const& op)
{
    if (m_num_stack.size() < 2)
    {
        throw std::runtime_error("Error: Not enough operands for operator '" + op + "'" );
    }

    int second_number = m_num_stack.top(); m_num_stack.pop();
    int first_number = m_num_stack.top(); m_num_stack.pop();

    if (op == "/" && second_number == 0)
    {
        throw std::runtime_error("Error: Division by zero");
    }

    int result;
    if (op == "+")
        result = first_number + second_number;
    else if (op == "-")
        result = first_number - second_number;
    else if (op == "*")
        result = first_number * second_number;
    else if (op == "/")
        result = first_number / second_number;

    m_num_stack.push(result);
}

int RPN::rpnCalculate(std::string const& expression)
{
    while (!m_num_stack.empty())
    {
        m_num_stack.pop();
    }
    
    int op_count = 0;

    std::istringstream iss(expression);
    std::string token;
    while(iss >> token)
    {
        if (isOperator(token))
        {
            executeOperation(token);
            op_count++;
        }
            else if (isNum(token))
        {
            int num = strToInt(token);
            m_num_stack.push(num);
        }
        else
            throw std::runtime_error("Error: Invalid token '" + token + "'");
    }

    if (m_num_stack.empty())
        throw std::runtime_error("Error: No result (empty expression)");

    if (op_count == 0)
        throw std::runtime_error("Error: No operations performed");

    if (m_num_stack.size() > 1)
        throw std::runtime_error("Error: Too many operands");

    return m_num_stack.top();

}
