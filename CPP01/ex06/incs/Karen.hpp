/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:34:20 by ljohnson          #+#    #+#             */
/*   Updated: 2022/11/10 16:30:34 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>

class	Karen
{
	private:
		void	debug();
		void	info();
		void	warning();
		void	error();

	public:
		Karen();
		~Karen();

		void	complain(std::string level);
};

#endif /* KAREN_HPP */