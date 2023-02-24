/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:31:54 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/24 13:40:24 by ljohnson         ###   ########lyon.fr   */
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
			default: break ;
		}
	}
	else if (str == "-inf" || str == "-inff")
	{
		switch(type)
		{
			case 0: throw IntImpossibleException();
			case 1: throw FloatNegInfException();
			case 2: throw DoubleNegInfException();
			default: break ;
		}
	}
	switch(type)
	{
		case 0: throw IntImpossibleException(); break ;
		case 1: throw FloatNaNException(); break ;
		case 2: throw DoubleNaNException(); break ;
		default: throw NbNotValidException();
	}
}

bool	ft_check_point(std::string const& str)
{
	bool			point = false;
	unsigned int	i = 0;

	while (i < static_cast<unsigned int>(str.length()))
	{
		if (point && (str[i] != '0' && str[i] != 'f'))
			return (true);
		if (!point && str[i] == '.')
			point = true;
		i++;
	}
	if (point && i != str.length())
		return (true);
	return (false);
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
				break ;
			if (str[a] == '.')
				point = true;
			a++;
		}
		if (a == len || (a == (len - 1) && str[a] == 'f'))
			return ;
	}
	if (type != 3)
		ft_check_literals(str, type);
	else if (type == 3)
		throw CharImpossibleException();
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

void	ft_char_handler(std::string const& str)
{
	if (ft_is_char(str))
	{
		if (ft_is_displayable(str[0]))
			std::cout << "char: '" << static_cast<char>(str[0]) << "'" << std::endl;
		else
			throw CharNonDisplayableException();
	}
	else
	{
		ft_check_nb_validity(str, 3);
		int	val = std::strtol(str.data(), NULL, 10);
		if (val >= 0 && val <= 127)
		{
			if (val >= 32 && val <= 126)
				std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
			else
				throw CharNonDisplayableException();
		}
		else
			throw CharImpossibleException();
	}
}

void	ft_int_handler(std::string const& str)
{
	ft_check_nb_validity(str, 0);
	int	val = std::strtol(str.data(), NULL, 10);
	if (errno == ERANGE)
		throw IntOverflowException();
	std::cout << "int: " << val << std::endl;
}

void	ft_float_handler(std::string const& str)
{
	ft_check_nb_validity(str, 1);
	float	val = std::strtof(str.data(), NULL);
	if (val > FLT_MAX || val < (-FLT_MAX - 1))
		throw FloatOverflowException();
	if (ft_check_point(str))
		std::cout << "float: " << val << "f" << std::endl;
	else
		std::cout << "float: " << val << ".0f" << std::endl;
}

void	ft_double_handler(std::string const& str)
{
	ft_check_nb_validity(str, 2);
	double	val = std::strtod(str.data(), NULL);
	if (val > DBL_MAX || val < (-DBL_MAX - 1))
		throw DoubleOverflowException();
	if (ft_check_point(str))
		std::cout << "double: " << val << std::endl;
	else
		std::cout << "double: " << val << ".0" << std::endl;
}

/* ************************************************************************** */
/* Main */
/* ************************************************************************** */
int	main(int ac, char** av)
{
	std::string	str;;

	if (ac != 2)
		return (print_err("ERROR: Usage: ./convert <arg>"));
	str = av[1];
	if (str.empty())
		return (print_err("ERROR: argument is empty !"));

	//char
	try {ft_char_handler(str);}
	catch (std::exception& e) {print_err(e.what());}

	//int
	try{ft_int_handler(str);}
	catch (IsCharException& e) {std::cout << "int: " << static_cast<int>(str[0]) << std::endl;}
	catch (std::exception& e) {print_err(e.what());}

	//float
	try{ft_float_handler(str);}
	catch (IsCharException& e) {std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;}
	catch (std::exception& e) {print_err(e.what());}

	//double
	try{ft_double_handler(str);}
	catch (IsCharException& e) {std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;}
	catch (std::exception& e) {print_err(e.what());}
	return (0);
}
