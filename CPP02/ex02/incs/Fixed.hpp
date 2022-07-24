/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:33:59 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/24 10:37:16 by ljohnson         ###   ########lyon.fr   */
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
		int		toInt() const;

		Fixed&	operator=(Fixed const& rhs);
		Fixed	operator+(Fixed const& rhs) const;
		Fixed	operator-(Fixed const& rhs) const;
		Fixed	operator/(Fixed const& rhs) const;
		Fixed	operator*(Fixed const& rhs) const;
};

std::ostream&	operator<<(std::ostream& out, Fixed const& rhs);

#endif /* FIXED_HPP */

/*
operator>
operator<
operator>=
operator<=
operator==
operator!=

operator+ OK
operator- OK
operator* OK
operator/ OK

i++
++i
i--
--i
ε tel que 1 + ε > 1

min
min const
max
max const
*/