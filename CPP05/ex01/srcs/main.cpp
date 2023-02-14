/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:54:51 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/14 18:21:27 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

void	print_err(char const* what)
{
	std::cerr << RED << BOLD;
	std::cerr << what;
	std::cerr << FWHITE << std::endl;
}

void	init_bureaucrat(std::string const& name, unsigned int const grade)
{
	Bureaucrat	worker(name, grade);

	std::cout << worker << std::endl;

	worker.increment_grade();
	std::cout << worker << std::endl;
	worker.decrement_grade();
	std::cout << worker << std::endl;
	worker.decrement_grade();
	std::cout << worker << std::endl;
}

int	main(void)
{
	for(int i = 0; i < 5; i++)
	{
		try
		{
			switch(i)
			{
				case 0:
					init_bureaucrat("Emperor", 1); break ;
				case 1:
					init_bureaucrat("Stormtrooper", 150); break ;
				case 2:
					init_bureaucrat("Jedi", 50); break ;
				case 3:
					init_bureaucrat("Leia", 0); break ;
				case 4:
					init_bureaucrat("JarJar", 151); break ;
				default:
					print_err("Ouaf!");
			}
		}
		catch(Bureaucrat::GradeTooHighException& e) {print_err(e.what());}
		catch(Bureaucrat::GradeTooLowException& e) {print_err(e.what());}
		catch(Form::GradeTooHighException& e) {print_err(e.what());}
		catch(Form::GradeTooLowException& e) {print_err(e.what());}
		std::cout << "--------------------------------------------------" << std::endl;
	}
	return (0);
}