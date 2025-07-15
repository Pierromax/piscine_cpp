/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:45:26 by ple-guya          #+#    #+#             */
/*   Updated: 2025/07/15 18:02:13 by ple-guya         ###   ########.fr       */
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

    std::cout << "=========== FOR LEVEL " << level << "===========" << std::endl;

    std::cout << "before swap : ";
    printPair(sorted, step);
    for (it = sorted.begin() + step - 1; it + step < sorted.end(); it += step * 2) 
    {
        if (*(it + step) < *it) 
            std::swap_ranges(it + 1 - step, it + 1, it + 1);
    }
    level++;
    std::cout << "ater swap : ";
    printPair(sorted, step);
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
    main.resize(main.size() - pend.size());
}

template <class Container>
void PmergeMe<Container>::insertion(Container &main, Container &pend, int step)
{
    // typename Container::iterator    main_it, pend_it, pos;
    // int                             jacob_idx = 1, pendGroup = pend.size() / step;
    // std::vector<bool>               inserted(pendGroup, false);
    // int							    res_len = step * (std::floor((sorted.size()/ (2.0 * step)) - 1) + 2);
    
    // main_it = main.begin();
    // pend_it = pend.begin();
    int pendGroup = pend.size() / step;
    std::vector<bool> inserted(pendGroup, false);

    int jacob_idx = 1;
    while (getJacob(jacob_idx) <= pendGroup) {
        int current_jacob = getJacob(jacob_idx);
        int previous_jacob = getJacob(jacob_idx - 1);

        for (int i = std::min(current_jacob - 1, pendGroup - 1); i >= previous_jacob; i--) {
            if (!inserted[i]) 
            {
                Container mainGroupLasts;
                int mainGroupCount = main.size() / step;
                for (int g = 0; g < mainGroupCount; ++g)
                    mainGroupLasts.push_back(*(main.begin() + (g + 1) * step - 1));
                typename Container::value_type value = *(pend.begin() + i * step + step - 1);
                typename Container::iterator groupPos = std::lower_bound(mainGroupLasts.begin(), mainGroupLasts.end(), value);
                int insertIdx = std::distance(mainGroupLasts.begin(), groupPos);
                typename Container::iterator insert_pos = main.begin() + insertIdx * step;
                main.insert(insert_pos, pend.begin() + i * step, pend.begin() + (i + 1) * step);
                inserted[i] = true;
            }
        }
        jacob_idx++;
    }

    for (int i = pendGroup - 1; i >= 0; i--) {
        if (!inserted[i]) {
            std::vector<typename Container::value_type> mainGroupLasts;
            int mainGroupCount = main.size() / step;
            for (int g = 0; g < mainGroupCount; ++g)
                mainGroupLasts.push_back(*(main.begin() + (g + 1) * step - 1));

             typename Container::value_type value = *(pend.begin() + i * step + step - 1);
            typename Container::iterator groupPos = std::lower_bound(mainGroupLasts.begin(), mainGroupLasts.end(), value);

            int insertIdx = std::distance(mainGroupLasts.begin(), groupPos);
            typename Container::iterator insert_pos = main.begin() + insertIdx * step;

            main.insert(insert_pos, pend.begin() + i * step, pend.begin() + (i + 1) * step);
        }
    }

    // Insérer les éléments restants (non groupés)
    int rest = pend.size() % step;
    if (rest) {
        typename Container::iterator it = pend.end() - rest;
        for (; it != pend.end(); ++it) {
            typename Container::iterator pos = std::lower_bound(main.begin(), main.end(), *it);
            main.insert(pos, *it);
        }
    }
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
    std::cout << "=========== INSERTION PART ===========" << std::endl << "---- for step " << step << "----" << std::endl;
    std::cout << "--- before insertion -----" << std::endl;
    std::cout << "main : ";
    printPair(main, step);
    std::cout << "pend : ";
    printPair(pend, step);

    insertion(main, pend, step);

    std::cout << "--- after insertion -----" << std::endl;
    std::cout << "main : ";
    printPair(main, step);

    sorted = main;

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
