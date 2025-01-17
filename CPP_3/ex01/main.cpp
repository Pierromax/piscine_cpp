/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:07:41 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/17 15:30:02 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{

	ScavTrap scav1;
    std::string name = "Scavvy";
    ScavTrap scav2(name);
    ScavTrap scav3(scav2);

    scav1.attack("Scavvy");
    scav3.takeDamage(scav1.getAttackDamage());
    scav2.attack("scav1");
    scav1.takeDamage(scav2.getAttackDamage());
    
	scav1.beRepaired(10);

    scav1.guardGate();
    scav2.guardGate();

	return 0;
}