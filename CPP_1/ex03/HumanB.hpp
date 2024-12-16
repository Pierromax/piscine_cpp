/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:48:00 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/08 17:42:52 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private :
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon &newWeapon);
		void	attack(void);
		~HumanB();
};

#endif