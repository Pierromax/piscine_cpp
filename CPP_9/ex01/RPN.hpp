/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:45:23 by ple-guya          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/09 22:19:27 by ple-guya         ###   ########.fr       */
=======
/*   Updated: 2025/03/10 13:12:14 by ple-guya         ###   ########.fr       */
>>>>>>> 3d9a2b060350a773ccc1fe5a738127227157bbcd
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