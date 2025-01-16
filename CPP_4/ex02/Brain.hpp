/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 03:20:34 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/17 03:55:58 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const std::string &type);
		Brain(Brain &cpy);
		Brain &operator=(Brain &type);
		std::string		getIdea(int index) const;
		~Brain();
};

#endif