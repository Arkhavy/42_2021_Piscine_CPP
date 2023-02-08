/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:03:11 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/08 18:03:55 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>

int	main(void)
{
	Cat		c1;
	Dog		d1;
	// AAnimal	a1;

	c1.makeSound();
	d1.makeSound();
	return (0);
}
