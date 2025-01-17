/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:07:41 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/17 15:31:38 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap dems("dems");
	
	std::cout << "diamondtrap attack damage : " << dems.getAttackDamage() << std::endl;
	std::cout << "diamondtrap hit points : " << dems.getHitPoints() << std::endl;
	std::cout << "diamondtrap EnergyPoints : " << dems.getEnergyPoints() << std::endl;
	dems.whoAmI();
	dems.attack("oui");
	dems.guardGate();
	return 0;
}