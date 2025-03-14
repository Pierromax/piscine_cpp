/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:33:24 by ple-guya          #+#    #+#             */
/*   Updated: 2025/03/12 18:36:43 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return(std::cerr << "wrong number of argument" << std::endl, 1);

    std::string input(av[1]);
    
    try {
        BitcoinExchange btc;
        btc.run(input);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}