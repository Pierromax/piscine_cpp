/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:33:56 by ple-guya          #+#    #+#             */
/*   Updated: 2025/03/13 13:42:02 by ple-guya         ###   ########.fr       */
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

BitcoinExchange::BitcoinExchange() 
{
    BitcoinExchange::loadDataBase("data.csv");
}

BitcoinExchange::BitcoinExchange(std::string const &filename)
{
   BitcoinExchange::loadDataBase(filename);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy) : dataBase(cpy.dataBase) {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (&rhs != this)
        this->dataBase = rhs.dataBase;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/****************************/
/*     Member Functions     */
/****************************/

void    BitcoinExchange::loadDataBase(std::string const &filename)
{
    std::ifstream   db_file(filename.c_str());
    if (!db_file.is_open())
        throw (std::ifstream::failure("can't find database"));
    std::string     line;
    std::string     str_date;
    std::string     str_value;
    float           value;
    size_t          pos;
    time_t          date;
    std::tm         tm;
    bool            header = false;  
    
    std::getline(db_file, line);
    if (line == "date,exchange_rate")
        header = true;
    if (header == false)
        throw (std::invalid_argument("missing database Header"));
    while(std::getline(db_file, line))
    {
        pos = line.find(",");
        if (pos == std::string::npos)
            throw (std::invalid_argument("database not valid"));
        str_date = line.substr(0,pos);
        str_value = line.substr(pos+1);
        if (strptime(str_date.c_str(), "%Y-%m-%d", &tm) == NULL)
            throw (std::invalid_argument("database not valid"));
        date = mktime(&tm);
        std::istringstream(str_value) >> value;
        dataBase[date] = value;
    }
    db_file.close();
}

void    BitcoinExchange::run(std::string const &inputFile)
{
    std::ifstream   infile(inputFile.c_str());
    if (!infile.is_open())
        throw (std::ifstream::failure("input file: can't find or don't exist"));
    std::string     str_date;
    std::string     line;
    std::string     str_value;
    size_t          pos;
    float           value;
    time_t          date;
    float           rate;
    bool            header = false;  

    std::getline(infile, line);
    if (line == "date | value")
        header = true;
    if (header == false)
        throw (std::invalid_argument("missing input file Header"));
    else
        std::cout << line << std::endl;
    while (std::getline(infile, line))
    {
        if (is_empty_line(line))
            continue;
        pos = line.find("|");
        std::tm tm = {};
        str_date = line.substr(0, pos);
        if (pos != std::string::npos && strptime(str_date.c_str(), "%Y-%m-%d", &tm) != NULL)
        {
            str_value = line.substr(pos + 1);
            date = mktime(&tm);
            try {
                is_valid_value(&value, str_value);
                rate = BitcoinExchange::FindDB(date);
                std::cout << str_date << " => " << value << " = " << value * rate << std::endl;
            } catch(std::exception &e) {
                std::cout << e.what() << std::endl;
            }
        }
        else
            std::cout << "Error: bad input => " << line << std::endl;
    }
}

float   BitcoinExchange::FindDB(time_t date)
{
    std::map<time_t, float>::iterator it = dataBase.begin();
    float  closest_rate = 0;
    
    for (; it != dataBase.end(); it++)
    {
        if (it->first == date)
            return (it->second);
        if (it->first > date)
            return (closest_rate);
        closest_rate = it->second;
    }
    throw std::runtime_error("Error: no valid exchange rate found in database");
}

void    BitcoinExchange::is_valid_value(float *value, std::string str_value)
{
    std::istringstream ss(str_value);
        
    if (!(ss >> *value))
        throw std::invalid_argument("Error => not a number");
    if (*value < 0)
        throw std::invalid_argument("Error => not a positive number.");
    if (*value > 1000)
        throw std::invalid_argument("Error => too large a number.");
}
