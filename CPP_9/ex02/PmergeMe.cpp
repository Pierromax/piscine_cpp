/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:45:26 by ple-guya          #+#    #+#             */
/*   Updated: 2025/07/18 20:24:36 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp" 

template <class Container>
PmergeMe<Container>::PmergeMe() {}

template <class Container>
PmergeMe<Container>::PmergeMe(char **liste) : level(0)
{
    for (size_t i = 0; liste[i] ; i++)
    {
        std::string str(liste[i]);
        int value;
        std::istringstream iss(str);
        if (!(iss >> value) || !(iss.eof()))
            throw std::invalid_argument("Invalid number");
        data.push_back(value);
    }
}

template <class Container>
PmergeMe<Container>::PmergeMe(PmergeMe const &cpy) : data(cpy.data) {}

template <class Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(PmergeMe<Container> const &rhs)
{
    if (this != &rhs)
        data = rhs.data;
    return (*this);
}

template <class Container>
PmergeMe<Container>::~PmergeMe(){}

template <class Container>
void PmergeMe<Container>::printData()
{
     for (unsigned long i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template <class Container>
Container PmergeMe<Container>::getData()
{
    return (data);
}

template <class Container>
void PmergeMe<Container>::printSorted()
{
     for (unsigned long i = 0; i < sorted.size(); i++)
    {
        std::cout << sorted[i] << " ";
    }
    std::cout << std::endl;
}

template <class Container>
void PmergeMe<Container>::printPair(Container &c, int step)
{
    // unsigned long pair_len = step * 2;
    unsigned long paired_elements = c.size() / step * step;
    bool pending = false;
    
    for (unsigned long i = 0; i < c.size(); i++)
    {
        if (i >= paired_elements && !pending)
        {
            pending = true;
            std::cout << " odd element : ";
        }
        if (i % step == 0 && !pending)
            std::cout << " [" ;
        std::cout << c[i];
        if ((i % step != step - 1 && i != c.size() - 1) || pending)
            std::cout << " "; 
        if ((i % step == step - 1 || i == c.size() - 1) && !pending)
            std::cout << "]";
    }
    std::cout << std::endl;
}


template <class Container>
int PmergeMe<Container>::getJacob(int index)
{
    static const int jacobsthal[32] = { 0, 1, 3, 5, 11, 21, 43, 85, 171, 341,
        683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 
		699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243,
		89478485, 178956971, 357913941, 715827883, 1431655765};

    return  jacobsthal[index];
}

template <class Container>
void PmergeMe<Container>::makePair(int step)
{
    typename Container::iterator it;

    for (it = sorted.begin() + step - 1; it + step < sorted.end(); it += step * 2) 
    {
        if (*(it + step) < *it) 
            std::swap_ranges(it + 1 - step, it + 1, it + 1);
    }
    level++;
}

template <class Container>
void PmergeMe<Container>::initChain(Container &main, Container &pend, int step)
{
	typename Container::iterator	res_it, pend_it, sorted_it;
	typename Container::iterator	d_lim, h_lim, pos; 

	std::copy(sorted.begin(), sorted.begin() + 2 * step, main.begin());
	sorted_it = sorted.begin() + 2 * step;
	res_it = main.begin() + 2 * step;
	pend_it = pend.begin();
	while (sorted_it != sorted.end()) 
    {
		if (sorted_it + step > sorted.end())
			break ;
		std::copy(sorted_it, sorted_it + step, pend_it);
		pend_it += step;
		sorted_it += step;
		if (sorted_it + step > sorted.end())
			break ;
		std::copy(sorted_it, sorted_it + step, res_it);
		res_it += step;
		sorted_it += step;
	}
    pend.insert(pend_it, sorted_it, sorted.end());
    main.resize(main.size() - pend.size());
}

template <class Container>
int PmergeMe<Container>::binarySearch(Container &main, int value, int step)
{
    int left = 0;
    int right = main.size() / step;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        int midValue = *(main.begin() + (mid + 1) * step - 1);
        if (midValue < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left * step;
}

template <class Container>
void PmergeMe<Container>::insertion(Container &main, Container &pend, int step)
{
    typename Container::iterator    pos, insert_it;
    int                             idx, pendGroup;

    pendGroup = pend.size() / step;
    
    std::vector<bool> inserted(pendGroup, false);

    idx = 1;
    while (pendGroup >= getJacob(idx))
    {
        int start = getJacob(idx - 1);
        int end = getJacob(idx);
        for (int i = end ; i >= start; i--)
        {
            if (i < pendGroup && !inserted[i])
            {
                insert_it = pend.begin() + (i + 1) * step - 1;
                pos = main.begin() + binarySearch(main, *insert_it, step);
                main.insert(pos, insert_it - step + 1, insert_it + 1);
                inserted[i] = true;
            }
        }
        idx++;
    }
    for (int i = pendGroup - 1; i >= 0; --i) 
    {
        if (!inserted[i])
        {
            insert_it = pend.begin() + (i + 1) * step - 1;
            pos = main.begin() + binarySearch(main, *insert_it, step);
            main.insert(pos, insert_it - step + 1, insert_it + 1);
            inserted[i] = true;
        }
    }
    int rest = pend.size() % step;
    if (rest != 0)
        main.insert(main.end(), pend.end() - rest, pend.end());
}

template <class Container>
void PmergeMe<Container>::sort()
{   
    if (sorted.size() / (1 << level) < 2) 
        return;

    int step = 1 << level;
    
    makePair(step);

    sort();
    		
	int						res_len = step * (std::floor((sorted.size()/ (2.0 * step)) - 1) + 2);
	Container				main(sorted.size());
    Container               pend(((sorted.size() - res_len) / step) * step);

    if (pend.size() == 0)
        return;

    initChain(main, pend, step);
    insertion(main, pend, step);
    
    this->sorted = main;

	return ;
}

template <class Container>
void PmergeMe<Container>::FordJohnson()
{
    if (data.size() <= 1)
        throw(std::invalid_argument("invalid sequence"));
        
    if (data.end() == std::adjacent_find(data.begin(), data.end(), std::greater<int>()))
        throw(std::invalid_argument("list already sorted"));
        
    sorted = data;
    
    sort();
}
