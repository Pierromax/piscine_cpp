/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:45:26 by ple-guya          #+#    #+#             */
/*   Updated: 2025/03/10 13:16:17 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string const &arg)
{
    RPN::calculate(arg);
}

RPN::RPN(RPN const &cpy) : _stack(cpy._stack) {}

RPN &RPN::operator=(RPN const &rhs)
{
    if (&rhs != this)
        this->_stack = rhs._stack;
    return (*this);
        
}

RPN::~RPN(){}

bool    RPN::isValidNumber(std::string &token)
{
    std::istringstream iss(token);
    double value;

    iss >> value;
    if (iss.fail())
        return false;
    if (value >= 10 || value <= 0)
        throw (std::invalid_argument("invalid expression"));
    _stack.push(value);
    return true;
}

void RPN::makeOperation(std::string &op)
{
    if (op.size() > 1)
            throw (std::invalid_argument("invalid expression"));
    double right = _stack.top(); 
    _stack.pop();
    double left = _stack.top(); 
    _stack.pop();
    switch (op[0])
    {
        case '+':
            _stack.push(left + right);
            break;
        case '-':
            _stack.push(left - right);
            break;
        case '*':
            _stack.push(left * right);
            break;
        case '/':
            if (left == 0 || right == 0)
                throw (std::runtime_error("can't divide by 0"));
            _stack.push(left / right);
            break;
        default:
            throw(std::invalid_argument("invalid expression"));
    }
}

void RPN::calculate(std::string const &arg)
{
    if (arg.empty())
        throw (std::invalid_argument("invalid expression"));
    std::istringstream ss(arg);
    std::string token;

    while (ss >> token)
    {
        if (RPN::isValidNumber(token))
            continue;
        else if (_stack.size() < 2)
            throw (std::invalid_argument("invalid expression"));
        RPN::makeOperation(token);
    }
}

double RPN::getResult() const
{
    if (_stack.empty())
        throw (std::runtime_error("no expression called"));
    return (_stack.top());
}
