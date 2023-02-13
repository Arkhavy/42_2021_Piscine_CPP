/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:26:45 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/13 18:37:52 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <IMateriaSource.hpp>

class AMateria;

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(); //Default constructor
		MateriaSource(MateriaSource const& src); //Copy constructor
		~MateriaSource(); //override Default destructor

		void		learnMateria(AMateria* m); //override
		AMateria*	createMateria(std::string const& type); //override

		MateriaSource&	operator=(MateriaSource const& rhs); //Assignment operator overload
};