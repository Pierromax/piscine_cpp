/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:38:01 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/08 00:02:17 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "zombieHorde.hpp"

Zombie	*zombieHorde(int N, std::string name) 
{
	Zombie* horde;

	if (N <= 0)
		return NULL;
	horde = new Zombie[N];
	for (int i = 0; i < N; ++i) 
		horde[i].setname(name);
	return horde;
}