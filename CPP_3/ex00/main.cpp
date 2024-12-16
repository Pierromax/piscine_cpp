/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:07:41 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/09 19:25:35 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap1("BOB");
	ClapTrap clap2("AYOUB");

	clap1.attack("target1");
	clap2.attack("target2");

	clap1.takeDamage(5);
	clap2.takeDamage(10);

	clap1.beRepaired(3);
	clap2.beRepaired(7);

	return 0;
}