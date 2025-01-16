/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:36:44 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/16 13:58:14 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria *inventory[4];
        AMateria **floor;
        int     floor_size;
        int     floor_count;
    public:
        Character(std::string const &name);
        Character(const Character &src);
        ~Character();
        Character &operator=(const Character &src);
        std::string const &getName() const;
        int get_floor_size() const;
        void set_floor_size(int const &size);
        int get_floor_count() const;
        void set_floor_count(int const &size);
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};

#endif