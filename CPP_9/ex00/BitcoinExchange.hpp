/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:33:58 by ple-guya          #+#    #+#             */
/*   Updated: 2025/03/07 17:42:43 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <sstream>

class BitcoinExchange
{
    private :
        std::vector<std::pair<std::string, float> > date_value;
        float       FindDB(time_t date);
        void        is_valid_param(std::string date, float value, std::string line, size_t pos);
        BitcoinExchange();

    public :
        BitcoinExchange(std::string const &filename);
        BitcoinExchange(BitcoinExchange const &original);
        BitcoinExchange &operator=(BitcoinExchange const &rhs);
        ~BitcoinExchange();
    
        void run();
};

#endif

