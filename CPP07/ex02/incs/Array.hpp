/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:44:13 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/23 16:50:20 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

template<typename T>
class	Array
{
	private:

	public:
		Array<T>();
		Array<T>(unsigned int n);
		Array<T>(Array const& src);
		~Array<T>();

		unsigned int	size() const;

		Array&	operator=(Array const& rhs); //must deep copy
};