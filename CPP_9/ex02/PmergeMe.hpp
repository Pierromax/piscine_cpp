/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:45:23 by ple-guya          #+#    #+#             */
/*   Updated: 2025/07/15 15:58:57 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <cmath>

#define RED     "\033[31m"
#define RESET   "\033[0m"

template <class Container>
class PmergeMe
{
    private :
        Container data;
        Container sorted;
        int       level;

        void      sort();
        void      insertion(Container &main, Container &pend, int step);
        void      initChain(Container &main, Container &pend, int step);
        void      makePair(int step);
        int       getJacob(int index);

    public :
        PmergeMe();
        PmergeMe(char **liste);
        PmergeMe(PmergeMe const &original);
        PmergeMe &operator=(PmergeMe const &rhs);
        ~PmergeMe();

        void      printPair(Container &c, int step);
        void      printData();
        void      printSorted();
        void      FordJohnson();
};

#include "PmergeMe.cpp"

#endif