/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:39:40 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/08 00:03:52 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombieHorde.hpp"

int main() 
{
	int N = 5;
	Zombie* horde = zombieHorde(N, "omax");
	for (int i = 0; i < N; ++i) {
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}