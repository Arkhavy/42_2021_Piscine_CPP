/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:44:13 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/27 13:18:26 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <cstdlib>

#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define FWHITE "\033[0m"

template<typename T>
class	Array
{
	private:
		T*				array;
		unsigned int	array_size;

	public:
		Array();
		Array(unsigned int n);
		Array(Array const& src);
		~Array();

		unsigned int	size() const;

		class	OutOfRangeException : public std::exception
		{
			public:
				virtual char const*	what() const throw();
		};

		Array&			operator=(Array const& rhs); //must deep copy
		T const&		operator[](unsigned int const idx) const;
		T&				operator[](unsigned int const idx);
};

#include <Array.tpp>