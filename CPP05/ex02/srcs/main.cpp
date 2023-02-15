/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:31:04 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/15 17:12:16 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

void	print_err(char const* what)
{
	std::cerr << RED << BOLD;
	std::cerr << what;
	std::cerr << FWHITE << std::endl;
}

int	main(void)
{
	Bureaucrat*	worker[3];
	AForm*		paperwork[3];

	worker[0] = new Bureaucrat("Emperor", 1);
	worker[1] = new Bureaucrat("Jedi Padawan", 70);
	worker[2] = new Bureaucrat("Stormtrooper", 150);
	paperwork[0] = new PresidentialPardonForm("JarJar Binks");
	paperwork[1] = new RobotomyRequestForm("General Grievous");
	paperwork[2] = new ShrubberyCreationForm("Temple");

	for (int i = 0; i < 3; i++)
		std::cout << *worker[i];
	for (int i = 0; i < 3; i++)
		std::cout << *paperwork[i];

	std::cout << FAINT << "--------------------------------------------------" << FWHITE << std::endl;

	for (int i = 2; i >= 0; i--)
	{
		for (int j = 0; j <= 2; j++)
		{
			try {worker[i]->signForm(*paperwork[j]);}
			catch(std::exception& e) {print_err(e.what());}
			std::cout << *paperwork[j];
			try {worker[i]->executeForm(*paperwork[j]);}
			catch(std::exception& e) {print_err(e.what());}
			std::cout << FAINT << "-------------------------" << FWHITE << std::endl;
		}
		std::cout << FAINT << "-------------------------" << FWHITE << std::endl;
	}
	for (int i = 0; i < 3; i++)
	{
		delete worker[i];
		delete paperwork[i];
	}
	return (0);
}