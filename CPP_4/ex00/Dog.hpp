/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:05:02 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/15 00:10:19 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"

class Dog : virtual public Animal
{
	protected:
		std::string	type;
	public:
		Dog();
		Dog(std::string &type);
		Dog(Dog &cpy);
		Dog &operator=(Dog &type);
		void	makeSound() const;
		~Dog();
};

#endif