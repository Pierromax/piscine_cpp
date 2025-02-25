/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:41:14 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/27 13:41:26 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_HPP
#define WrongAnimal_HPP

#include <string>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const std::string &type);
		WrongAnimal(WrongAnimal &cpy);
		WrongAnimal &operator=(WrongAnimal &type);
		std::string		getType() const;
		virtual void	makeSound() const;
		virtual ~WrongAnimal();
};

#endif