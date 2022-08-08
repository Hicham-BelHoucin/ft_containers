/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_tests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:31:38 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/08 08:06:24 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tests.hpp"

int main(void)
{
	vector      myvector(5);
	iter_type   begin, end, tmp;

	std::cout << "Testing Iterator .... " << std::endl;
	begin = myvector.begin();
	end = myvector.end();
	SetValues(begin, end);
	PrintVectorValues(begin, end);
	std::cout << "Testing Operators .... " << std::endl;
	std::cout << "Testing + operator" << std::endl;
	tmp = begin + 3;
	std::cout << "tmp value : " << *tmp << std::endl;
	
	std::cout << "Testing - operator" << std::endl;
	tmp = end - 3;
	std::cout << "tmp value : " << *tmp << std::endl;

	std::cout << "Testing ++ Prefix operator" << std::endl;
	++tmp;
	std::cout << "tmp value : " << *tmp << std::endl;

	std::cout << "Testing -- Prefix operator" << std::endl;
	--tmp;
	std::cout << "tmp value : " << *tmp << std::endl;

	std::cout << "Testing -- Suffix operator" << std::endl;
	tmp--;
	std::cout << "tmp value : " << *tmp << std::endl;
	tmp = begin;
	std::cout << "Testing == operator :" << std::endl;
	std::cout << (tmp == begin ? "true" : "false") << std::endl;

	std::cout << "Testing != operator :" << std::endl;
	std::cout << (tmp != begin ? "true" : "false") << std::endl;

	std::cout << "Testing > operator :" << std::endl;
	std::cout << (tmp > end ? "true" : "false") << std::endl;

	std::cout << "Testing < operator :" << std::endl;
	std::cout << (tmp < end ? "true" : "false") << std::endl;

	std::cout << "Testing - operator :" << std::endl;
	std::cout << (end - begin) << std::endl;
	std::cout << "Testing + operator :" << std::endl;
	std::cout << *(begin + 2) << std::endl;

	std::cout << "Done Testing Iterator .... " << std::endl;
}