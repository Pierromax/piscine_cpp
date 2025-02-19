/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:41:50 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/17 16:41:50 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    (void)av;
    (void)ac;
    // if (ac != 2)
    // {
    //     std::cout << "Error: wrong number of arguments" << std::endl;
    //     return 1;
    // }
    //ScalarConverter::convert(av[1]);
    float f = 0.032f;

    std::cout << "f = " << f << "f" << std::endl;
    
    return 0;
}