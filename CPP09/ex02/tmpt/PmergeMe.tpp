/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:16:44 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/05 11:16:57 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

template<typename T>
T	ft_print_msg(char const* color, std::string const& message, T const val)
{
	std::cerr << color << BOLD;
	std::cerr << message;
	std::cerr << RESET << std::endl;
	return (val);
}