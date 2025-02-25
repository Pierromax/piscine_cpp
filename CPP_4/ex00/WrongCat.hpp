/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:39:39 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/27 13:47:48 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP
#define WrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string &type);
		WrongCat(WrongCat &cpy);
		WrongCat &operator=(WrongCat &type);
		void	makeSound() const;
		~WrongCat();
};

#endif