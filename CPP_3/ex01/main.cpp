/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:07:41 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/11 15:57:57 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{

	ScavTrap scav1;
    std::string name = "Scavvy";
    ScavTrap scav2(name);
    ScavTrap scav3(scav2);

    // Utilisation des méthodes de ScavTrap
    scav1.attack("target1");
    scav2.attack("target2");
	scav1.beRepaired(10);

    scav1.guardGate();
    scav2.guardGate();


	return 0;
}