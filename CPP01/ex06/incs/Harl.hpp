/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:34:20 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/19 13:25:42 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class	Harl
{
	private:
		void	debug();
		void	info();
		void	warning();
		void	error();

	public:
		Harl();
		~Harl();

		void	complain(std::string level);
};

#endif /* HARL_HPP */