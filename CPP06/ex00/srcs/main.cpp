/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:31:54 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/20 19:21:59 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Convert.hpp>

int	print_err(char const* what)
{
	std::cerr << RED << BOLD;
	std::cerr << what;
	std::cerr << FWHITE << std::endl;
	return (1);
}

bool	ft_isdigit(char value)
{
	if (value < '0' && value > '9')
		return (false);
	return (true);
}

int	main(int ac, char** av)
{
	if (ac != 2)
		return (print_err("ERROR: Usage: ./convert <arg>"));
	try
	{
		int	conv_int = static_cast<int>(std::atoi(av[1]));
		if (static_cast<int>(std::atoi(av[1]) != conv_int))
			throw IntOverflowException();
		std::cout << "int: " << conv_int << std::endl;
	}
	catch (std::exception& e) {print_err(e.what());}
	return (0);
}

//NEED ATOI AND ATOF WITH FOLLOWING CONDITION TO AVOID OVERFLOWS
//C++ VERSION WILL BE FUN LOLOLOL
//WILL BE A BRUTAL ONE
// Will num*10 + digit overflow?
// if ((num >= INT_MAX/10) && ((num > INT_MAX/10) || (digit > INT_MAX%10)))




// if (char_valid)
// 	std::cout << "char: " << static_cast<char>var << std::endl;
// else if (not)
// 	std::cout << "char:"
// std::cout << "int: " << static_cast<int>var << std::endl;

// error cases :
// global : no arg | empty string
// char : non displayable | impossible
// int : overflow | impossible
// float : overflow | nanf
// double : overflow | nan

/*
check all characters
	if (!isdigit(val[0]))
	{
		if length == 1
		{
			get ascii value
			display char if (32 <= val <= 126), else non displayable
			convert for int
			convert for float
			convert for double
			return
		}
		else
		{
			char impossible
			int impossible
			float nanf
			double nan
		}
	}
	else
	{
		check all char
			if all isdigit -> OK
			if only last is f -> OK
			can be a . somewhere
			can be a - at the start but only one
			can be a + at the start but only one
			can be a - and . but need numbers in between and after .
			can be a + and . but need numbers in between and after .
			if - and + or any other char -> error case 2 for all
			if -inff -inf +inff +inf nanf nan -> error case 2 for all
		if 0 <= val <= 127
			display char if (32 <= val <= 126), else non displayable
		else
			char impossible
		check limits INTMAX INTMIN FLOATMAX FLOATMIN DOUBLEMAX DOUBLEMIN
		convert and display in consequence
		string operations ? do we really need to atoi ? are cast enough ?
	}

./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
*/

/*
bool < char < short int < int < unsigned int < long < unsigned < long long < float < double < long double
char < int < float < double
*/