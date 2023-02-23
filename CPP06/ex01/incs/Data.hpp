/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:18:23 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/23 08:48:09 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdint.h>

#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define FWHITE "\033[0m"

class	Data
{
	private:
		std::string	name;
		int			age;

	public:
		Data();
		Data(Data const& src);
		~Data();

		std::string	get_name() const;
		int			get_age() const;
		void		set_name(std::string const name);
		void		set_age(int const age);

		Data&	operator=(Data const& rhs);
};