/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:56:21 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/17 15:14:46 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DiamondTrap_HPP
#define DiamondTrap_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string &newname);
		DiamondTrap(DiamondTrap &cpy);

		DiamondTrap&	operator=(const DiamondTrap &cpy);
		void	attack(const std::string &target);
		void	whoAmI(void);

		~DiamondTrap();
};

#endif