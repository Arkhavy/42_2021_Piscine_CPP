/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:40:37 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/28 13:22:13 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define FWHITE "\033[0m"

class	Span
{
	private:
		std::vector<int>	tab;
		unsigned int		tab_max_size;

		Span();
	public:
		Span(unsigned int const N);
		Span(Span const& src);
		~Span();

		Span&	operator=(Span const& rhs);

		class	NoSpanPossibleException : public std::exception
		{
			public:
				virtual char const*	what() const throw();
		};

		class	NoSpaceLeftException : public std::exception
		{
			public:
				virtual char const*	what() const throw();
		};

		void			addNumber(int const nb);
		int				shortestSpan() const;
		int				longestSpan() const;
		void			addPack(unsigned int const N, int const value);

		int				get_value_idx(unsigned int const idx) const;
		unsigned int	get_size() const; 
};

std::ostream&	operator<<(std::ostream& out, Span const& rhs);