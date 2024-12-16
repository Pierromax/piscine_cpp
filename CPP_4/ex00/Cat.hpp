/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:04:03 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/15 00:07:02 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"

class Cat : virtual public Animal
{
	public:
		Cat();
		Cat(std::string &type);
		Cat(Cat &cpy);
		Cat &operator=(Cat &type);
		void	makeSound() const;
		~Cat();
};

#endif