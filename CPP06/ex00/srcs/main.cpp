/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:31:54 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/21 19:13:56 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Convert.hpp>

/* ************************************************************************** */
/* Main Functions */
/* ************************************************************************** */

int	print_err(char const* what)
{
	std::cerr << RED << BOLD;
	std::cerr << what;
	std::cerr << FWHITE << std::endl;
	return (1);
}

bool	ft_is_digit(char value) {return (value >= '0' && value <= '9');}

bool	ft_is_displayable(char value) {return (value >= 32 && value <= 126);}

double	ft_is_double_literal(std::string const& str)
{
	if (str == "+inf" || str == "+inff")
		return (strtod("+inf", NULL));
	else if (str == "-inf" || str == "-inff")
		return (strtod("-inf", NULL));
	else if (str == "nan" || str "nanf")
		return (strtod("nan", NULL));
	return (false);
}

bool	ft_basic_check(std::string const& str)
{
	unsigned int	a = 0;
	unsigned int	len = str.length();

	if (len == 1 && (str[0] == '-' || str[0] == '+'))
		return (false);
	if (len > 1)
	{
		if (str[0] == '-' || str[0] == '+')
			a++;
		while (ft_is_digit(str[a]))
			a++;
	}
	if (a == len)
		return (true);
	return (false);
}

bool	ft_is_char(std::string const& str)
{
	if (str.empty())
		return (false);
	if (str.length() > 1)
		return (false);
	if (str[0] >= 0 && str[0] <= 127)
		return (true);
	return (false);
}

bool	ft_is_int(std::string const& str)
{
	if (!ft_basic_check(str))
		return (false);
}

bool	ft_is_float(std::string const& str)
{
	if (!ft_basic_check(str))
		return (false);
}

bool	ft_is_double(std::string const& str)
{
	if (!ft_basic_check(str))
		return (false);
}

// int result = result * 10 + static_cast<int>(str[a] + '0');
/* ************************************************************************** */
/* Main */
/* ************************************************************************** */

int	main(int ac, char** av)
{
	// std::string	tmp = av[1];
	if (ac != 2)
		return (print_err("ERROR: Usage: ./convert <arg>"));
	std::cout << "ouaf: " << std::setprecision(8) << atof(av[1]) << std::endl;
	return (0);
}

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