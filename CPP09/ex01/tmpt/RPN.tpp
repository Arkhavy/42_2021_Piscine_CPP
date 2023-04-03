/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:34:49 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/03 12:34:56 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

template<typename T>
T	ft_print_msg(char const* color, std::string const& message, T const val)
{
	std::cerr << color << BOLD;
	std::cerr << message;
	std::cerr << RESET << std::endl;
	return (val);
}