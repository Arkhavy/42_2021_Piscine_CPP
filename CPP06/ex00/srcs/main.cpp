/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:31:54 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/21 12:02:29 by ljohnson         ###   ########lyon.fr   */
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

bool	ft_isdigit(char value) {return (value >= '0' && value <= '9');}

int	ft_power(int const nb, int const power)
{
	int	result = 1;

	if ((nb == 0 && power != 0) || power < 0)
		return (0);
	if ((nb < 0 && power == 0) || (power == 0))
		return (1);
	else
	{
		for (; power > 0; power--)
			result = result * nb;
	}
	return (result);
}

unsigned int	ft_sign_check(char const& str, int& negative)
{
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			negative = -1;
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/* Int Conversion */
/* ************************************************************************** */
//Ajouter condition overflow int
int	ft_add_str_to_int(char const& str, int& a)
{
	int	result = 0;

	while (ft_isdigit(str[a]))
	{
		result = result * 10 + static_cast<int>(str[a] - '0');
		a++;
	}
	return (result);
}

int	ft_atoi(char const& str)
{
	int		negative = 1;
	int		a = ft_sign_check(str, negative);
	long	result = ft_add_str_to_int(str, a);

	if (result > LONG_MAX && negative == -1)
		return (0);
	else if (result > LONG_MAX && negative == 1)
		return (-1);
	return (static_cast<int>(result * negative));
}

/* ************************************************************************** */
/* Float Conversion */
/* ************************************************************************** */
//Ajouter condition overflow float
float	ft_add_str_to_float(char const& str, int& a)
{
	float	result = 0;

	while (ft_isdigit(str[a]))
	{
		result = result * 10 + static_cast<float>(str[a] - '0');
		a++;
	}
	return (result);
}

float	ft_atof(char const& str)
{
	float	decimal = 0;
	int		negative = 1;
	int		point = 1;
	int		a = ft_atoi_check(str, negative);
	int		result = ft_add_str_to_int(str, a);

	if (str[a] == '.')
	{
		a++;
		point = a;
		decimal = ft_add_str_to_int(str, a);
		point = a - point;
	}
	return (static_cast<float>((result + (decimal / ft_power(10, point))) * negative));
}

/* ************************************************************************** */
/* Double Conversion */
/* ************************************************************************** */
//Ajouter condition overflow double
double	ft_add_str_to_double(char const& str, int& a)
{
	double	result = 0;

	while (ft_isdigit(str[a]))
	{
		result = result * 10 + static_cast<double>(str[a] - '0');
		a++;
	}
	return (result);
}

float	ft_atod(char const& str)
{
	double	decimal = 0;
	int		negative = 1;
	int		point = 1;
	int		a = ft_atoi_check(str, negative);
	int		result = ft_add_str_to_int(str, a);

	if (str[a] == '.')
	{
		a++;
		point = a;
		decimal = ft_add_str_to_int(str, a);
		point = a - point;
	}
	return (static_cast<double>((result + (decimal / ft_power(10, point))) * negative));
}

/* ************************************************************************** */
/* Main */
/* ************************************************************************** */

int	main(int ac, char** av)
{
	if (ac != 2)
		return (print_err("ERROR: Usage: ./convert <arg>"));
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