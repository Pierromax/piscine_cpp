/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 03:20:36 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/27 14:15:10 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

/******************************/
/*  Constructor & destrutor   */
/******************************/

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "idee par default";
	std::cout << "default Brain constructor called" << std::endl;
}

Brain::Brain(const std::string &idea)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = idea;
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain &cpy)
{	
	for (int i = 0; i < 100; i++)
		this->ideas[i] = cpy.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}	

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

/******************************/
/*    surcharge d'opeateur    */
/******************************/

Brain	&Brain::operator=(Brain &cpy)
{
	if (this != &cpy)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = cpy.ideas[i];
	}
	return (*this);
}

/******************************/
/*    surcharge d'opeateur    */
/******************************/

std::string	Brain::getIdea(int index) const
{
	return(ideas[index]);
}
