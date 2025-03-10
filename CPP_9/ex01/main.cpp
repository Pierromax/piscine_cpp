/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:45:29 by ple-guya          #+#    #+#             */
/*   Updated: 2025/03/10 13:13:57 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "Usage : ./RPN 'expression'" << std::endl, 1);

    std::string const arg(av[1]);
    
    try {
        RPN rpn(arg);
        std::cout << rpn.getResult() << std::endl;
    }
    catch(std::exception &e){
        std::cerr << e.what()<< std::endl;
    } 
}