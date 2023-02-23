/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:24:38 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/23 08:03:38 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Convert.hpp>

/* ************************************************************************** */
/* Char Exceptions */
/* ************************************************************************** */
char const*	IsCharException::what() const throw() {return ("ouaf");}
char const*	CharNonDisplayableException::what() const throw() {return ("char: Non displayable");}
char const*	CharImpossibleException::what() const throw() {return ("char: Impossible");}

/* ************************************************************************** */
/* Int Exceptions */
/* ************************************************************************** */
char const*	IntImpossibleException::what() const throw() {return ("int: Impossible");}
char const*	IntOverflowException::what() const throw() {return ("int: Overflow");}

/* ************************************************************************** */
/* Float Exceptions */
/* ************************************************************************** */
char const*	FloatPosInfException::what() const throw() {return ("float: +inff");}
char const*	FloatNegInfException::what() const throw() {return ("float: -inff");}
char const*	FloatNaNException::what() const throw() {return ("float: NaNf");}
char const*	FloatOverflowException::what() const throw() {return ("float: Overflow");}

/* ************************************************************************** */
/* Double Exceptions */
/* ************************************************************************** */
char const*	DoublePosInfException::what() const throw() {return ("double: +inf");}
char const*	DoubleNegInfException::what() const throw() {return ("double: -inf");}
char const*	DoubleNaNException::what() const throw() {return ("double: NaN");}
char const*	DoubleOverflowException::what() const throw() {return ("double: Overflow");}

/* ************************************************************************** */
/* Other Exceptions */
/* ************************************************************************** */
char const*	NbNotValidException::what() const throw() {return ("ouaf ouaf");}