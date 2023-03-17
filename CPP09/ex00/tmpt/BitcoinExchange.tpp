/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:08:30 by ljohnson          #+#    #+#             */
/*   Updated: 2023/03/17 13:25:25 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

template<typename T>
T	ft_print_err(std::string const& message, T const val)
{
	std::cerr << RED << BOLD;
	std::cerr << message;
	std::cerr << RESET << std::endl;
	return (val);
}