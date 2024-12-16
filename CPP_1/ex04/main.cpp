/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:08:59 by ple-guya          #+#    #+#             */
/*   Updated: 2024/12/08 19:38:59 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

static void	replaceline(std::string &content, std::string s1, std::string s2)
{
	size_t pos = 0;
	
	while ((pos = content.find(s1, pos)) != std::string::npos) 
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}
}

int main(int ac, char **av)
{
	if (ac != 4)
		return (std::cerr << "Usage " << av[0] << " <filename> <s1> <s2>" << std::endl, 1);
	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	std::ifstream input(av[1]);
	
	if (!input.is_open())
		return (std::cerr << filename << " : doesnt exist or can't access" <<std::endl, 1);
	std::ofstream outfile((filename + ".replace").c_str());
	 if (!outfile.is_open())
		return (std::cerr << "can't create file" <<std::endl, 1);
		
	std::string content;
	while(getline(input, content))
	{
		replaceline(content, s1, s2);
		outfile << content << std::endl;
	}
	return 0;
}
