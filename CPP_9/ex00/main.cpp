/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:33:24 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/26 14:21:42 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void check_valid_file(std::string line)
{
    int pos = line.find('|');
    if (std::string::npos == pos)
        throw (std::exception());
}

int main(int ac, char **av)
{
    if (ac != 2)
        return(std::cout << "wrong number of argument" << std::endl, 1);
        
    std::ifstream infile(av[1]);

    if (!infile.is_open())
        return(std::cerr << "file don't exist or can't access" << std::endl, 1);
        
    std::string line;
    while (std::getline(infile, line))
    {
        try{
            check_valid_file(line);
        }
        catch (std::exception &e){
            std::cerr << line << ": invalide line in file" << std::endl; 
        }
    }
}