/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:46:10 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/15 11:09:28 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <Contact.hpp>

class	PhoneBook
{
	private:
		int		contact_nb;
		int		oldest_contact;
		Contact	Contact[8];

		void	display_phonebook();

	public:
		PhoneBook();
		~PhoneBook();

		void	add_contact();
		void	search_contact();
		void	exit_program();

};

#endif /* PHONEBOOK_HPP */