/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:30:16 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/11 19:23:20 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public :
		FragTrap();
		FragTrap(const std::string &newname);
		FragTrap(FragTrap &cpy);
		FragTrap& operator=(const FragTrap &cpy);
		void	attack(const std::string &target);
		void	highFivesGuys(void);
		~FragTrap();
};

#endif