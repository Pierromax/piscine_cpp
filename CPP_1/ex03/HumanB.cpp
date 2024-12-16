/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:47:58 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/08 18:06:33 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {}

HumanB::~HumanB()
{
	std::cout << "HumanB has been destroy" <<std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}

void HumanB::attack(void)
{
	if (weapon)
		std::cout << name << " attack with their " << weapon->getType() << std::endl;
	else
		std::cout << name << "try to attack with yheir bare hands and fail" << std::endl;
}