/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:45:23 by ple-guya          #+#    #+#             */
/*   Updated: 2025/03/07 18:52:17 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <sstream>

class RPN
{
    private :
        std::vector<std::pair<std::string, float> > date_value;
        
    public :
        RPN();
        RPN(std::string const &filename);
        RPN(RPN const &original);
        RPN &operator=(RPN const &rhs);
        ~RPN();
        
        
};

#endif