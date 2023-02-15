/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:52:53 by ljohnson          #+#    #+#             */
/*   Updated: 2023/02/15 11:53:04 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <Form.hpp>

class RobotomyRequestForm : public Form
{
	private:
		RobotomyRequestForm();
		std::string	const	target;

	public:
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const& src);
		virtual ~RobotomyRequestForm(); //override

		virtual void	execute(Bureaucrat const& executor) const; //override pure

		RobotomyRequestForm&	operator=(RobotomyRequestForm const& rhs);
};
