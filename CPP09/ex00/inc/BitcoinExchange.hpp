/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:28:29 by baguiar-          #+#    #+#             */
/*   Updated: 2025/07/27 10:09:40 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>

class BitcoinExchange
{
    private:
        std::map<std::string, double> m_bitcoin_prices;

        //Methods used in the program and the user won't access it
        void loadDatabase(const std::string& db_filename);
        bool validateDate(const std::string& date);
        bool isLeapYear(int year);
        bool getExchangeRate(const std::string& date, double& rate);
        std::string trim(const std::string& str);
    
    public:
        //Orthodox Canonical Form
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        //Method called by users
        void processInputFile(const std::string& input_filename);

};

#endif
