/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:20:02 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/22 12:05:14 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <climits>
#include <cfloat>
#include <cstdlib>

#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define FWHITE "\033[0m"

/* ************************************************************************** */
/* Char Exceptions */
/* ************************************************************************** */
class	CharImpossibleException : public std::exception
{
	public:
		virtual char const* what() const throw();
};

class	CharNonDisplayableException : public std::exception
{
	public:
		virtual char const* what() const throw();
};

/* ************************************************************************** */
/* Int Exceptions */
/* ************************************************************************** */
class	IntImpossibleException : public std::exception
{
	public:
		virtual char const* what() const throw();
};

/* ************************************************************************** */
/* Float Exceptions */
/* ************************************************************************** */
class	FloatNaNException : public std::exception
{
	public:
		virtual char const* what() const throw();
};

/* ************************************************************************** */
/* Double Exceptions */
/* ************************************************************************** */
class	DoubleNaNException : public std::exception
{
	public:
		virtual char const* what() const throw();
};

/* ************************************************************************** */
/* Other Exceptions */
/* ************************************************************************** */
class	EmptyStrException : public std::exception
{
	public:
		virtual char const* what() const throw();
};
