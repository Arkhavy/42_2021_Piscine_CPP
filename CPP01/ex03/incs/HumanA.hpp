/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:08:44 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/16 11:48:14 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <Weapon.hpp>

class	HumanA
{
	private:
		std::string	name;
		Weapon		weapon;

	public:
		HumanA(std::string name, Weapon weapon);
		~HumanA();

		void	attack() const;
};

#endif /* HUMANA_HPP */