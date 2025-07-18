/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:45:29 by ple-guya          #+#    #+#             */
/*   Updated: 2025/07/18 20:46:18 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>

int main(int ac, char **av)
{
    if (ac < 2)
        return (std::cerr << "Usage : ./PmergeMe liste a trier" << std::endl, 1);

    try {

        typedef std::vector<int> VectorInt;
        typedef std::deque<int> DequeInt;
        
        PmergeMe<VectorInt> vec(&av[1]);
        PmergeMe<DequeInt> deq(&av[1]);
        
        std::clock_t vecClock = std::clock();
        
        vec.FordJohnson();
        vecClock = std::clock() - vecClock;
        
        std::clock_t deqClock = std::clock();
        deq.FordJohnson();
        deqClock = std::clock() - deqClock;
        
        std::cout << "before   : ";
        vec.printData();
        std::cout << "after : ";
        vec.printSorted();

        double vecTime = 1000.0 * vecClock / CLOCKS_PER_SEC;
        double deqTime = 1000.0 * deqClock / CLOCKS_PER_SEC;

        std::cout << std::fixed << std::setprecision(7);
        std::cout << "Time to process a range of " << ac - 1
                  << " elements with std::vector : " << vecTime << " ms" << std::endl;
                  
        std::cout << "Time to process a range of " << ac - 1
                  << " elements with std::deque : " << deqTime << " ms" << std::endl;
    }
    catch(std::exception &e){
        std::cerr << RED << e.what() << RESET << std::endl;
    }
}

