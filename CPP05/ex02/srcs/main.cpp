/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:31:04 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/15 15:35:16 by ljohnson         ###   ########lyon.fr   */
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
	RobotomyRequestForm		ouaf("ceci est une cible");
	Bureaucrat				ouef1("1", 140);
	Bureaucrat				ouef2("2", 40);
	Bureaucrat				ouef3("3", 1);


	std::cout << ouaf << std::endl;
	std::cout << ouef1 << std::endl;
	std::cout << ouef2 << std::endl;
	std::cout << ouef3 << std::endl;


	try {ouef1.signForm(ouaf);}
	catch(std::exception& e) {print_err(e.what());}

	std::cout << ouaf << std::endl;

	try {ouef1.executeForm(ouaf);}
	catch(std::exception& e) {print_err(e.what());}

	try {ouef2.executeForm(ouaf);}
	catch(std::exception& e) {print_err(e.what());}

	try {ouef3.executeForm(ouaf);}
	catch(std::exception& e) {print_err(e.what());}

	std::cout << std::endl << "--------------------------------------------------" << std::endl << std::endl;
	std::cout << std::endl << "--------------------------------------------------" << std::endl << std::endl;

	try {ouef2.signForm(ouaf);}
	catch(std::exception& e) {print_err(e.what());}

	std::cout << ouaf << std::endl;

	try {ouef1.executeForm(ouaf);}
	catch(std::exception& e) {print_err(e.what());}

	try {ouef2.executeForm(ouaf);}
	catch(std::exception& e) {print_err(e.what());}

	try {ouef3.executeForm(ouaf);}
	catch(std::exception& e) {print_err(e.what());}

	std::cout << std::endl << "--------------------------------------------------" << std::endl << std::endl;
	std::cout << std::endl << "--------------------------------------------------" << std::endl << std::endl;

	try {ouef3.signForm(ouaf);}
	catch(std::exception& e) {print_err(e.what());}

	std::cout << ouaf << std::endl;

	try {ouef1.executeForm(ouaf);}
	catch(std::exception& e) {print_err(e.what());}

	try {ouef2.executeForm(ouaf);}
	catch(std::exception& e) {print_err(e.what());}

	try {ouef3.executeForm(ouaf);}
	catch(std::exception& e) {print_err(e.what());}

	return (0);
}