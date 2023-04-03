/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:20:42 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/03 12:50:37 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

char const*	InvalidProgramNameException::what()	const throw() {return ("ERROR: Invalid program name");}
char const*	InvalidArgumentException::what()	const throw() {return ("ERROR: Invalid argument given");}