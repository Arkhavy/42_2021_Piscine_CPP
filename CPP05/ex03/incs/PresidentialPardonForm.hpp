/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:17:14 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/15 14:32:02 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <AForm.hpp>

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm();
		std::string	const	target;

	public:
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const& src);
		virtual ~PresidentialPardonForm(); //override

		virtual void	execute(Bureaucrat const& executor) const; //override pure

		PresidentialPardonForm&	operator=(PresidentialPardonForm const& rhs);
};
