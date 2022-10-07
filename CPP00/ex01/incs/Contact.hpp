/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:45:51 by ljohnson          #+#    #+#             */
/*   Updated: 2022/10/07 08:06:53 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class	Contact
{
	private:
	// Values
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	
	public:
	// Constructors & Destructors
		Contact();
		~Contact();

	// Member functions
		void		display_info() const;
		
	// Getters
		std::string	get_str(int index) const;

	// Setters
		void		set_str(std::string str, int index);

};

#endif /* CONTACT_HPP */