/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:33:56 by ple-guya          #+#    #+#             */
/*   Updated: 2025/03/07 18:30:19 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool is_empty_line(std::string line)
{
    for (size_t i = 0; line[i]; i++)
    {
        if (!std::isspace(line[i]))
            return false;
    }
    return (true);
}

/****************************/
/* Constructor & Destructor */
/****************************/

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string const &filename)
{
    std::ifstream infile(filename.c_str());
    std::string line;
    std::string date;
    float value;

    if (!infile.is_open())
        throw (std::ifstream::failure("Could not open file"));
    while (std::getline(infile, line))
    {
        if (line == "date | value")
        {
            date = line, value = -1;
            continue;
        }
        size_t pos = line.find("|");
        if (is_empty_line(line))
            continue;
        date = line.substr(0, pos);
        std::string str_value = line.substr(pos + 1);
        std::stringstream(str_value) >> value;
        try {
            is_valid_param(date, value, line, pos);
        } catch (std::exception &e) {
            date = e.what(), value = -1;
        }
        date_value.push_back(std::pair<std::string, float>(date, value));
    }
    infile.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy) : date_value(cpy.date_value) {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (&rhs != this)
        this->date_value = rhs.date_value;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/****************************/
/*     Member Functions     */
/****************************/

void BitcoinExchange::run()
{
    std::vector<std::pair<std::string, float> >::iterator it = date_value.begin();
    std::tm input = {};
    for (;it != date_value.end(); it++)
    {
        
        if (it->second == -1)
            std::cout << it->first << std::endl;
        else if (strptime(it->first.c_str(), "%Y-%m-%d", &input) != NULL)
        {
            time_t date = mktime(&input);
            try {
                float rate = FindDB(date);
                std::cout << it->first << " => " << it->second << " = " << it->second * rate << std::endl;
            } catch (std::exception &e){
                throw(e);
            }
        }
    }
}

float  BitcoinExchange::FindDB(time_t date)
{
    std::ifstream db_file("data.csv");
    if (!db_file.is_open())
        throw (std::ifstream::failure("can't find database"));
    std::string line;
    float rate;
    float closest_rate = 0;
    time_t db_time;

    while(std::getline(db_file, line))
    {
        size_t pos = line.find(",");
        std::string db_date = line.substr(0, pos);
        std::string str_rate = line.substr(pos + 1);
        std::tm  db_tm = {};
        if (strptime(db_date.c_str(), "%Y-%m-%d", &db_tm) != NULL)
        {
            db_time = mktime(&db_tm);
            std::stringstream (str_rate) >> rate;
            if (db_time == date)
                return (db_file.close(), rate);
            if (db_time > date)
            {
                std::cout << closest_rate << std::endl;
                return (db_file.close(),  closest_rate);
            }
            closest_rate = rate;
        } 
    }
    db_file.close();
    throw std::invalid_argument("Error: no valid exchange rate found in database");
}

void BitcoinExchange::is_valid_param(std::string date, float value, std::string line, size_t pos)
{
    if (std::string::npos == pos)
        throw(std::invalid_argument("Error: bad input => " + line));
    if (value < 0)
        throw (std::out_of_range("Error: not a positive number"));
    if (value > 1000)
        throw (std::out_of_range("Error: number too large"));
    std::tm tm;
    if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL)
        throw(std::invalid_argument("Error: bad input => " + line));
}
