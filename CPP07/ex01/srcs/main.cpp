/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:08:39 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/23 16:12:31 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iter.hpp>

void	space_to_X(char& c)
{
	if (c == ' ')
		c = 'X';
}

void	erase_char(char& c)
{
	if (c != ' ')
		c = '_';
}

void	plus_one(int& nb)
{
	nb += 1;
}

void	one_to_three(int& nb)
{
	if (nb == 1)
		nb = 3;
}

int	main(int ac, char** av)
{
	if (ac > 1)
	{
		unsigned int	str1len = strlen(av[1]);

		std::cout << "Before iter:	|" << CYAN << BOLD;
		std::cout << av[1];
		std::cout << FWHITE << "|" << std::endl;

		iter<char, unsigned int, void>(av[1], str1len, &space_to_X);

		std::cout << "After iter:	|" << GREEN << BOLD;
		std::cout << av[1];
		std::cout << FWHITE << "|" << std::endl;
	}

	std::cout << FAINT << "--------------------------------------------------" << FWHITE << std::endl;

	if (ac > 2)
	{
		unsigned int	str2len = strlen(av[2]);

		std::cout << "Before iter:	|" << CYAN << BOLD;
		std::cout << av[2];
		std::cout << FWHITE << "|" << std::endl;

		iter<char, unsigned int, void>(av[2], str2len, &erase_char);

		std::cout << "After iter:	|" << GREEN << BOLD;
		std::cout << av[2];
		std::cout << FWHITE << "|" << std::endl;
	}

	std::cout << FAINT << "--------------------------------------------------" << FWHITE << std::endl;

	int	lst_int1[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

	std::cout << "Before iter:	|" << CYAN << BOLD;
	for (int i = 0; i < 10; i++)
		std::cout << " " << lst_int1[i] << " ";
	std::cout << FWHITE << "|" << std::endl;

	iter<int, unsigned int, void>(lst_int1, 10, &plus_one);

	std::cout << "After iter:	|" << GREEN << BOLD;
	for (int i = 0; i < 10; i++)
		std::cout << " " << lst_int1[i] << " ";
	std::cout << FWHITE << "|" << std::endl;

	std::cout << FAINT << "--------------------------------------------------" << FWHITE << std::endl;

	int	lst_int2[11] = {1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1};

	std::cout << "Before iter:	|" << CYAN << BOLD;
	for (int i = 0; i < 11; i++)
		std::cout << " " << lst_int2[i] << " ";
	std::cout << FWHITE << "|" << std::endl;

	iter<int, unsigned int, void>(lst_int2, 11, &one_to_three);

	std::cout << "After iter:	|" << GREEN << BOLD;
	for (int i = 0; i < 11; i++)
		std::cout << " " << lst_int2[i] << " ";
	std::cout << FWHITE << "|" << std::endl;

	std::cout << FAINT << "--------------------------------------------------" << FWHITE << std::endl;
	return (0);
}