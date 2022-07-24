/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:33:59 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/24 13:56:22 by ljohnson         ###   ########lyon.fr   */
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

		static const Fixed&	min(Fixed const& lhs, Fixed const& rhs);
		static const Fixed&	max(Fixed const& lhs, Fixed const& rhs);
		static const Fixed&	min(Fixed& lhs, Fixed& rhs);
		static const Fixed&	max(Fixed& lhs, Fixed& rhs);

		Fixed&	operator=(Fixed const& rhs);
		Fixed	operator+(Fixed const& rhs) const;
		Fixed	operator-(Fixed const& rhs) const;
		Fixed	operator/(Fixed const& rhs) const;
		Fixed	operator*(Fixed const& rhs) const;

		int		operator>(Fixed const& rhs) const;
		int		operator<(Fixed const& rhs) const;
		int		operator>=(Fixed const& rhs) const;
		int		operator<=(Fixed const& rhs) const;
		int		operator==(Fixed const& rhs) const;
		int		operator!=(Fixed const& rhs) const;

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
};

std::ostream&	operator<<(std::ostream& out, Fixed const& rhs);

#endif /* FIXED_HPP */

/*
operator> OK
operator< OK
operator>= OK
operator<= OK
operator== OK
operator!= OK

operator+ OK
operator- OK
operator* OK
operator/ OK

i++ OK
++i OK
i-- OK
--i OK
ε tel que 1 + ε > 1

min OK
min const OK
max OK
max const OK
*/