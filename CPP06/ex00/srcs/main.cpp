/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:31:54 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/22 13:57:36 by ljohnson         ###   ########lyon.fr   */
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

void	ft_check_literals(std::string const& str, unsigned int const type)
{
	if (str == "+inf" || str == "+inff")
	{
		switch(type)
		{
			case 0: throw IntImpossibleException();
			case 1: throw FloatPosInfException();
			case 2: throw DoublePosInfException();
			default: throw NbNotValidException();
		}
	}
	else if (str == "-inf" || str == "-inff")
	{
		switch(type)
		{
			case 0: throw IntImpossibleException();
			case 1: throw FloatNegInfException();
			case 2: throw DoubleNegInfException();
			default: throw NbNotValidException();
		}
	}
	else if (str == "nan" || str == "nanf")
	{
		switch(type)
		{
			case 0: throw IntImpossibleException();
			case 1: throw FloatNaNException();
			case 2: throw DoubleNaNException();
			default: throw NbNotValidException();
		}
	}
}

void	ft_check_nb_validity(std::string const& str, unsigned int const type)
{
	unsigned int	len = str.length();
	unsigned int	a = 0;
	bool			point = false;

	if (len == 1 && !ft_is_digit(str[0]))
		throw IsCharException();
	else if (len >= 1)
	{
		if (str[0] == '-' || str[0] == '+')
			a++;
		while (ft_is_digit(str[a]) || str[a] == '.')
		{
			if (point && str[a] == '.')
				throw NbNotValidException();
			if (str[a] == '.')
				point = true;
			a++;
		}
		if (a == len || (a == (len - 1) && str[a] == 'f'))
			return ;
	}
	ft_check_literals(str, type);
	throw NbNotValidException();
}

bool	ft_is_char(std::string const& str)
{
	if (str.length() > 1)
		return (false);
	if (ft_is_digit(str[0]))
		throw CharNonDisplayableException();
	return (true);
}

/* ************************************************************************** */
/* Main */
/* ************************************************************************** */
int	main(int ac, char** av)
{
	if (ac != 2)
		return (print_err("ERROR: Usage: ./convert <arg>"));

	std::string	str = av[1];
	if (str.empty())
		return (print_err("ERROR: argument is empty !"));
	//char
	try
	{
		if (ft_is_char(str))
		{
			if (ft_is_displayable(str[0]))
				std::cout << "char: " << static_cast<char>(str[0]) << std::endl;
			else
				throw CharNonDisplayableException();
		}
		if (strtol(str, NULL, 10) >= 0 && strtol(str, NULL, 10) <= 127)
		{
			if (strtol(str, NULL, 10) >= 32 && strtol(str, NULL, 10) <= 126)
				std::cout << "char: " << static_cast<char>(strtol(str, NULL, 10)) << std::endl;
		}
		else
			throw CharImpossibleException();
	}
	catch (std::exception& e) {print_err(e.what());}
	//int
	try
	{
		ft_check_nb_validity(str);
		std::cout << "int: " << strtol(str, NULL, 10) << std::endl;
	}
	catch (IsCharException& e) {std::cout << "int: " << static_cast<int>(str[0]) << std::endl;}
	catch (std::exception& e) {print_err(e.what());}
	//float
	try
	{
		ft_check_nb_validity(str);
		std::cout << "float: " << static_cast<float>(str) << "f" << std::endl;
	}
	catch (IsCharException& e) {std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;}
	catch (std::exception& e) {print_err(e.what());}
	//double
	try
	{
		ft_check_nb_validity(str);
		std::cout << "double: " << static_cast<double>(str) << std::endl;
	}
	catch (IsCharException& e) {std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;}
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