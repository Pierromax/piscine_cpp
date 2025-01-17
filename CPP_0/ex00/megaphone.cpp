/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:18:35 by ple-guya          #+#    #+#             */
/*   Updated: 2025/01/06 21:04:32 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
    if (ac < 2)
        return (std::cout << "* LOUD AND UNBREAKABLE FEEDBACK NOISE *" << std::endl, 1);
    for (int i = 1; i < ac; i++)
      for (size_t j = 0; av[i][j]; j++)
        std::cout << (char)toupper(av[i][j]);
    std::cout << std::endl;
}
