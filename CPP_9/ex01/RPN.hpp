/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:45:23 by ple-guya          #+#    #+#             */
/*   Updated: 2025/03/10 13:12:14 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <ctime>
#include <sstream>

class RPN
{
    private :
        std::stack<double> _stack;
        bool isValidNumber(std::string &nb);
        void makeOperation(std::string &op);
        
    public :
        RPN();
        RPN(std::string const &arg);
        RPN(RPN const &original);
        RPN &operator=(RPN const &rhs);
        ~RPN();
        
        double getResult() const;
        void calculate(std::string const &arg);
};

#endif