/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:41:30 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/17 03:47:24 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

/******************************/
/*  Constructor & destrutor   */
/******************************/

Dog::Dog() : Animal("Dog")
{
	this->dogBrain = new Brain();
	std::cout << "default Dog constructor called" << std::endl;
}

Dog::Dog(std::string &type) : Animal(type)
{
	this->dogBrain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog &cpy) : Animal(cpy.type)
{
	this->dogBrain = cpy.dogBrain;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete [] dogBrain;
	std::cout << "Dog destructor called" << std::endl;
}

/******************************/
/*    surcharge d'opeateur    */
/******************************/

Dog	&Dog::operator=(Dog &cpy)
{
	if (this != &cpy)
		this->type = cpy.type;
	return (*this);
}

/******************************/
/*      member function       */
/******************************/

void	Dog::makeSound() const
{
	std::cout << "Wouf Wouf" << std::endl;
}