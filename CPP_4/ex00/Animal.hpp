/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:41:23 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/27 13:42:54 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const std::string &type);
		Animal(Animal &cpy);
		Animal &operator=(Animal &rhs);
		std::string		getType() const;
		virtual void	makeSound() const;
		virtual ~Animal();
};

#endif