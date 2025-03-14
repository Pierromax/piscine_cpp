/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:45:26 by ple-guya          #+#    #+#             */
/*   Updated: 2025/03/09 22:25:09 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#Incllude "RPN.hpp"

RPN::RPN() : _stack(), _calculation()
{
}

RPn::RPN(std::string const &arg) : _stack(), _calculation()
{
    std::string calculation = arg.split(' ');
    for (std::string::iterator it = calculation.begin(); it != calculation.end(); it++)
    {
        if (isdigit(*it))
            _stack.push(*it);
        else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
            _calculation.push_back(*it);
        else
            throw std::invalid_argument("Invalid character in expression");
    }
}

RPN::~RPN()
{
}

RPN::RPN(RPN const &original) : _stack(original._stack), _calculation(original._calculation)
{
}

RPN &RPN::operator=(RPN const &rhs)
{
    if (this != &rhs)
    {
        _stack = rhs._stack;
        _calculation = rhs._calculation;
    }
    return *this;
}



