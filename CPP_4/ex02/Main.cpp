/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:16:40 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/27 14:15:42 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
	// Subject test
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;//should not create a leak
	delete i;

	std::cout << std::endl;

	Dog* a = new Dog();
	Dog* b = new Dog(*a);
	Dog *c = new Dog();
	delete a;
	delete b;
	delete c;
	
	std::cout << std::endl;

	const Animal*	array[6]; // Create an animal array

	for (int i = 0; i < 3; i++)
	{	// Fill one part of the array
		array[i] = new Dog();	// with newly allocated dogs
		std::cout << std::endl;
	}
	for (int i = 3; i < 6; i++)
	{	// Fill the other part of the array
		array[i] = new Cat();	// with newly allocated cats
		std::cout << std::endl;
	}
	// Freeing memory
	for (int i = 0; i < 6; i++){
		delete(array[i]);
		std::cout << std::endl;
	}
	return 0;
}
