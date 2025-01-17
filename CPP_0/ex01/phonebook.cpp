/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:28:07 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/07 21:09:59 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static std::string truncate(std::string str, size_t width)
{
	if (str.size() > width)
		return (str.substr(0, width - 1) + ".");
	else
		return (str);
}

void	printbook(phonebook *book)
{
	std::string	info;
	contact		man;
	int			i = 0;

	std::cout << "/-----------------------------------------------\\" << std::endl;
	std::cout << "|  index  |   name    |  lastname  |  nickname  |" << std::endl;
	std::cout << "|-----------------------------------------------|" << std::endl;
	while (i < 8)
	{
		man = book->get_contact(i);
	std::cout << "|" << std::setw(5) << i + 1 << std::setw(5) << "|" 
			<< std::setw(10)<< truncate(man.getname(), 10) << " | " 
			<< std::setw(10) << truncate(man.getlastname(), 10) << " | " 
			<< std::setw(10) << truncate(man.getnickname(), 10) << " |" << std::endl;
		i++;
	}
	std::cout << "\\-----------------------------------------------/" << std::endl;
	std::cout << "command list :" << std::endl 
	<< "ADD -> create a contact" << std::endl 
	<< "SEARCH -> use this to dispay a specific contact" << std::endl 
	<< "EXIT -> quit the phonebook and lost all contact" << std::endl << std::endl;
}

static	std::string get_valid_input(const std::string prompt)
{
	std::string input;
	
	while (true)
	{
		std::cout << prompt;
		std::cin >> input;
		if (std::cin.good() == false)
			break ;
		if (!input.empty())
			return input;
	}
	return ("");
}

void	add_function(phonebook *book, int index)
{
	contact cont;
	std::string	input;

	input = get_valid_input("Enter a name: ");
	if (input == "")
		return ;
	cont.setName(input);
	if (input == "")
		return ;
	input = get_valid_input("Enter a last name : ");
	if (input == "")
		return ;
	cont.setLastName(input);
	input = get_valid_input("Enter a phone number : ");
	if (input == "")
		return ;
	cont.setPhoneNumber(input);
	input = get_valid_input("Enter a nickname : ");
	if (input == "")
		return ;
	cont.setNickName(input);
	input = get_valid_input("What's your darkest secret :");
	if (input == "")
		return ;
	cont.setDarkestSecret(input);
	book->addcontact(index, cont);
	clear_screen(book, "contact added successfully!");
}

void	search_function(phonebook *book)
{
	std::string	input;
	int			index;
	contact		search;

	input = get_valid_input("what index do you want to consult ? ");
	std::stringstream ss(input);
	if (!(ss >> index) || index < 1 || index > 8)
		return(clear_screen(book, "invalid index"));
	search = book->get_contact(index - 1);
	if (search.getname() == "")
		return(clear_screen(book, "contact doesnt exit yet"));
	clear_screen(book, "");
	std::cout << "/-----------------------------------------------\\" << std::endl;
	std::cout << "|  index  |   name    |  lastname  |  nickname  |" << std::endl;
	std::cout << "|-----------------------------------------------|" << std::endl;
	std::cout << "|" << std::setw(5) << index << std::setw(5) << "|" 
			<< std::setw(10)<< truncate(search.getname(), 10) << " | " 
			<< std::setw(10) << truncate(search.getlastname(), 10) << " | " 
			<< std::setw(10) << truncate(search.getnickname(), 10) << " |" << std::endl;
	std::cout << "\\-----------------------------------------------/" << std::endl;
	return;
}
