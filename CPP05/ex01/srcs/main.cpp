/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:54:51 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/14 21:31:48 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <Form.hpp>

void	print_err(char const* what)
{
	std::cerr << RED << BOLD;
	std::cerr << what;
	std::cerr << FWHITE << std::endl;
}

int	main(void)
{
	Bureaucrat*	worker[3];
	Form*		paperwork[3];

	worker[0] = new Bureaucrat("Emperor", 1);
	worker[1] = new Bureaucrat("Jedi Padawan", 70);
	worker[2] = new Bureaucrat("Stormtrooper", 150);
	paperwork[0] = new Form("Execute_Order_66.pdf", 1, 150);
	paperwork[1] = new Form("Learn_To_Use_the_force.txt", 80, 60);
	paperwork[2] = new Form("How_To_Shoot_a_Jedi.mp4", 150, 100);

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
			catch(Bureaucrat::GradeTooHighException& e) {print_err(e.what());}
			catch(Bureaucrat::GradeTooLowException& e) {print_err(e.what());}
			catch(Bureaucrat::AlreadySignedException& e) {print_err(e.what());}
			catch(Form::GradeTooHighException& e) {print_err(e.what());}
			catch(Form::GradeTooLowException& e) {print_err(e.what());}
			catch(Form::AlreadySignedException& e) {print_err(e.what());}
		}
		for (int j = 0; j < 3; j++)
			std::cout << *paperwork[j];
		std::cout << FAINT << "-------------------------" << FWHITE << std::endl;
	}
	for (int i = 0; i < 3; i++)
	{
		delete worker[i];
		delete paperwork[i];
	}
	return (0);
}