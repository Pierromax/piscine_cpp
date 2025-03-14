/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:45:23 by ple-guya          #+#    #+#             */
/*   Updated: 2025/03/09 22:19:27 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
    private :
        std::stack<double> _stack;
        std::string _calculation[];
        void calculate(std::string const &calculation);
        
    public :
        RPN();
        RPN(std::string const &arg);
        RPN(RPN const &original);
        RPN &operator=(RPN const &rhs);
        ~RPN();

        void print_result();
};

#endif