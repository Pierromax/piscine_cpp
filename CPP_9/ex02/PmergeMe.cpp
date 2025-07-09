/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:45:26 by ple-guya          #+#    #+#             */
/*   Updated: 2025/07/09 18:15:53 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp" 

template <class Container>
PmergeMe<Container>::PmergeMe() {}

template <class Container>
PmergeMe<Container>::PmergeMe(char **liste) : level(0), step(0)
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
void PmergeMe<Container>::printSorted()
{
     for (unsigned long i = 0; i < sorted.size(); i++)
    {
        std::cout << sorted[i] << " ";
    }
    std::cout << std::endl;
}

template <class Container>
void PmergeMe<Container>::printPair(Container &c)
{
    unsigned long pair_len = step * 2;
    unsigned long paired_elements = c.size() / pair_len * pair_len;
    bool pending = false;
    
    for (unsigned long i = 0; i < c.size(); i++)
    {
        if (i == paired_elements && !pending)
        {
            pending = true;
            std::cout << " pending : ";
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
void PmergeMe<Container>::FordJohnson()
{
    if (data.size() <= 1)
        throw(std::invalid_argument("invalid sequence"));
        
    if (data.end() == std::adjacent_find(data.begin(), data.end(), std::greater<int>()))
        throw(std::invalid_argument("list already sorted"));
    sorted = data;
    sort(sorted);
}

template <class Container>
size_t PmergeMe<Container>::binarySearch(Container &main, int element)
{
    size_t left = 0;
    size_t right = main.size();
    
    while (left < right) {
        size_t mid = (left + right) / 2;
        if (main[mid] < element) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

template <class Container>
void PmergeMe<Container>::insertion(Container& c, Container& main, Container& pend)
{
    int jacob_idx = 1;
    while (getJacob(jacob_idx) <= static_cast<int>(pend.size())) 
    {
        int idx = getJacob(jacob_idx) - 1;
        if (idx >= 0 && idx < (int)pend.size()) 
        {
            int element = pend[idx];
            size_t pos = binarySearch(main, element);
            main.insert(main.begin() + pos, element);
        }
        jacob_idx++;
    }
    std::copy(main.begin(), main.end(), c.begin());
}

template <class Container>
void PmergeMe<Container>::initChain(Container &c, Container &main, Container &pend)
{
    typename   Container::iterator c_it, pend_it, main_it;
    
	std::copy(c.begin(), c.begin() + 2 * step, main.begin());
	c_it = c.begin() + 2 * step;
	main_it = main.begin() + 2 * step;
	pend_it = pend.begin();
	while (c_it != c.end()) 
    {
		if (c_it + step > c.end())
			break ;
		std::copy(c_it, c_it + step, main_it);
		main_it += step;
		c_it += step;
		if (c_it + step > c.end())
			break ;
		std::copy(c_it, c_it + step, main_it);
		main_it += step;
		c_it += step;
	}
}

template <class Container>
void PmergeMe<Container>::makePair(Container &c)
{
    typename Container::iterator it;
    
    if (c.size() / (1 << level) < 2)
        return;
        
    step = 1 << level;
        
    std::cout << "====== FOR RECURSION LEVEL " << level << " ======" << std::endl;
    std::cout << "before swap :: " ;
    printPair(c);
    
    for (it = c.begin() + step - 1; it + step < c.end(); it += step * 2) 
    {
        if (*(it + step) < *it) 
            std::swap_ranges(it + 1 - step, it + 1, it + 1);
    }
    
    std::cout << "after swap :: " ;
    printPair(c);
    
    level++;
    makePair(c);
}

template <class Container>
void PmergeMe<Container>::sort(Container &c)
{   
    std::cout << "====== SWAP TIME ======" << std::endl;
    makePair(c);

    std::cout << "====== INITIALIZATION TIME ======" << std::endl;

    unsigned int main_len = step * 2;
    unsigned int pend_len = c.size() - main_len;
    
    Container main(c.size());
    Container pend(c.end() - pend_len, c.end());
    
    initChain(c, main, pend);
    
    std::cout << "====== INSERTION TIME ======" << std::endl;
    
    if (pend.size() > 0) {
        insertion(c, main, pend);
    } else {
        std::copy(main.begin(), main.end(), c.begin());
    }
    sorted = c;
    
    std::cout << "====== END ======" << std::endl;
    return;
}

