/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:08:34 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/11 19:30:40 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*************************************** */
/*		Constructor ans destructor		*/
/****************************************/

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap(), name("_clap_name")
{
	this->Hitpoints = FragTrap::Hitpoints;
	this->Energypoints = ScavTrap::Energypoints;
	this->Attackdamage = FragTrap::Attackdamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &newname) : ClapTrap(newname), FragTrap(), ScavTrap(), name(newname + "_clap_name")
{
	this->Hitpoints = FragTrap::Hitpoints;
	this->Energypoints = ScavTrap::Energypoints;
	this->Attackdamage = FragTrap::Attackdamage;
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &cpy) : ClapTrap(cpy), FragTrap(cpy), ScavTrap(cpy), name(cpy.name)
{
	*this = cpy;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

/****************************************/
/*               Operator               */
/****************************************/

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &cpy)
{
	if (this != &cpy)
	{
		ClapTrap::operator=(cpy);
		FragTrap::operator=(cpy);
		ScavTrap::operator=(cpy);
		name = cpy.name;
	}
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	return *this;
}

/****************************************/
/*           Member function            */
/****************************************/

void	DiamondTrap::whoAmI(void)
{
	std::cout << "to be " << this->name << " or to be " << ClapTrap::name << " that is the question"<< std::endl;
}