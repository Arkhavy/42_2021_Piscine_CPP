/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:07:24 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/23 14:58:21 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define FWHITE "\033[0m"

template<typename T>
void	swap(T& a, T& b)
{
	T	c = a;

	a = b;
	b = c;
}

template<typename T>
T	min(T const& a, T const& b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename T>
T	max(T const& a, T const& b)
{
	if (a > b)
		return (a);
	return (b);
}
