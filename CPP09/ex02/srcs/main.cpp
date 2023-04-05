/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:06:20 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/05 15:55:10 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

void	init_sorter(PmergeMe& sorter, char** av)
{
	unsigned int	tmp = 0;

	for (size_t i = 1; av[i]; i++)
	{
		tmp = std::strtol(av[i], NULL, 10);
		if (tmp > INT_MAX || errno == ERANGE)
			throw OutOfRangeException();
		sorter.set_vct_val(tmp);
	}
	if (sorter.check_vct_duplicates())
		throw DuplicateFoundException();
	for (size_t i = 1; av[i]; i++)
		sorter.set_lst_val(std::strtol(av[i], NULL, 10));
}

void	check_user_input(std::string const program_name, char** av)
{
	size_t	i = 1;

	if (program_name != "./PmergeMe")
		throw InvalidProgramNameException();
	while (av[i])
	{
		size_t	j = 0;
		if (!av[i][j])
			throw InvalidArgumentException();
		while (av[i][j])
		{
			if (!isdigit(av[i][j]))
				throw InvalidArgumentException();
			j++;
		}
		i++;
	}
}

int	main(int ac, char** av)
{
	PmergeMe	sorter;

	if (ac == 1)
		return (ft_print_msg<int>(RED, "ERROR: Usage: ./PmergeMe <args ...>", 1));
	try
	{
		check_user_input(av[0], av);
		init_sorter(sorter, av);
		sorter.display_lst();
		sorter.display_vct();
		while (!sorter.check_sorting())
		{
			sorter.launch(0);
			sorter.launch(1);
		}
		sorter.display_lst();
		sorter.display_vct();
	}
	catch (std::exception& e) {return (ft_print_msg<int>(RED, e.what(), 1));}
	ft_print_msg<int>(GREEN, "Everything worked correctly wooo", 0);
	return (0);
}