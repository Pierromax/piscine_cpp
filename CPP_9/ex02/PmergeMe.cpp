/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:45:26 by ple-guya          #+#    #+#             */
/*   Updated: 2025/07/14 15:51:04 by ple-guya         ###   ########.fr       */
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
size_t PmergeMe<Container>::binarySearchGroup(Container &main, int element)
{
    int left = 0;
    int right = main.size() / step;
    
    while (left < right) {
        int mid = (left + right) / 2;
        
        // Comparer avec le DERNIER élément du groupe mid
        int mid_element = main[mid * step + step - 1];
        
        if (mid_element < element) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    // Retourner la position en éléments (pas en groupes)
    return left * step;
}

template <class Container>
size_t PmergeMe<Container>::binarySearch(Container &main, int element)
{
    size_t left = 0;
    size_t right = main.size();
    
    while (left < right) 
    {
        size_t mid = (left + right) / 2;

        if (main[mid] < element) 
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

template <class Container>
void PmergeMe<Container>::insertion(Container& main, Container& pend)
{
  if (pend.empty()) return;
    
    std::cout << "=== INSERTION START ===" << std::endl;
    std::cout << "main.size() = " << main.size() << ", pend.size() = " << pend.size() << std::endl;
    std::cout << "step = " << step << std::endl;
    
    // Calculer le nombre de groupes
    int groups_in_pend = pend.size() / step;
    std::cout << "groups_in_pend = " << groups_in_pend << std::endl;
    
    // Tracker des groupes insérés
    std::vector<bool> inserted(groups_in_pend, false);
    
    // Phase 1: Insertion Jacobsthal
    int jacob_idx = 1;
    while (getJacob(jacob_idx) <= groups_in_pend) {
        
        int current_jacob = getJacob(jacob_idx);
        int previous_jacob = getJacob(jacob_idx - 1);
        
        std::cout << "Jacobsthal range: " << previous_jacob << " to " << current_jacob << std::endl;
        
        for (int group_idx = std::min(current_jacob - 1, groups_in_pend - 1); 
             group_idx >= previous_jacob; 
             group_idx--) {
             
            if (group_idx >= 0 && group_idx < groups_in_pend && !inserted[group_idx]) {
                
                std::cout << "Inserting group " << group_idx << std::endl;
                int compare_element = pend[group_idx * step + step - 1];
                size_t pos = binarySearchGroup(main, compare_element);
                for (int i = 0; i < step; i++)
                    main.insert(main.begin() + pos + i, pend[group_idx * step + i]);   
                inserted[group_idx] = true;
            }
        }
        
        jacob_idx++;
    }
    
    for (int group_idx = 0; group_idx < groups_in_pend; group_idx++) {
        if (!inserted[group_idx]) {
            std::cout << "Inserting remaining group " << group_idx << std::endl;
            
            int compare_element = pend[group_idx * step + step - 1];
            size_t pos = binarySearchGroup(main, compare_element);
            
            for (int i = 0; i < step; i++) {
                main.insert(main.begin() + pos + i, pend[group_idx * step + i]);
            }
            
            std::cout << "main.size() = " << main.size() << std::endl;
        }
    }
    
    // Phase 3: Éléments individuels restants
    int remaining_start = groups_in_pend * step;
    
    for (int i = remaining_start; i < static_cast<int>(pend.size()); i++) {
        int element = pend[i];
        size_t pos = binarySearchGroup(main, element);
        main.insert(main.begin() + pos, element);
        
        std::cout << "Inserted individual element " << element << std::endl;
    }
    
    std::cout << "main = ";    
    std::cout << "=== INSERTION END ===" << std::endl;
}

template <class Container>
void PmergeMe<Container>::initChain(Container &c, Container &main, Container &pend)
{
    typename Container::iterator it;
    unsigned long pair_len = step * 2;

    main.insert(main.end(), c.begin(), c.begin() + pair_len);

    for (it = c.begin() + pair_len; it + pair_len <= c.end(); it += pair_len)
    {
        pend.insert(pend.end(), it, it + step);
        main.insert(main.end(), it + step, it + pair_len);
    }
    if (it != c.end()) 
        pend.insert(pend.end(), it, c.end());
}

template <class Container>
void PmergeMe<Container>::makePair(Container &c)
{
    if (c.size() / (1 << level) < 2) 
        return;

    typename Container::iterator it;
    
    step = 1 << level;

    std::cout << "=========== FOR LEVEL " << level << "===========" << std::endl;

    std::cout << "before swap : ";
    printPair(c);
    for (it = c.begin() + step - 1; it + step + 1 < c.end(); it += step) 
    {
        if (*(it + step) < *it) 
            std::swap_ranges(it + 1 - step, it + 1, it + 1);
        it += step;
    }
    
    level++;
    std::cout << "ater swap : ";
    printPair(c);
    
    makePair(c);
}

template <class Container>
void PmergeMe<Container>::sort(Container &c)
{   
    makePair(c);

    Container main;
    Container pend;
    
    while (step >= 1)
    {
        main.clear();
        pend.clear();
        initChain(c, main, pend);                
        if (!pend.empty()) 
            insertion(main, pend);
        c = main;
        step /= 2;
    }
}
