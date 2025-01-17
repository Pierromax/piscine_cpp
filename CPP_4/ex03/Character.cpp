/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:37:47 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/16 17:56:00 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : name(name), floor_size(10), floor_count(0)
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    floor = new AMateria*[floor_size];
    for (int i = 0; i < floor_size ; i++)
        floor[i] = NULL; 
}

Character::Character(const Character &src)
{   
    this->name = src.name;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = src.inventory[i]->clone();
    floor_size = src.floor_size;
    floor_count = src.floor_count;
    floor = new AMateria*[floor_size];
    for (int i = 0; i < floor_count; i++)
        floor[i] = src.floor[i]->clone();
    for (int i = floor_count; i < floor_size ; i++)
        floor[i] = NULL;
}

Character::~Character()
{   
    for (int i = 0; i < 4; i++)
        if (this->inventory[i] != NULL)
        {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
    for (int i = 0; i < get_floor_count(); i++)
            delete this->floor[i];
    delete [] this->floor;
}

Character &Character::operator=(const Character &src)
{
    if (this != &src)
    {
        this->name = src.name;
        for (int i = 0; i < 4; i++)
        {
            delete this->inventory[i];
            this->inventory[i] = src.inventory[i]->clone();
        }
        delete[] floor;
        floor_size = src.floor_size;
        floor_count = src.floor_count;
        floor = new AMateria*[floor_size];
        for (int i = 0; i < get_floor_count(); i++)
            floor[i] = src.floor[i]->clone();
        for (int i = get_floor_count(); i < floor_size; i++)
            floor[i] = NULL;
    }
    return *this;
} 

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL)
    {
        if (get_floor_count() >= get_floor_size())
        {
            set_floor_size(get_floor_size() * 2);
            AMateria **new_floor = new AMateria*[get_floor_size()];
            for (int i = 0; i < get_floor_count(); i++)
                new_floor[i] = floor[i];
            delete [] floor;
            this->floor = new_floor;
        }
        floor[get_floor_count()] = this->inventory[idx];
        this->inventory[idx] = NULL;
        set_floor_count(get_floor_count() + 1);
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL)
        this->inventory[idx]->use(target);
}

int Character::get_floor_size() const
{
    return floor_size;
}

void Character::set_floor_size(int const &size)
{
    this->floor_size = size;
}

int Character::get_floor_count() const
{
    return floor_count;
}

void Character::set_floor_count(int const &count)
{
    this->floor_count = count;
}