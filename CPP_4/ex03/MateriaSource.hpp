/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:55:48 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/10 15:56:40 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *source[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &src);
        ~MateriaSource();
        MateriaSource &operator=(const MateriaSource &src);
        void learnMateria(AMateria *m);
        AMateria *createMateria(std::string const &type);
};

#endif