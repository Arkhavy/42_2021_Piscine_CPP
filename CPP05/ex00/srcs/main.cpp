/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:54:51 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/14 15:15:48 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

void	print_err(char const* what)
{
	std::cerr << RED << BOLD;
	std::cerr << what;
	std::cerr << FWHITE << std::endl;
}

int	main(void)
{
	try {Bureaucrat	b_high("Emperor", 1);}
	catch (Bureaucrat::GradeTooHighException& e) {print_err(e.what());}
	catch (Bureaucrat::GradeTooLowException& e) {print_err(e.what());}

	std::cout << std::endl;

	try {Bureaucrat	b_low("Stormtrooper", 150);}
	catch (Bureaucrat::GradeTooHighException& e) {print_err(e.what());}
	catch (Bureaucrat::GradeTooLowException& e) {print_err(e.what());}

	std::cout << std::endl;

	try {Bureaucrat	b_middle("Jedi", 50);}
	catch (Bureaucrat::GradeTooHighException& e) {print_err(e.what());}
	catch (Bureaucrat::GradeTooLowException& e) {print_err(e.what());}

	std::cout << std::endl;

	try {Bureaucrat	b_err_high("Leia", 0);}
	catch (Bureaucrat::GradeTooHighException& e) {print_err(e.what());}
	catch (Bureaucrat::GradeTooLowException& e) {print_err(e.what());}

	std::cout << std::endl;

	try {Bureaucrat	b_err_low("JarJar", 151);}
	catch (Bureaucrat::GradeTooHighException& e) {print_err(e.what());}
	catch (Bureaucrat::GradeTooLowException& e) {print_err(e.what());}


		// std::cout << b_high << std::endl;
		// std::cout << b_low << std::endl;
		// std::cout << b_middle << std::endl;
	// catch (Bureaucrat::GradeTooHighException& e) {std::cerr << e.what() << std::endl;}
	// catch (Bureaucrat::GradeTooLowException& e) {std::cerr << e.what() << std::endl;}


	// std::cout << std::endl << "--------------------------------------------------" << std::endl;

	// try
	// {
	// 	b_high.increment_grade();
	// 	std::cout << b_high << std::endl;
	// 	b_high.decrement_grade();
	// 	std::cout << b_high << std::endl;
	// }

	// std::cout << std::endl << "--------------------------------------------------" << std::endl;

	// try
	// {
	// 	b_low.decrement_grade();
	// 	std::cout << b_low << std::endl;
	// 	b_low.increment_grade();
	// 	std::cout << b_low << std::endl;
	// }

	// std::cout << std::endl << "--------------------------------------------------" << std::endl;

	// try
	// {
	// 	b_middle.increment_grade();
	// 	std::cout << b_middle << std::endl;
	// 	b_middle.decrement_grade();
	// 	std::cout << b_middle << std::endl;
	// }
	// catch

	return (0);
}