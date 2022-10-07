/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:46:10 by ljohnson          #+#    #+#             */
/*   Updated: 2022/10/07 08:06:26 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <Contact.hpp>

class	PhoneBook
{
	private:
	// Values
		int		contact_nb;
		int		oldest_contact;
		Contact	contact_list[8];

	// Member functions
		void	display_phonebook() const;

	public:
	// Constructors & Destructors
		PhoneBook();
		~PhoneBook();

	// Member functions
		void	add_contact();
		void	search_contact() const;

};

#endif /* PHONEBOOK_HPP */