/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:41:27 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/27 14:18:56 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

/******************************/
/*  Constructor & destrutor   */
/******************************/

Cat::Cat() : Animal("Cat")
{
	this->catBrain = new Brain();
	std::cout << "default Cat constructor called" << std::endl;
}

Cat::Cat(std::string &type) : Animal(type)
{
	this->catBrain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat &cpy) : Animal(cpy.type)
{
	this->catBrain = new Brain(*cpy.catBrain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	if (this->catBrain)
		delete this->catBrain;
	std::cout << "Cat destructor called" << std::endl;
}

/******************************/
/*    surcharge d'opeateur    */
/******************************/

Cat	&Cat::operator=(Cat &cpy)
{
	if (this != &cpy)
	{
		this->type = cpy.type;
		delete this->catBrain;
		this->catBrain = cpy.catBrain;
	}
	return (*this);
}
/******************************/
/*      member function       */
/******************************/

void	Cat::makeSound() const
{
	std::cout << "Miaou Miaou (les jours de l'humaniter sont compter)" << std::endl;
}