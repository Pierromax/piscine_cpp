/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:33:24 by ple-guya          #+#    #+#             */
/*   Updated: 2025/03/07 17:50:06 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return(std::cerr << "wrong number of argument" << std::endl, 1);

    std::string input(av[1]);
    
    try {
        BitcoinExchange btc(input);
        btc.run();
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}