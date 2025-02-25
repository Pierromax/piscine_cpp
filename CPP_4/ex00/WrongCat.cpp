/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:40:18 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/27 13:55:09 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

/******************************/
/*  Constructor & destrutor   */
/******************************/

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(std::string &type) : WrongAnimal(type)
{
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat &cpy) : WrongAnimal(cpy.type)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

/******************************/
/*    surcharge d'opeateur    */
/******************************/

WrongCat	&WrongCat::operator=(WrongCat &cpy)
{
	if (this != &cpy)
		this->type = cpy.type;
	return (*this);
}
/******************************/
/*      member function       */
/******************************/

void	WrongCat::makeSound() const
{
	std::cout << "miaou motherfucker" << std::endl;
}