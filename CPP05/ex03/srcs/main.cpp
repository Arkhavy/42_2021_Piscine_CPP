/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:45:26 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/16 09:38:43 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Intern.hpp>

void	print_err(char const* what)
{
	std::cerr << RED << BOLD;
	std::cerr << what;
	std::cerr << FWHITE << std::endl;
}

AForm*	init_intern_form(std::string const& form_name, std::string const& target) 
{
	Intern	woof;

	return (woof.makeForm(form_name, target));
}

int	main(void)
{
	Bureaucrat*	workers[3];
	AForm*		tmp_form = NULL;

	workers[0] = new Bureaucrat("Dog", 150);
	workers[1] = new Bureaucrat("Some random dude", 50);
	workers[2] = new Bureaucrat("Myself", 1);
	for (int i = 0; i < 4; i++)
	{
		try
		{
			switch(i)
			{
				case 0:
					tmp_form = init_intern_form("wrong form", "ouaf"); break ;
				case 1:
					tmp_form = init_intern_form("presidential pardon", "A random guy"); break ;
				case 2:
					tmp_form = init_intern_form("robotomy request", "Soon to be robot"); break ;
				case 3:
					tmp_form = init_intern_form("shrubbery creation", "Tree house"); break ;
				default:
					print_err("woof"); break ;
			}
		}
		catch (std::exception& e) {print_err(e.what());}
		if (tmp_form)
		{
			for (int j = 0; j < 3; j++)
			{
				try {workers[j]->signForm(*tmp_form);}
				catch (std::exception& e) {print_err(e.what());}
				for (int l = 0; l < 3; l++)
				{
					try {workers[l]->executeForm(*tmp_form);}
					catch (std::exception& e) {print_err(e.what());}
				}
			}
		}
		delete tmp_form;
	}
	for (int i = 0; i < 3; i++)
		delete workers[i];
	return (0);
}