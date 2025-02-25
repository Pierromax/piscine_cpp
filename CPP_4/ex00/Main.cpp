/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:16:40 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/27 13:54:43 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* hawai = new WrongAnimal();
	const WrongAnimal* ui = new WrongCat();
	WrongCat test;
	
	std::cout << i->getType() << " I " << std::endl;
	std::cout << j->getType() << " j " << std::endl;
	std::cout << hawai->getType() << " hawai " << std::endl;
	std::cout << ui->getType() << " ui " << std::endl;
	std::cout << test.getType() << " test " << std::endl;
	std::cout << meta->getType() << " meta " << std::endl;
	
	test.makeSound();
	hawai->makeSound();
	ui->makeSound();
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	delete hawai;
	delete ui;
	
	return 0;
}