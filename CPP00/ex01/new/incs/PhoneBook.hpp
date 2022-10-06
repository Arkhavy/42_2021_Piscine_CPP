/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:31:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/10/06 10:37:32 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <Contact.hpp>

class PhoneBook
{
	private:
		int		contact_nb;
		int		oldest_contact;
		Contact	contact_list[8];

		void	display_phonebook() const;

	public:
		//Constructors & Destructors
		PhoneBook();
		~PhoneBook();

		//Member functions
		void	add_contact();
		void	search_contact() const;
};

#endif /* PHONEBOOK_HPP */