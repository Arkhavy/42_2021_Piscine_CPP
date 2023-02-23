/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:06:37 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/23 10:16:07 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <A.hpp>
#include <B.hpp>
#include <C.hpp>

void	identify(Base* p)
{
	A*	aptr = dynamic_cast<A*>(p);
	if (aptr == NULL)
	{
		B*	bptr = dynamic_cast<B*>(p);
		if (bptr == NULL)
		{
			C*	cptr = dynamic_cast<C*>(p);
			if (cptr == NULL)
			{
				std::cerr << RED << BOLD;
				std::cerr << "Base* p does not correspond to any type checked.";
				std::cerr << FWHITE << std::endl;
				return ;
			}
			else
			{
				(void)cptr;
				std::cout << "Identified type of Base* p is: ";
				std::cout << CYAN << BOLD << "C";
				std::cout << FWHITE << std::endl;
				return ;
			}
		}
		else
		{
			(void)bptr;
			std::cout << "Identified type of Base* p is: ";
			std::cout << CYAN << BOLD << "B";
			std::cout << FWHITE << std::endl;
			return ;
		}
	}
	else
	{
		(void)aptr;
		std::cout << "Identified type of Base* p is: ";
		std::cout << CYAN << BOLD << "A";
		std::cout << FWHITE << std::endl;
		return ;
	}
}

void	identify(Base& p)
{
	try 
	{
		A&	aref = dynamic_cast<A&>(p);
		std::cout << "Identified type of Base& p is: ";
		std::cout << GREEN << BOLD << "A";
		std::cout << FWHITE << std::endl;
		(void)aref;
	}
	catch (std::exception& e)
	{
		try 
		{
			B&	bref = dynamic_cast<B&>(p);
			std::cout << "Identified type of Base& p is: ";
			std::cout << GREEN << BOLD << "B";
			std::cout << FWHITE << std::endl;
			(void)bref;
		}
		catch (std::exception& e)
		{
			try 
			{
				C&	cref = dynamic_cast<C&>(p);
				std::cout << "Identified type of Base& p is: ";
				std::cout << GREEN << BOLD << "C";
				std::cout << FWHITE << std::endl;
				(void)cref;
			}
			catch (std::exception& e)
			{
				std::cerr << RED << BOLD;
				std::cerr << "Base& p does not correspond to any type checked.";
				std::cerr << FWHITE << std::endl;
			}
		}
	}
}

Base*	generate()
{
	static unsigned int	count = 0;

	count++;
	std::cout << "Class type generated is: ";
	if ((count % 3) == 0)
	{
		std::cout << YELLOW << BOLD << "A";
		std::cout << FWHITE << std::endl;
		return (new A());
	}
	else if ((count % 3) == 1)
	{
		std::cout << YELLOW << BOLD << "B";
		std::cout << FWHITE << std::endl;
		return (new B());
	}
	else if ((count % 3) == 2)
	{
		std::cout << YELLOW << BOLD << "C";
		std::cout << FWHITE << std::endl;
		return (new C());
	}
	std::cout << RED << BOLD << "NULL";
	std::cout << FWHITE << std::endl;
	return (NULL);
}

int	main(void)
{
	for (int i = 0; i < 15; i++)
	{
		std::cout << "--------------------------------------------------" << std::endl;
		Base*	ptr = generate();
		identify(ptr);
		Base&	ref = *ptr;
		identify(ref);
		delete ptr;
	}
	return (0);
}