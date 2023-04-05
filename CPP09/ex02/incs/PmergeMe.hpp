/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:19:23 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/05 17:56:47 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <exception>
#include <algorithm>
#include <sys/time.h>

# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

# define ERASE		"\033[2K\r"
# define RESET		"\033[0m"
# define BOLD		"\033[1m"
# define FAINT		"\033[2m"
# define ITALIC		"\033[3m"
# define UNDERLINE	"\033[4m"

class	PmergeMe
{
	private:
		std::list<unsigned int>		lst;
		std::vector<unsigned int>	vct;
		u_int64_t					begin_time_lst;
		u_int64_t					begin_time_vct;
		u_int64_t					end_time_lst;
		u_int64_t					end_time_vct;
	
	public:
	//Constructors & Destructors
		PmergeMe();
		PmergeMe(PmergeMe const& src);
		virtual	~PmergeMe();

	//Operator overloads
		PmergeMe&	operator=(PmergeMe const& rhs);

	//Getter & Setters
		void		set_lst_val(unsigned int nb);
		void		set_vct_val(unsigned int nb);
		u_int64_t	get_time_vct() const;
		u_int64_t	get_time_lst() const;
		u_int64_t	set_time();

	//Member functions
		bool	check_vct_duplicates() const;
		void	display_lst() const;
		void	display_vct() const;

		template<typename T>
		T&	ft_sorting(T& lst);

		void	launch();
		void	display_process_time();
};

/* ************************************************************************** */
/* Exceptions */
/* ************************************************************************** */
class	InvalidProgramNameException	: public std::exception {public: virtual char const*	what() const throw();};
class	InvalidArgumentException	: public std::exception {public: virtual char const*	what() const throw();};
class	OutOfRangeException			: public std::exception {public: virtual char const*	what() const throw();};
class	DuplicateFoundException		: public std::exception {public: virtual char const*	what() const throw();};

/* ************************************************************************** */
/* Templates */
/* ************************************************************************** */
template<typename T>
T	ft_print_msg(char const* color, std::string const& message, T const val);

template<typename T>
bool	check_sorting(T& lst);

#include <PmergeMe.tpp>