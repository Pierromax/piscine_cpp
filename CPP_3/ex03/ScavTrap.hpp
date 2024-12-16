/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:53:33 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/11 19:23:07 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SVACTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public :
		ScavTrap();
		ScavTrap(const std::string &newname);
		ScavTrap(ScavTrap &cpy);
		ScavTrap& operator=(const ScavTrap &cpy);
		void	attack(const std::string &target);
		void	guardGate(void);
		~ScavTrap();
};

#endif