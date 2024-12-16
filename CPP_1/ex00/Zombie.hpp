/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:11:33 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/07 22:52:41 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private :
		std::string name;
	public:
		Zombie(std::string name);
		void announce(void);
		~Zombie(void);
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif