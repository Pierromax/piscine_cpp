/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:24:50 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/06 17:38:55 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string	contact::getname(void) const
{
	return name;
}

std::string	contact::getPhoneNumber(void) const
{
	return phone_number;
}

std::string	contact::getlastname(void) const
{
	return last_name;
}

std::string	contact::getnickname(void) const
{
	return nickname;
}

void	contact::setName(const std::string &newname)
{
	name = newname;
}

void	contact::setLastName(const std::string &newLastName)
{
	last_name = newLastName;
}

void		contact::setNickName(const std::string &newNickName)
{
	nickname = newNickName;
}
void		contact::setPhoneNumber(const std::string &newPhoneNumber)
{
	phone_number = newPhoneNumber;
}
void		contact::setDarkestSecret(const std::string &newsecret)
{
	darkest_secret = newsecret;
}

void	phonebook::addcontact(int index, const contact &newcontact)
{
	if (index >= 0 && index < 8)
		contacts[index] = newcontact;
}

contact	phonebook::get_contact(int index) const
{
	if (index >= 0 && index < 8)
		return (contacts[index]);
	return contact();
}
