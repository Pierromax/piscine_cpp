/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:00:38 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/17 17:22:59 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string name;
		int	Hitpoints;
		int	Energypoints;
		int	Attackdamage;
	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(ClapTrap &clap);
		
		ClapTrap&	operator=(const ClapTrap &cpy);
		std::string	getName(void) const;
		int			getHitPoints( void ) const;
		int			getEnergyPoints( void ) const;
		int			getAttackDamage( void ) const;
		void	attack(const std::string& target);
		
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		~ClapTrap();
};

#endif