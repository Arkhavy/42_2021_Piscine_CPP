/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:19:35 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/23 16:39:43 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					value;
		static const int	bitnb = 8;

	public:
		Fixed(); //Default constructor
		Fixed(Fixed const& src); //Copy constructor
		Fixed(int const nb);
		Fixed(float const nb);
		~Fixed(); //Default destructor

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int 	toInt() const;

		Fixed&	operator=(Fixed const& rhs);
};

std::ostream&	operator<<(std::ostream& out, Fixed const& rhs);

#endif /* FIXED_HPP */