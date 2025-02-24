/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:59:22 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/23 16:39:54 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// void print_char(char c)
// {
//     std::cout << c << " ";
// }

// void print_int(int x)
// {
//     std::cout << x << " ";
// }

// void intcrement(int &x)
// {
//     x++;
// }

// void increment(char &x)
// {
//     x++;
// }

int main()
{
    std::string str_arr[] = {"coucoou", "c'est moi", "tu veux", "voir", "mon code ?"};
    size_t str_size = sizeof(str_arr) / sizeof(str_arr[0]);
    char char_arr[] = {'a','b', 'c', 'd', 'f', 't'};
    size_t char_size = sizeof(char_arr) / sizeof(char_arr[0]);
    int int_arr[] = {8, 7, 8, 9, 7, 8, 7, 87, 9844, 65654, 654, 35};
    size_t int_size = sizeof(int_arr) / sizeof(int_arr[0]);

    std::cout << std::endl << std::string(40, '=') << std::endl;
    std::cout << std::string(15, ' ') << "string array" << std::endl << std::string(40, '=') << std::endl;
    iter(str_arr, str_size, print_with_space<std::string>);
    std::cout << std::endl;
    for (size_t i = 0; i < str_size; i++)
            iter(str_arr[i], str_arr[i].size(), add_one<char>);
    iter(str_arr, str_size, print_with_space<std::string>);
    std::cout << std::endl;
    std::cout << std::endl << std::string(40, '=') << std::endl;
    std::cout << std::string(15, ' ') << "int array" << std::endl << std::string(40, '=') << std::endl;
    iter(int_arr, int_size, print_with_space<int>);
    iter(int_arr, int_size, add_one<int>);
    std::cout << std::endl;
    iter(int_arr, int_size, print_with_space<int>);
    std::cout << std::endl <<std::endl << std::string(40, '=') << std::endl;
    std::cout << std::string(15, ' ') << "char array" << std::endl << std::string(40, '=') << std::endl;
    iter(char_arr, char_size, print_with_space<char>);
    iter(char_arr, char_size, add_one<char>);
    std::cout << std::endl;
    iter(char_arr, char_size, print_with_space<char>);

    return 0;
}