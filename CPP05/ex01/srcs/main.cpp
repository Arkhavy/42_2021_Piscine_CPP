/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:54:51 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/16 07:44:09 by ljohnson         ###   ########lyon.fr   */
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

void	init_wrong_form(std::string const& name, unsigned int const& sign_req, unsigned int const& exec_req)
{
	Form	wrong_form(name, sign_req, exec_req);

	std::cout << wrong_form << std::endl;
}

int	main(void)
{
	Bureaucrat*	worker[3];
	Form*		paperwork[3];

	std::cout << FAINT << "--------------------------------------------------" << FWHITE << std::endl;
	for (int i = 0; i < 5; i++)
	{
		try
		{
			switch(i)
			{
				case 0:
					init_wrong_form("Woof", 0, 40); break ;
				case 1:
					init_wrong_form("Meow", 151, 40); break ;
				case 2:
					init_wrong_form("Moo", 40, 0); break ;
				case 3:
					init_wrong_form("Roar", 40, 151); break ;
				case 4:
					init_wrong_form("Oui", 0, 151); break ;
				default:
					print_err("Ouaf!");
			}
		}
		catch(std::exception& e) {print_err(e.what());}
	}
	std::cout << FAINT << "--------------------------------------------------" << FWHITE << std::endl;

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
			catch(std::exception& e) {print_err(e.what());}
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