/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:41:51 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/27 13:46:01 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

/******************************/
/*  Constructor & destrutor   */
/******************************/

WrongAnimal::WrongAnimal() : type("Default")
{
	std::cout << "default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &cpy) : type(cpy.type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/******************************/
/*      member functions      */
/******************************/

void	WrongAnimal::makeSound() const
{
	std::cout << "j'aime les pizza a l'ananas" << std::endl;
}

/******************************/
/*           getter           */
/******************************/

std::string WrongAnimal::getType() const
{
	return type;
}

/******************************/
/*    surcharge d'opeateur    */
/******************************/

WrongAnimal	&WrongAnimal::operator=(WrongAnimal &animal)
{
	if (this != &animal)
		this->type = animal.type;
	return (*this);
}
