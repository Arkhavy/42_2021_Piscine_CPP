/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:24:38 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/21 11:52:57 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Convert.hpp>

/* ************************************************************************** */
/* Char Exceptions */
/* ************************************************************************** */
char const*	CharImpossibleException::what() const throw() {return ("char: Impossible");}
char const*	CharNonDisplayableException::what() const throw() {return ("char: Non displayable");}

/* ************************************************************************** */
/* Int Exceptions */
/* ************************************************************************** */
char const*	IntOverflowException::what() const throw() {return ("int: Overflow");}
char const*	IntImpossibleException::what() const throw() {return ("int: Impossible");}

/* ************************************************************************** */
/* Float Exceptions */
/* ************************************************************************** */
char const*	FloatOverflowException::what() const throw() {return ("float: Overflow");}
char const*	FloatInfNegativeException::what() const throw() {return ("float: -inff");}
char const*	FloatInfPositiveException::what() const throw() {return ("float: +inff");}
char const*	FloatNaNException::what() const throw() {return ("float: NaN");}

/* ************************************************************************** */
/* Double Exceptions */
/* ************************************************************************** */
char const*	DoubleOverflowException::what() const throw() {return ("double: Overflow");}
char const*	DoubleInfNegativeException::what() const throw() {return ("double: -inf");}
char const*	DoubleInfPositiveException::what() const throw() {return ("double: +inf");}
char const*	DoubleNaNException::what() const throw() {return ("double: NaN");}


