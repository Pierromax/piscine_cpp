/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:06:53 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/08 00:13:17 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() 
{
	std::string string;
	std::string *stringPTR;
	std::string &stringREF = string;

	string = " HI THIS IS BRAIN ";
	stringPTR = &string;

	std::cout << "The memory address of the string variable: " << &string << std::endl;
	std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "The value of the string variable: " << string << std::endl;
	std::cout << "The value pointed to by stringPTR:" << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF:" << stringREF << std::endl;

	return 0;
}