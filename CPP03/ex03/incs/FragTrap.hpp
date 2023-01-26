/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:27:14 by ljohnson          #+#    #+#             */
/*   Updated: 2023/01/26 10:44:45 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <ClapTrap.hpp>

class FragTrap : public virtual ClapTrap
{
	private:
		static unsigned int	frag_max_hit_points;
		static unsigned int	frag_attack_damage;

	public:
		FragTrap(); //Default constructor
		FragTrap(std::string name);
		FragTrap(FragTrap const& src); //Copy constructor
		~FragTrap(); //Default destructor

		void	highFivesGuys(void);
		static unsigned int	get_max_hit_points();
		static unsigned int	get_attack_damage();
		void				set_max_hit_points();
		void				set_attack_damage();

		FragTrap&	operator=(FragTrap const& rhs);
};

#endif /* FRAGTRAP_HPP */