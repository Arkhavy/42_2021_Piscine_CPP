/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 07:56:54 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/28 09:35:22 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>

void	ft_print_err(std::string const& str)
{
	std::cerr << RED << BOLD;
	std::cerr << str;
	std::cerr << FWHITE << std::endl;
}

int	main(void)
{
	/* ************************************************************************** */
	/* STD STRING OK TEST */
	/* ************************************************************************** */
	std::cout << CYAN << BOLD << "std::string OK Test" << FWHITE << std::endl;
	std::string	str = "ouaf ouaf ouaf";
	int	res = -1;
	try
	{
		res = easyfind(str, 'a');
		std::cout << "easyfind string: " << GREEN << BOLD;
		std::cout << static_cast<char>(res);
		std::cout << FWHITE << std::endl;
	}
	catch (std::exception& e) {ft_print_err(e.what());}

	std::cout << FAINT << "\n----------\n" << FWHITE << std::endl;
	/* ************************************************************************** */
	/* STD STRING KO TEST */
	/* ************************************************************************** */
	std::cout << CYAN << BOLD << "std::string KO Test" << FWHITE << std::endl;
	try  {res = easyfind(str, 'x');}
	catch (std::exception& e) {ft_print_err(e.what());}

	std::cout << FAINT << "\n----------\n" << FWHITE << std::endl;
	/* ************************************************************************** */
	/* STD VECTOR INT OK TEST */
	/* ************************************************************************** */
	std::cout << CYAN << BOLD << "std::vector<int> OK test" << FWHITE << std::endl;
	std::vector<int>	haystack;
	srand(time(NULL));
	res = rand();
	for (int i = 0; i < 10; i++)
		haystack.push_back(rand());
	haystack.push_back(res);
	try
	{
		res = easyfind(haystack, res);
		std::cout << "easyfind vector<int>: " << GREEN << BOLD;
		std::cout << res;
		std::cout << FWHITE << std::endl;
	}
	catch (std::exception& e) {ft_print_err(e.what());}

	std::cout << FAINT << "\n----------\n" << FWHITE << std::endl;
	/* ************************************************************************** */
	/* STD VECTOR INT KO TEST */
	/* ************************************************************************** */
	std::cout << CYAN << BOLD << "std::vector<int> KO test" << FWHITE << std::endl;
	res = -1;
	try {res = easyfind(haystack, res);}
	catch (std::exception& e) {ft_print_err(e.what());}
	return (0);
}
