/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 08:41:08 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/22 11:36:31 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					value;
		static const int	bitnb = 8;

	public:
		Fixed();
		Fixed(Fixed const& src);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);

		Fixed&	operator=(Fixed const& rhs);
};

#endif /* FIXED_HPP */