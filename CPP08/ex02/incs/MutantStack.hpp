/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:54:34 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/28 15:30:24 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define FWHITE "\033[0m"

template<typename T>
class	MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack<T> const& src);
		~MutantStack();

		MutantStack<T>&	operator=(MutantStack<T> const& rhs);

		typedef typename	std::stack<T>::container_type::iterator			iterator;
		typedef typename	std::stack<T>::container_type::const_iterator	const_iterator;

		iterator	begin();
		iterator	end();
		const_iterator	cbegin();
		const_iterator	cend();
};

#include <MutantStack.tpp>