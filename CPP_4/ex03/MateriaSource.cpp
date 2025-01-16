/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:46:50 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/16 14:33:44 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    for (int i = 0; i < 4; i++)
        this->source[i] = src.source[i]->clone();
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->source[i] != NULL)
        {
            delete this->source[i];
            this->source[i] = NULL;
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
        {
            delete this->source[i];
            this->source[i] = src.source[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->source[i] == NULL)
        {
            this->source[i] = m;
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->source[i] != NULL && this->source[i]->getType() == type)
            return this->source[i]->clone();
    }
    return NULL;
}
