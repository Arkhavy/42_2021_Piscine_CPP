/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:19:35 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/22 13:47:48 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	private:
		int					value;
		static const int	bitnb = 8;

	public:
		Fixed();
		Fixed(Fixed const& src);
		Fixed(int const nb);
		Fixed(float const nb);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int 	toInt() const;

		Fixed&	operator=(Fixed const& rhs);
		Fixed&	operator<<(Fixed const& rhs);
};

#endif /* FIXED_HPP */