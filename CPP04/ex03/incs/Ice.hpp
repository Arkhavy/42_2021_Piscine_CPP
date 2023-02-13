/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:15:56 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/13 16:29:29 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <AMateria.hpp>

class Ice : public AMateria
{
	public:
		Ice(); //Default constructor
		Ice(std::string const& type);
		Ice(Ice const& src); //Copy constructor
		~Ice(); //override Default destructor

		Ice*	clone() const; //override
		void	use(ICharacter& target); //override

		Ice&	operator=(Ice const& rhs); //Assignment operator overload
};