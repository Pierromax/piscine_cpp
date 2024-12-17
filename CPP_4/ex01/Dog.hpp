/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:05:02 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/17 03:53:37 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal
{
	private:
		Brain *dogBrain;
	public:
		Dog();
		Dog(std::string &type);
		Dog(Dog &cpy);
		Dog &operator=(Dog &type);
		void	makeSound() const;
		~Dog();
};

#endif