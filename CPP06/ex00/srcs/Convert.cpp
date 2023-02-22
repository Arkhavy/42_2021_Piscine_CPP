/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:24:38 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/22 12:05:11 by ljohnson         ###   ########lyon.fr   */
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
char const*	IntImpossibleException::what() const throw() {return ("int: Impossible");}

/* ************************************************************************** */
/* Float Exceptions */
/* ************************************************************************** */
char const*	FloatNaNException::what() const throw() {return ("float: NaN");}

/* ************************************************************************** */
/* Double Exceptions */
/* ************************************************************************** */
char const*	DoubleNaNException::what() const throw() {return ("double: NaN");}

/* ************************************************************************** */
/* Other Exceptions */
/* ************************************************************************** */
char const*	EmptyStrException::what() const throw() {return ("ERROR: Empty STR given !");}