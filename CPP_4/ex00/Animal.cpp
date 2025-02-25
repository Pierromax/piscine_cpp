/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:43:53 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/27 13:42:42 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

/******************************/
/*  Constructor & destrutor   */
/******************************/

Animal::Animal() : type("Default")
{
	std::cout << "default Animal constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal &cpy) : type(cpy.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

/******************************/
/*      member functions      */
/******************************/

void	Animal::makeSound() const
{
	std::cout << "skibidi toilet" << std::endl;
}

/******************************/
/*           getter           */
/******************************/

std::string Animal::getType() const
{
	return type;
}

/******************************/
/*    surcharge d'opeateur    */
/******************************/

Animal	&Animal::operator=(Animal &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}
