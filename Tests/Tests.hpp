/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 07:18:52 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/09 15:45:32 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

# include "../Iterator.hpp"
# include "../Vector.hpp"
# include "../lexicographical_compare.hpp"
# include "../equal.hpp"
# include <iostream>
# include <ctime>
# include <vector>
# include <cctype>

# define TESTED_TYPE int
# define NAME_SPACE ft

typedef NAME_SPACE::vector<TESTED_TYPE>             vector;
typedef NAME_SPACE::vector<TESTED_TYPE>::iterator   iter_type;

template <typename iter>
void    PrintVectorValues(iter begin, iter end)
{
	std::cout << "Vector values :" << std::endl;
	while (begin != end)
	{
		std::cout << *begin << std::endl;
		begin++;
	}
}

template <typename iter>
void	SetValues(iter begin, iter end)
{
	int		i;

	i = 1;
	while (begin != end)
	{
		*begin = i;
		begin++;
		i++;
	}
}

#endif // TESTS_HPP
