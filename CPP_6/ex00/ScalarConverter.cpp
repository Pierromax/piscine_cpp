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

void ScalarConverter::convert(std::string const &str)
{
    try
    {
        char c = static_cast<char>(std::stoi(str));
        std::cout << "char: " << c << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "char: impossible" << std::endl;
    }
    try
    {
        int i = static_cast<int>(std::stoi(str));
        std::cout << "int: " << i << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "int: impossible" << std::endl;
    }
    try
    {
        float f = static_cast<float>(std::stof(str));
        std::cout << "float: " << f << ".0f" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "float: impossible" << std::endl;
    }
    try
    {
        double d = static_cast<double>(std::stod(str));
        std::cout << "double: " << d << ".0" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "double: impossible" << std::endl;
    }
}