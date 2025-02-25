/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:59:50 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/24 17:00:41 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <exception>

int main()
{
    std::vector<int> vec;

    std::cout << std::string (25, '*') << std::endl << std::string(5, ' ') << "vector container" 
            << std::endl << std::string (25, '*') << std::endl;
             
    for (int i = 1; i <= 9; i++)
        vec.push_back(i);
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    try { 
        std::cout << easyfind(vec, 9) << std::endl;
        easyfind(vec, 40);
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::list<int> lst;

    std::cout << std::endl << std::string (25, '*') << std::endl << std::string(5, ' ') << "list container" 
            << std::endl << std::string (25, '*') << std::endl;
    for (int i = 1; i <= 9; i++)
        lst.push_back(i);
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    try { 
        std::cout << easyfind(lst, 9) << std::endl;
        easyfind(lst, 40);
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::deque<int> deq;

    std::cout << std::endl << std::string (25, '*') << std::endl << std::string(5, ' ') << "deque container" 
            << std::endl << std::string (25, '*') << std::endl;
    for (int i = 1; i <= 9; i++)
        deq.push_back(i);
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    try { 
        std::cout << easyfind(deq, 9) << std::endl;
        easyfind(deq, 40);
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}