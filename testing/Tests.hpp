/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 07:18:52 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/03 13:22:28 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

template <typename iter>
void    PrintVectorValues(iter begin, iter end, std::string value = "Vector values :")
{
	std::cout << value << std::endl;
	while (begin != end)
	{
		std::cout << *begin << " ";
		begin++;
	}
	std::cout << std::endl;
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
