/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:17:09 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/23 08:53:49 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Data.hpp>

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int	main(void)
{
	Data*	ouaf = new Data();
	std::cout << ouaf << std::endl;

	uintptr_t	nb = serialize(ouaf);

	Data*	new_ouaf = deserialize(nb);
	std::cout << new_ouaf << std::endl;

	delete ouaf;
	return (0);
}