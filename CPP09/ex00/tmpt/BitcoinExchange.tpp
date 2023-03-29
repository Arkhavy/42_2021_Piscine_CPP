/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:08:30 by ljohnson          #+#    #+#             */
/*   Updated: 2023/03/29 10:47:09 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

template<typename T>
T	ft_print_msg(char const* color, std::string const& message, T const val)
{
	std::cerr << color << BOLD;
	std::cerr << message;
	std::cerr << RESET << std::endl;
	return (val);
}