/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:10:20 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/09 15:44:51 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Tests.hpp"

bool mycomp (char c1, char c2)
{ 
    return std::tolower(c1) < std::tolower(c2);
}

int main ()
{
    char foo[]="Apple";
    char bar[]="apartment";

    std::cout << std::boolalpha;

    std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

    std::cout << "Using default comparison (operator<): ";
    std::cout << NAME_SPACE::lexicographical_compare(foo, foo+5, bar, bar+9);
    std::cout << '\n';

    std::cout << "Using mycomp as comparison object: ";
    std::cout << NAME_SPACE::lexicographical_compare(foo, foo+5, bar, bar+9, mycomp);
    std::cout << '\n';

  return 0;
}
