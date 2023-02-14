/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:18:20 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/14 08:19:36 by ljohnson         ###   ########lyon.fr   */
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

class ICharacter;

class AMateria
{
	protected:
		std::string	type;
		bool		equipped;

	public:
		AMateria(); //Default constructor
		AMateria(std::string const& type);
		AMateria(AMateria const& src); //Copy constructor
		virtual	~AMateria(); //Default destructor

		std::string const&	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

		bool	const&	getEquipped() const;
		void			setEquipped(bool equipped);

		AMateria&	operator=(AMateria const& rhs); //Assignment operator overload
};