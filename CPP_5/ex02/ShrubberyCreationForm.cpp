/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:21:47 by ple-guya          #+#    #+#             */
/*   Updated: 2025/02/15 16:05:41 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/********************************************/
/*       Constructor et destructor          */
/********************************************/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", SHRUBBERY_SIGN, SHRUBERRY_EXEC)
{
    this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target) : AForm("Shrubbery", SHRUBBERY_SIGN, SHRUBERRY_EXEC)
{
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &cpy) : AForm(cpy), target(cpy.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        this->target = rhs.target;
    }
    return (*this);
}

/********************************************/
/*            Member functions              */
/********************************************/

static void CreateTree(const std::string &target)
{
    std::ofstream ofs(target + "_shrubbery");
    if (!ofs)
    {
        std::cerr << "Error: Could not create file " << target + "_shrubbery" << std::endl;
        return;
    }
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣦⣼⠻⠿⣦⣄⠀⢀⣼⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡾⠃⠀⠀⠀⠉⠙⠚⠙⢿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡾⣦⢾⣦⣤⠀⠀⢀⢙⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠉⣿⡀⢀⣼⠿⣷⣼⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡴⠾⠋⠀⠀⠀⠉⣻⡿⠞⠛⢻⣅⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠙⡿⠛⠁⠀⠉⠁⠛⣿⣾⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⢿⡄⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⣹⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⡶⣿⡉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠀⠀⠀⠀⠀⠀⢰⣦⣶⣶⣤⣀⠀⠀⠀⠀⢹⣷⣶⣦⣤⡶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣦⠀⢹⣧⣦⣴⠆⢠⣦⣦⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠀⠀⠀⢀⣠⣶⡾⠃⠀⠀⠉⠟⠷⢶⣶⣶⡀⠀⣀⣤⣸⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣀⣤⣠⣤⡶⣿⣳⠟⠁⣤⣾⠀⠀⠘⠷⠋⠀⣸⣇⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠀⢰⣿⠟⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠷⡼⠏⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⠛⠀⠈⠘⠃⠉⠀⠀⠈⠛⠒⠋⠀⠀⠀⠀⠀⠀⠀⠈⠉⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    
    ofs << "⣰⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⡄⢀⣴⡇⠀⢀⣠⣾⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⡇⢀⣀⡀⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠋⣿⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⠀⠀⠀⢿⡽⣿⠿⣧⠷⣼⣧⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠋⢯⡆⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠀⣾⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠋⠱⣿⣿⢶⠀⠀⢣⣿⡆⠈⡷⢷⡜⣷⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠇⠀⠀⠀⠀⠀⠀\n";
    ofs << "⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣓⣾⠽⣇⠀⢁⡞⠑⠛⢻⡾⣷⣀⡄⣀⣤⣠⠄⠀⣠⣤⠀⠀⠀⠀⠀⠀⣀⡀⣤⣠⣤⡼⣉⣤⣦⡀⢀⠀⠀⠀\n";
    ofs << "⠈⠙⣿⣄⠀⣠⣦⡄⠀⠀⢰⣶⣆⠀⠀⡀⠀⠀⠀⠀⢠⣀⣴⠋⠉⠹⣆⢹⣄⠸⠀⢠⠟⢸⠃⠈⠉⢻⡏⢻⠁⠀⢠⣟⣞⣀⠀⠀⢀⠀⠀⠿⢽⣧⣹⣠⣿⠏⠉⠙⠛⢻⣖⠴⣦\n";
    ofs << "⠀⠀⠛⠿⠺⠻⠻⣧⣶⣴⣾⡿⣿⣴⠟⢛⡷⠂⠀⠀⡀⠀⠁⠀⠀⠀⠈⠛⣛⠓⣆⣞⠀⡏⠀⠀⠀⣸⠃⡏⢀⡠⠼⡟⢫⣧⡖⠊⠉⠀⠀⠀⠀⠀⠉⠙⠁⠀⠀⠀⠀⠀⠀⠀⣿\n";
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠈⠛⢻⣿⣤⣀⠀⢠⡾⠁⠀⠀⠳⣽⠂⢀⠀⣀⡴⣶⣶⠉⢷⠈⠙⠀⣇⠀⠀⣰⢃⡼⠛⠉⣠⡤⠿⠻⣆⠙⢦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿\n";
    ofs << "⠀⠀⠀⠀⠀⠀⠀⢀⣀⣠⡏⠉⠻⡷⡞⠀⠀⠀⣠⠞⣠⠴⠞⠋⠁⠀⠈⢿⣇⡤⡶⠛⣷⣭⠀⠀⠀⠀⠁⣻⣋⣀⣀⣀⢀⣈⠳⠸⠷⠤⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸\n";
    ofs << "⠀⠀⠀⠀⢠⣾⣟⠟⠛⠋⠀⠀⠀⠀⠀⠀⠀⠠⢃⣰⠃⠀⠀⠀⠀⠀⠀⠈⠟⠀⠀⠀⢱⢿⡀⠠⡤⢤⣼⠟⠋⠛⠉⠋⠁⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠻\n";
    ofs << "⠀⠀⠀⠀⠈⣿⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠇⣼⠁⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣄⣰⡞⠻⠃⠀\n";
    ofs << "⠀⠀⠀⠀⠀⢻⣧⣤⣀⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣴⠾⠋⠀⠃⠠⡇⠀⠀⣀⡀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣛⣋⡁⠉⠀⠀⠀⠀\n";
    ofs << "⠀⠀⠀⠀⠀⠀⠉⠙⠉⣿⢂⣄⠀⠀⠀⠀⠀⣿⢀⡀⠀⠀⠀⠀⠀⢴⣤⠶⠷⠛⠉⢳⠀⠀⠀⠀⣰⠿⣤⢦⠟⢻⢻⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠻⣻⠟⠀⠀⠀⠀⠀\n";
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⢻⣿⣦⣴⣤⡿⢿⣋⣿⠇⠀⠀⠀⠀⠀⠈⠙⠲⡄⠀⠀⢸⠀⠀⠀⣰⠃⠀⠉⠉⠀⣾⡛⠁⠀⠀⠀⠀⠀⠀⠀⠀⣰⢦⣦⣤⣤⣴⡏⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠉⠀⠁⠀⠈⣯⡀⡀⡀⢀⠀⣠⡄⣼⠶⠾⠃⠀⠀⡞⠀⠀⠀⢹⠀⠀⠀⠀⠀⠈⢷⢦⣤⣄⠀⠀⠀⢠⣤⣴⠟⠀⠀⠉⠀⠈⠀⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠓⠛⠛⠛⠋⠛⠋⠀⠀⠀⠀⠀⡇⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠈⠀⠹⠷⣾⡍⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣷⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡇⠀⠀⠸⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡇⠀⠀⠀⢧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠏⠀⠀⠀⠀⢈⡻⠆\n";

    ofs.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
    try{
        AForm::execute(executor);
        CreateTree(this->target);
    }catch (std::exception &e)
    {
        std::cout << executor.getName() << "couldn't execute because" << e.what() << std::endl;
    }
}