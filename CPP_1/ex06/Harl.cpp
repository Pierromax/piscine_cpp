/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:49:56 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/12 15:26:45 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() 
{}

Harl::~Harl() {}

void Harl::debug(void) 
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << " love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) 
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough "
	<< "bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) 
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for " 
	<< "years whereas you started working here since last month" << std::endl;
}

void Harl::error(void) 
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

static int get_level(std::string level)
{
	std::string levels[4] = {"DEBUG","INFO","WARNING","ERROR"};
	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
			return(1);
	}
	return 4;
}

void Harl::complain(std::string level)
{
	switch (get_level(level))
	{
		case 0:
			this->debug();
			// fall through
		case 1:
			this->info();
			// fall through 
		case 2:
			this->warning();
			// fall through
		case 3:
			this->error();
			break;
		default:
			std::cout << "complaing again... but we don't care" << std::endl;
			break;
	}
}