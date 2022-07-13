/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:44:37 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/13 13:35:42 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.Class.hpp>

Contact::Contact() {return ;}

Contact::~Contact() {return ;}

std::string	Contact::get_first_name() {return (this->first_name);}

std::string	Contact::get_last_name() {return (this->last_name);}

std::string	Contact::get_nickname() {return (this->nickname);}

std::string	Contact::get_phone_number() {return (this->phone_number);}

std::string	Contact::get_darkest_secret() {return (this->darkest_secret);}

void	Contact::display_info()
{
	std::cout << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "First name : " << this->first_name << std::endl;
	std::cout << "Last name : " << this->last_name << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Phone Number : " << this->phone_number << std::endl;
	std::cout << "Darkest Secret : " << this->darkest_secret << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;
}