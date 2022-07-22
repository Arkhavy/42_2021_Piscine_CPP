/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 08:41:08 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/22 08:47:00 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:

	public:
		Fixed();
		Fixed(Fixed const& src);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int raw);

		Fixed&	operator=(Fixed const& rhs);
};

#endif /* FIXED_HPP */