/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:52:11 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/27 10:48:02 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : m_bitcoin_prices(other.m_bitcoin_prices)
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        this->m_bitcoin_prices = other.m_bitcoin_prices;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& db_filename)
{
    std::ifstream file(db_filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: File not opened!" << std::endl;
        return ;
    }

    std::string line;
    bool first_line = true;
    while (std::getline(file, line))
    {
        if (first_line)
        {
            first_line = false;
            continue;
        }

        std::stringstream ss(line);
        std::string date, price_str;

        if (std::getline(ss, date, ',') && std::getline(ss, price_str))
        {
            std::stringstream price_stream(price_str);
            double price;

            if (price_stream >> price)
            {
                if (validateDate(date))
                {
                    m_bitcoin_prices[date] = price;
                }
                else
                    std::cerr << "Error: invalid date in database: " << date << std::endl;
            }
            else
            {
                std::cerr << "Error: invalid price format in database" << std::endl;
            }
        }
        else
            std::cerr << "Error: invalid line format in database" << std::endl;
    }

    file.close();
}

bool BitcoinExchange::validateDate(const std::string& date)
{
    if (date.length() != 10)
        return false;
    
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    for (int i = 0; i < 10; i++)
    {
        if (i != 4 && i != 7)
        {
            if (!isdigit(date[i]))
                    return false;
        }
    }

    //Extract and validate the ranges of the date
    std::string year_str = date.substr(0, 4);
    std::string month_str = date.substr(5, 2);
    std::string day_str = date.substr(8, 2);

    std::stringstream year_stream(year_str);
    std::stringstream month_stream(month_str);
    std::stringstream day_stream(day_str);

    int year, month, day;
    if (!(year_stream >> year) || !(month_stream >> month) || !(day_stream >> day))
    {
        return false;
    }

    //Validate the range
    if (month < 1 || month > 12)
        return false;

    if (day < 1 || day > 31)
        return false;

    if (year < 1900 || year > 2040)
        return false;
    
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return false;
    }
    else if (month == 2)
    {
        int maxDays = isLeapYear(year) ? 29 : 28;
        if (day > maxDays)
            return false;
    }
    
    return true;
}

bool BitcoinExchange::isLeapYear(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

bool BitcoinExchange::getExchangeRate(const std::string& date, double& rate)
{
    //find exact match
    std::map<std::string, double>::iterator it = m_bitcoin_prices.find(date);
    if (it != m_bitcoin_prices.end())
    {
        rate = it->second;
        return true;
    }
    //if no exact match, go to closest lower date
    it = m_bitcoin_prices.lower_bound(date);

   //target is before database - error
    if (it == m_bitcoin_prices.begin())
    {
        return false;
    }

    --it;
    rate = it->second;
    return true;
}

void BitcoinExchange::processInputFile(const std::string& input_filename)
{
    loadDatabase("data.csv");
    
    std::ifstream file(input_filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file" << std::endl;
        return ;
    }

    std::string line;
    
    while (std::getline(file, line))
    {
        if (line == "date | value")
        {
            continue;
        }

        std::stringstream ss(line);
        std::string date_part, value_part;

        if (std::getline(ss, date_part, '|') && std::getline(ss, value_part))
        {
            std::string target_date = trim(date_part);
            std::string value_str = trim(value_part);

            if (!validateDate(target_date))
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue ;
            }
            
            std::stringstream value_stream(value_str);
            double input_value;

            if (value_stream >> input_value)
            {
                //std::cout << "DEBUG: Parsed value = " << input_value << std::endl;

                if (input_value < 0)
                {
                    std::cerr << "Error: not a positive number." << std::endl;
                    continue;
                }

                if (input_value > 1000)
                {
                    std::cerr << "Error: too large a number." << std::endl;
                    continue;
                }
                
                double rate;
                if (getExchangeRate(target_date, rate))
                {
                    double result = input_value * rate;
                    std::cout << target_date << " => " << input_value << " = " << result << std::endl;
                }
                else
                {
                    std::cerr << "Error: date too early for database" << std::endl;
                }
            }
            else
            {
                std::cerr << "Error: bad input => " << line << std::endl;
            }
        }
        else
        {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
    file.close();
}

std::string BitcoinExchange::trim(const std::string& str)
{
    size_t begin = str.find_first_not_of(" \t");
    if (begin == std::string::npos)
        return "";

    size_t end = str.find_last_not_of(" \t");
    return str.substr(begin, end - begin + 1);
}
