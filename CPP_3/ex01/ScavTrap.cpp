/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:11:47 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/11 19:23:52 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*************************************** */
/*		Constructor ans destructor		*/
/****************************************/

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
	this->name = "Scavtrap";
	this->Hitpoints = 100;
	this->Energypoints = 50;
	this->Attackdamage = 20;
	std::cout << "Scavtrap default constructor called" << std::endl;
}
ScavTrap::ScavTrap(const std::string &newname) : ClapTrap(newname)
{
	this->name = newname;
	this->Hitpoints = 100;
	this->Energypoints = 50;
	this->Attackdamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &cpy) : ClapTrap(cpy)
{
	this->name = cpy.name;
	this->Hitpoints = cpy.Hitpoints;
	this->Energypoints = cpy.Energypoints;
	this->Attackdamage = cpy.Attackdamage;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

/*************************************** */
/*			Member function				*/
/****************************************/

void	ScavTrap::attack(const std::string &target)
{
	if (Hitpoints == 0)
		std::cout << name << " has no hit point left, cant do anything" << std::endl;
	else if (Energypoints == 0)
		std::cout << name << " has no energy left, cant do anything" << std::endl;
	else
	{
		Energypoints--;
		std::cout << "ScavTrap " << this->name << " attacks "<< target 
		<< ", causing " << this->Attackdamage << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << " is guard gating mode" << std::endl;
}

/*************************************** */
/*				Operator				*/
/****************************************/

ScavTrap& ScavTrap::operator=(const ScavTrap &cpy)
{
	if (this != &cpy)
	{
		ClapTrap::operator=(cpy);
		this->Hitpoints = cpy.Hitpoints;
		this->Energypoints = cpy.Energypoints;
		this->Attackdamage = cpy.Attackdamage;
	}
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return *this;
}

