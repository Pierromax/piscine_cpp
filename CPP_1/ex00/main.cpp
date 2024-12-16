/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:23:11 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/07 22:51:14 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* cranberry;
	cranberry = newZombie("heap");
	cranberry->announce();
	delete cranberry;
	randomChump("stack");
	return 0;
}