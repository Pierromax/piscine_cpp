/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:30:14 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/27 20:52:24 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*************************************** */
/*		Constructor ans destructor		*/
/****************************************/

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
	this->Hitpoints = 100;
	this->Energypoints = 100;
	this->Attackdamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &newname) : ClapTrap(newname)
{
	this->name = newname;
	this->Hitpoints = 100;
	this->Energypoints = 100;
	this->Attackdamage = 30;
	std::cout << "FragTrap constructor called fot" << newname << std::endl;
}

FragTrap::FragTrap( const FragTrap &cpy) : ClapTrap(cpy)
{
	this->name = cpy.name;
	this->Hitpoints = cpy.Hitpoints;
	this->Energypoints = cpy.Energypoints;
	this->Attackdamage = cpy.Attackdamage;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

/****************************************/
/*               Operator               */
/****************************************/

FragTrap& FragTrap::operator=(const FragTrap &cpy)
{
	if (this != &cpy)
	{
		ClapTrap::operator=(cpy);
		this->Hitpoints = cpy.Hitpoints;
		this->Energypoints = cpy.Energypoints;
		this->Attackdamage = cpy.Attackdamage;
	}
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return *this;
}

/*************************************** */
/*         Member functions             */
/****************************************/

void	FragTrap::attack(const std::string &target)
{
	if (Hitpoints == 0)
		std::cout << name << " has no hit point left, cant do anything" << std::endl;
	else if (Energypoints == 0)
		std::cout << name << " has no energy left, cant do anything" << std::endl;
	else
	{
		Energypoints--;
		std::cout << "FragTrap " << this->name << " attacks "<< target 
		<< ", causing " << this->Attackdamage << " points of damage!" << std::endl;
	}
}

static void	displayHighFiveArt()
{
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠒⢀⣠⠒⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣡⠈⠱⡗⠉⢮⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⡁⠀⢀⡇⠀⢸⢃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠁⠀⠠⡇⠀⠐⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠀⠀⢰⠅⠀⠀⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠶⠀⠀⢸⡆⠀⠀⣯⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣮⠇⠀⠀⢸⡇⠀⠀⠺⣗⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠎⠀⠀⠀⢸⡷⠀⠀⠐⣯⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣟⠁⠀⠀⠀⢸⡇⠀⠀⠀⡩⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠏⠀⠀⠀⠀⢼⡏⠀⠀⠀⠘⡵⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡎⠌⠀⠀⠀⠀⢺⣇⠀⠀⠀⠀⠵⣓⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠞⠀⠀⠀⠀⠀⠀⣻⣧⠀⠀⠀⠀⠈⠔⢳⡀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⣀⣠⡶⡖⠉⠂⠀⠀⠀⠀⠀⡐⣿⣿⡀⠀⠀⠀⠀⠈⠢⠙⢲⣶⣄⡀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⣀⣤⣴⣿⣿⣿⣷⡄⠀⠀⠀⠀⠀⢀⡰⣭⣿⣿⡥⣀⠠⠀⠀⠀⠀⠈⣶⣿⣿⣿⣿⣦⣄⣀" << std::endl;
	std::cout << "⠰⣾⣿⣿⣿⣿⡻⢧⢏⡳⣄⠀⠀⠀⣘⣦⡷⠛⠉⠈⠛⢳⣦⡑⠀⠀⠀⣴⣛⠾⣽⣻⣿⣿⣿⣿" << std::endl;
	std::cout << "⢘⣿⣿⡟⣷⣣⠟⡭⢎⡱⣌⠷⣤⣸⣵⣿⠀⠀⠀⠀⠀⠀⢿⣗⣦⣤⡞⣣⢎⡽⢣⣟⢷⣻⣿⣿" << std::endl;
	std::cout << "⠰⣿⣳⡻⣵⢋⡞⣱⢣⡳⣜⣿⣿⣿⡿⠁⠀⠀⠀⠀⠀⠀⠈⢻⣿⣿⣞⡵⣪⣜⢳⢮⣻⢽⡾⣿" << std::endl;
	std::cout << "⠈⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉" << std::endl;
}

static void	displayWindArt()
{
    std::cout << "███████████               " << std::endl;
    std::cout << "                                  ████████████               ██████████████████           " << std::endl;
    std::cout << "                                ███         ████           ███                 ████        " << std::endl;
    std::cout << "                               ██             ███        ███                     ████      " << std::endl;
    std::cout << "                              ██               ███       █           █████         ███     " << std::endl;
    std::cout << "                              ██                ███     ██        █       ███       ███    " << std::endl;
    std::cout << "                              ██          █     ███     █                   ███      ███   " << std::endl;
    std::cout << "                               ██         █     ███     █                    ███      ██   " << std::endl;
    std::cout << "                                ██       ██     ███     ██                    ███     ███  " << std::endl;
    std::cout << "                                  ███████      ███       █                    ███     ███  " << std::endl;
    std::cout << "                                              ████        ██                  ███     ███  " << std::endl;
    std::cout << "                ██████████████████          █████             █              ███      ███  " << std::endl;
    std::cout << "           ████                ████████████████                             ████      ███  " << std::endl;
    std::cout << "       ███                             ███                                 ████      ███   " << std::endl;
    std::cout << "     █                                                                   ████       ███    " << std::endl;
    std::cout << "                      ███████████                                    ██████        ███     " << std::endl;
    std::cout << "                ███               ██████                  ██████████████          ███      " << std::endl;
    std::cout << "                                       █████                                    ████       " << std::endl;
    std::cout << "                                           █████                             █████         " << std::endl;
    std::cout << "                                              ██████                      █████            " << std::endl;
    std::cout << "                                                   ████████        █████████               " << std::endl;
    std::cout << "                                                         ██████████████" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::string	input;
	std::cout << this->name << " extends its arm waiting for a high five" << std::endl;
	std::cout << "[accept/decline] ?" << std::endl;
	std::cin >> input;
	while (input != "accept" && input != "decline")
	{
		std::cout << "Invalid input. Please type 'accept' or 'decline'." << std::endl;
		std::cin >> input;
	}
	if (input == "accept")
	{
		std::cout << "YEAH!" << std::endl;
		displayHighFiveArt();
	}
	else if (input == "decline")
	{
		std::cout << "*wind noise*" << std::endl;
		displayWindArt();
	}
}
