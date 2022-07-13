/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:45:51 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/13 11:56:48 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>
# include <iostream>

class	Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
		void	display_info();

	public:
		Contact();
		~Contact();

		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
		std::string	get_phone_number();
		std::string	get_darkest_secret();
};

#endif