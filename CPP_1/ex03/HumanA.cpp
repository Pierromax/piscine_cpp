/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:47:52 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/08 17:43:28 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA()
{
	std::cout << "HumanA has Been destroy" << std::endl;
}

void	HumanA::setWeapon(Weapon &newWeapon) const
{
	weapon = newWeapon;
}

void HumanA::attack(void)
{
	std::cout << name << " attack with their " << weapon.getType() << std::endl;
}