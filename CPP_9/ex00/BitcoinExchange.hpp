/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:33:58 by ple-guya          #+#    #+#             */
/*   Updated: 2025/03/12 18:31:42 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <sstream>

class BitcoinExchange
{
    private :
        std::map<time_t, float> dataBase;
        float       FindDB(time_t date);
        void        is_valid_value(float value);
        void        loadDataBase(std::string const &filename);
        
    public :
        BitcoinExchange();
        BitcoinExchange(std::string const &filename);
        BitcoinExchange(BitcoinExchange const &original);
        BitcoinExchange &operator=(BitcoinExchange const &rhs);
        ~BitcoinExchange();

        void run(std::string const &inputFile);
};

#endif

