/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:50:00 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/12 15:10:12 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) 
{
	Harl harl;
	
	if (ac!= 2)
	{
		std::cerr << "Usage : " << av[0] << "log level" <<std::endl;
		return 1;
	}
	std::string arg = av[1];
	harl.complain(arg);
	return 0;
}