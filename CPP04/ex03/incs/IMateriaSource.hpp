/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:09:29 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/13 16:40:07 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <AMateria.hpp>

class IMateriaSource
{
	protected:
		AMateria*	inventory[4];

	public:
		IMateriaSource(); //Default constructor
		IMateriaSource(IMateriaSource const& src); //Copy constructor
		virtual ~IMateriaSource(); //Default destructor

		virtual void		learnMateria(AMateria* m) = 0;
		virtual AMateria*	createMateria(std::string const& type) = 0;

		IMateriaSource&	operator=(IMateriaSource const& rhs); //Assignment operator overload
};
