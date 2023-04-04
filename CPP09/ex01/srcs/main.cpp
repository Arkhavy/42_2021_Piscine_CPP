/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:20:40 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/04 15:19:40 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

/* ************************************************************************** */
/* MODULE : CHECK USER INPUT */
/* ************************************************************************** */
bool	is_symbol(char c) {return (c == '+' || c == '-' || c == '/' || c == '*');}

bool	is_input_valid(std::string const& input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != ' ' && !is_symbol(input[i]))
			return (false);
	}
	return (true);
}

void	check_user_input(std::string const& program_name, std::string const& input)
{
	if (program_name != "./RPN")
		throw InvalidProgramNameException();
	if (input.empty() || input.length() == 0)
		throw InvalidArgumentException();
	if (!is_input_valid(input))
		throw InvalidArgumentException();
}

/* ************************************************************************** */
/* MAIN */
/* ************************************************************************** */
int	main(int ac, char** av)
{
	RPN	rpn;

	if (ac != 2)
		return (ft_print_msg<int>(RED, "ERROR: Usage: ./RPN <Inverted Polish mathematical expression>", 1));
	try
	{
		check_user_input(av[0], av[1]);
		rpn.operation(av[1]);
	}
	catch (std::exception& e) {return (ft_print_msg<int>(RED, e.what(), 1));}
	std::cout << rpn.get_front() << std::endl;
	// std::cout << rpn << std::endl;
	// ft_print_msg(GREEN, "Everything worked correctly woo", 1);
	return (0);
}