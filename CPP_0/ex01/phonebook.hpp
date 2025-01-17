/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:58:21 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/07 21:06:04 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
#include <limits>

class	contact
{
	private:
		std::string	name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public :
		void		setName(const std::string &newName);
		void		setLastName(const std::string &newLastName);
		void		setNickName(const std::string &newNickName);
		void		setPhoneNumber(const std::string &newPhoneNumber);
		void		setDarkestSecret(const std::string &newPhoneNumber);
		std::string	getname(void) const;
		std::string	getlastname(void) const;
		std::string	getnickname(void) const;
		std::string	getPhoneNumber(void) const;
};

class	phonebook
{
	private:
		contact	contacts[8];
	public :
		void	addcontact(int index, const contact &newcontact);
		contact	get_contact(int index) const;
};

void	clear_screen(phonebook *book, std::string prompt);
void	add_function(phonebook *book, int index);
void	search_function(phonebook *book);
void	printbook(phonebook *book);

#endif