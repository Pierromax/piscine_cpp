/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:41:23 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/15 00:16:34 by ple-guya         ###   ########.fr       */
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
		Animal &operator=(Animal &type);
		std::string		getType() const;
		virtual void	makeSound() const;
		virtual ~Animal();
};

#endif