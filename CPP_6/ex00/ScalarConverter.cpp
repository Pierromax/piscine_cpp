/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:46:09 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/17 16:46:09 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

ScalarConverter::~ScalarConverter() {}

static void printspecialcase(std::string const str)
{
    std::string DoubleStr[3] = {"+inf", "-inf", "nan"};
    std::string FloatStr[3] = {"+inff", "-inff", "nanf"};
    int i = 0;

    while (str != DoubleStr[i] && str != FloatStr[i])
        i++;
    std::cout << "char: impossible" << std::endl 
            << "int: impossible" << std::endl 
            << "float: " << FloatStr[i] << std::endl 
            << "double: " << DoubleStr[i] << std::endl;
}

static int is_valid_parameter(std::string const str)
{
    int len = str.length();
    int i;

    if (len == 0)
        return (0);
    if (len == 1)
        return (1);
    i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    while (str[i] && std::isdigit(str[i]))
        i++;
    if (i == len)
        return (1);
    if (str[i] == '.')
        i++;
    while (str[i] && std::isdigit(str[i]))
        i++;
    if (i == len || (i = len - 1 && str[i] == 'f'))
        return (1);
    return 0;
}

static int convert_from_string(std::string str, int *ivalue, float *fvalue, double *dvalue)
{
    std::stringstream ss(str);

    ss >> *ivalue;
    ss.clear();
    ss.seekg(0);
    ss >> *fvalue;
    ss.clear();
    ss.seekg(0);
    ss >> *dvalue;
    size_t pos = str.find('f');
    if (pos != std::string::npos)
        str.erase(pos);
    pos = str.find(".");
    if (pos != std::string::npos)
    {
        int i = 0;
        str = &str[pos + 1];
        int len = str.length();
        while (str[i] && str[i] == '0')
            i++;
        if (i != len)
            return (len);
    }
    return 1;
}

static void print_parameter(std::string str)
{
    std::stringstream sslong(str);
    char    c;
    int     intValue;
    long    lvalue;
    float   floatValue;
    double  doubleValue;
    int     precision = 1;
    bool    overflow = false;

    if (str.length() == 1 && !std::isdigit(str[0]))
    {
        intValue = static_cast<int>(str[0]);
        floatValue = static_cast<float>(str[0]);
        doubleValue = static_cast<double>(str[0]);
    }
    else
        precision = convert_from_string(str, &intValue, &floatValue, &doubleValue);
    sslong >> lvalue;
    c = static_cast<char>(intValue);
    overflow = (lvalue > CHAR_MAX || lvalue < CHAR_MIN) ? true : false;
    if (std::isprint(c) && overflow == false)
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: non displayable" << std::endl;
    overflow = (lvalue > INT_MAX || lvalue < INT_MIN) ? true : false;
    if (overflow)
        std::cout << "int: overflow" << std::endl;
    else
        std::cout << "int: "<< intValue << std::endl;  
    overflow = (doubleValue > FLT_MAX || doubleValue < FLT_MIN) ? true : false;
    std::cout << std::fixed << std::setprecision(precision);
    if (overflow)
        std::cout << "float: overflow" << std::endl;
    else
        std::cout << "float: " << floatValue << "f" << std::endl;
    std::cout << "double: " << doubleValue << std::endl;
}

void ScalarConverter::convert(std::string const &str)
{
    if (str == "nan" || str == "nanf" || str == "+inf" 
        || str == "-inf" || str == "+inff" || str == "-inff")
        return (printspecialcase(str));
    if (is_valid_parameter(str))
        print_parameter(str);
    else
        std::cout << IMPOSSIBLE << std::endl;
}
