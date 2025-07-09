/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:45:29 by ple-guya          #+#    #+#             */
/*   Updated: 2025/07/08 16:06:13 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (std::cerr << "Usage : ./PmergeMe liste a trier" << std::endl, 1);

    try {

        typedef std::vector<int> VectorInt;
        //typedef std::deque<int> DequeInt;
        
        PmergeMe<VectorInt> vec(&av[1]);
        vec.FordJohnson();

        std::cout << "data ";
        vec.printData();
        std::cout << "sorted ";
        vec.printSorted();
        
    }
    catch(std::exception &e){
        std::cerr << RED << e.what() << RESET << std::endl;
    }
}

