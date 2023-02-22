/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:31:54 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/22 12:12:03 by ljohnson         ###   ########lyon.fr   */
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

long	ft_int_convert(std::string const& str)
{
	if (str == "+inf" || str == "+inff")
		return (strtol("+inf", NULL, 10));
	else if (str == "-inf" || str == "-inff")
		return (strtol("-inf", NULL, 10));
	else if (str == "nan" || str == "nanf")
		return (strtol("nan", NULL, 10));
	return (strtol(str.data(), NULL, 10));
}

float	ft_float_convert(std::string const& str)
{
	if (str == "+inf" || str == "+inff")
		return (strtof("+inff", NULL));
	else if (str == "-inf" || str == "-inff")
		return (strtof("-inff", NULL));
	else if (str == "nan" || str == "nanf")
		return (strtof("nanf", NULL));
	return (strtof(str.data(), NULL));
}

double	ft_double_convert(std::string const& str)
{
	if (str == "+inf" || str == "+inff")
		return (strtod("+inf", NULL));
	else if (str == "-inf" || str == "-inff")
		return (strtod("-inf", NULL));
	else if (str == "nan" || str == "nanf")
		return (strtod("nan", NULL));
	return (strtod(str.data(), NULL));
}

bool	ft_basic_nb_check(std::string const& str)
{
	unsigned int	a = 0;
	unsigned int	len = str.length();
	bool 			point = false;

	if (len == 0 || str.empty())
		throw EmptyStrException();
	else if (len == 1 && !ft_is_digit(str[0]))
		return (false);
	if (len >= 1)
	{
		if (str[0] == '-' || str[0] == '+')
			a++;
		while (ft_is_digit(str[a]) || str[a] == '.')
		{
			if (point && str[a] == '.')
				return (false);
			if (str[a] == '.')
				point = true;
			a++;
		}
	}
	if (a == len || (a == (len - 1) && str[a] == 'f'))
		return (true);
	return (false);
}

bool	ft_is_char(std::string const& str)
{
	if (str.empty())
		throw EmptyStrException();
	if (str.length() > 1)
		return (false);
	return (true);
}

bool	ft_is_int(std::string const& str)
{
	unsigned int	len = str.length();
	unsigned int	i = 0;

	if (ft_basic_nb_check(str))
	{
		if (len > 1 && str[len - 1] == 'f')
			return (false);
		while (ft_is_digit(str[i]) || i < len)
			i++;
		if (i < len)
			return (false);
		return (true);
	}
	throw IntImpossibleException();
	return (false);
}

bool	ft_is_float(std::string const& str)
{
	unsigned int	len = str.length();

	if (ft_basic_nb_check(str))
	{
		if (str[len - 1] == 'f')
			return (true);
	}
	throw FloatNaNException();
	return (false);
}

bool	ft_is_double(std::string const& str)
{
	unsigned int	len = str.length();

	if (ft_basic_nb_check(str))
	{
		if (str[len - 1] == 'f')
			return (false);
		return (true);
	}
	throw DoubleNaNException();
	return (false);
}

// int result = result * 10 + static_cast<int>(str[a] + '0');
/* ************************************************************************** */
/* Main */
/* ************************************************************************** */

int	main(int ac, char** av)
{
	std::string	str = av[1];
	if (ac != 2)
		return (print_err("ERROR: Usage: ./convert <arg>"));
	//char
	try
	{
		if (ft_is_char(str))
		{
			if (ft_is_displayable(str[0]))
			{
				std::cout << "char: " << str[0] << std::endl;
			}
			else
				throw CharNonDisplayableException();
		}
		else
			throw CharImpossibleException();
	}
	catch (std::exception& e) {print_err(e.what());}
	//int
	try
	{
		if (ft_is_int(str))
			std::cout << "int: " << ft_int_convert(str) << std::endl;
		else
			std::cout << "int: " << static_cast<int>(ft_int_convert(str)) << std::endl;
	}
	catch (std::exception& e) {print_err(e.what());}
	//float
	try
	{
		if (ft_is_float(str))
			std::cout << "float: " << ft_float_convert(str) << std::endl;
		else
			std::cout << "float: " << static_cast<float>(ft_float_convert(str)) << std::endl;
	}
	catch (std::exception& e) {print_err(e.what());}
	//double
	try
	{
		if (ft_is_double(str))
			std::cout << "double: " << ft_double_convert(str) << std::endl;
		else
			std::cout << "double: " << static_cast<double>(ft_double_convert(str)) << std::endl;
	}
	catch (std::exception& e) {print_err(e.what());}
	return (0);
}

/*
Erreurs actuelles :
FLOAT n'affiche pas son f
FLOAT et DOUBLE n'ont pas de .0 s'il n'y a pas de décimale
CHAR n'affiche pas le caractère si on donne sa valeur ASCII
int float double n'affichent pas de valeur ASCII si un char est donné
*/



/*
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