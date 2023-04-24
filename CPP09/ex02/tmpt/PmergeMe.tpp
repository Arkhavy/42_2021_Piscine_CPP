/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:16:44 by ljohnson          #+#    #+#             */
/*   Updated: 2023/04/24 13:01:54 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

template<typename T>
T	ft_print_msg(char const* color, std::string const& message, T const val)
{
	std::cerr << color << BOLD;
	std::cerr << message;
	std::cerr << RESET << std::endl;
	return (val);
}

template<typename T>
T&	PmergeMe::merge_insert_sort(T& lst)
{
	unsigned int	lst_size = lst.size();
	unsigned int	half_size = lst_size / 2;

	if (lst_size > 16)
	{
		typename T::iterator	it = lst.begin();
		T	a;
		T	b;

		for (unsigned int i = 0; i < half_size; i++, it++)
			a.push_back(*it);
		for (unsigned int i = half_size; i < lst_size; i++, it++)
			b.push_back(*it);
		a = merge_insert_sort(a);
		b = merge_insert_sort(b);
		std::merge(a.begin(), a.end(), b.begin(), b.end(), lst.begin());
	}
	else
	{
		typename T::iterator	it1 = lst.begin();
		typename T::iterator	it2 = lst.begin();
		it2++;

		while (it2 != lst.end())
		{
			if (*it1 > *it2)
			{
				std::swap(*it1, *it2);
				if (it1 != lst.begin())
				{
					it1--;
					it2--;
				}
			}
			else
			{
				it1++;
				it2++;
			}
		}
	}
	return (lst);
}

template<typename T>
bool	check_sorting(T& lst)
{
	typename T::const_iterator	it1 = lst.begin();
	typename T::const_iterator	it2 = lst.begin();
	it2++;

	while (it2 != lst.end())
	{
		if (*it1 > *it2)
			return (false);
		it1++;
		it2++;
	}
	return (true);
}

template<typename T>
void	PmergeMe::display_tab(T const& lst, std::string const& moment) const
{
	std::cout << moment;
	if (moment == "Before: ")
		std::cout << CYAN;
	else
		std::cout << GREEN;
	for (typename T::const_iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << RESET << std::endl;
}