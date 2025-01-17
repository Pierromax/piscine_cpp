/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:00:40 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/17 17:26:17 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*************************************** */
/*		Constructor ans destructor		*/
/****************************************/

ClapTrap::ClapTrap() : name("ClapTrap"), Hitpoints(10), Energypoints(10), Attackdamage(0)
{
	std::cout << "claptrap default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), Hitpoints(10), Energypoints(10), Attackdamage(0)
{
	std::cout << "ClapTrap constructor has been called" << std::endl;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "claptrap destructor has been called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &clap) :
name(clap.name), Hitpoints(clap.Energypoints), Energypoints(clap.Energypoints), Attackdamage(clap.Attackdamage)
{
	std::cout << "claptrap copy constructor has been called" << std::endl;
}

/*************************************** */
/*			Member function				*/
/****************************************/

void ClapTrap::attack(const std::string& target)
{
	if (Hitpoints == 0)
		std::cout << name << " has no hit point left, cant do anything" << std::endl;
	else if (Energypoints == 0)
		std::cout << name << " has no energy left, cant do anything" << std::endl;
	else
	{
		Energypoints--;
		std::cout << "ClapTrap " << this->name << " attacks "<< target 
		<< ", causing " << this->Attackdamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (Hitpoints == 0)
	{
		std::cout << "get bullied again in ur death, poor "<< name << std::endl;
		return;
	}
	Hitpoints = Hitpoints - amount;
	if (Hitpoints < 0)
		Hitpoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (Energypoints == 0)
		std::cout << name << " has no energy left, cant do anything" << std::endl;
	else if (Hitpoints == 10)
		std::cout << name << " is already fully repaired" << std::endl;
	else
	{
		Hitpoints += amount;
		Energypoints--;
		std::cout << this->name << " gained " << amount << " of Hitpoints" << std::endl;
	}
	if (Hitpoints > 10)
		Hitpoints = 10;
}

/*************************************** */
/*				Operator				*/
/****************************************/

ClapTrap &ClapTrap::operator=(const ClapTrap &cpy)
{
	if (this != &cpy)
	{
		this->name = cpy.getName();
		this->Energypoints = cpy.getEnergyPoints();
		this->Hitpoints = cpy.getHitPoints();
		this->Attackdamage = cpy.getAttackDamage();
	}
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	return (*this);
}

/*************************************** */
/*				Getter					*/
/****************************************/

std::string	ClapTrap::getName( void ) const
{
	return (this->name);
}

int	ClapTrap::getHitPoints( void ) const
{
	return (this->Hitpoints);
}

int	ClapTrap::getEnergyPoints( void ) const
{
	return (this->Energypoints);
}

int	ClapTrap::getAttackDamage( void ) const
{
	return (this->Attackdamage);
}
