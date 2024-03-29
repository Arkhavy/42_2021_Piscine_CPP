/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 07:59:23 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/28 08:40:59 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>

template<typename T>
int	easyfind(T& lhs, int rhs)
{
	typename T::iterator res = std::find(lhs.begin(), lhs.end(), rhs);
	if (res == lhs.end())
		throw NotFoundException();
	return (rhs);
}
