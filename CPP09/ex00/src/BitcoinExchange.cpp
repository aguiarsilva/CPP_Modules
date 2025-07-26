/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:52:11 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/26 10:03:46 by baguiar-         ###   ########.fr       */
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

    int year = std::atoi(year_str.c_str());
    int month = std::atoi(month_str.c_str());
    int day = std::atoi(day_str.c_str());

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

double BitcoinExchange::getExchangeRate(const std::string& date)
{
    std::map<std::string, double>::iterator it = m_bitcoin_prices.lower_bound(date);

}
