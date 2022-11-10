/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:29:09 by ljohnson          #+#    #+#             */
/*   Updated: 2022/11/10 16:17:32 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

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

#endif /* HARL_HPP */