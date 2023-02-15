/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:53:12 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/15 13:25:56 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <AForm.hpp>

class ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm();
		std::string	const	target;

	public:
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(ShrubberyCreationForm const& src);
		virtual ~ShrubberyCreationForm(); //override

		virtual void	execute(Bureaucrat const& executor) const; //override pure

		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& rhs);
};
