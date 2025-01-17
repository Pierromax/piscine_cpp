/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:54:13 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/07 21:16:31 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void clear_screen(phonebook *book, std::string prompt)
{
	std::cout << "\033[2J\033[1;1H";
	printbook(book);
	std::cout << prompt << std::endl;
}

int	main() 
{
	std::string input;
	phonebook	book;
	int	index = 0;

	printbook(&book);
	while (1)
	{
		std::cin >> input;
		if (std::cin.good() == false)
			break ;
		if (input == "EXIT" || input == "exit")
			break ;
		else if (input == "ADD" || input == "add")
			add_function(&book, index++);
		else if (input == "SEARCH" || input == "search")
			search_function(&book);
		else
				clear_screen(&book, "command dont exist please use ADD, SEARCH or EXIT");
		index = index % 8;
	}
	return 0;
}
