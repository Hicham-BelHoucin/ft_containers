/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:42:57 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/09 15:45:54 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Tests.hpp"


bool mypredicate (int i, int j) 
{
  return ( i == j);
}

int main () 
{
    int myints[] = {20, 40, 60, 80, 100};
    vector myvector (myints, myints + 5);

    if (NAME_SPACE::equal (myvector.begin(), myvector.end(), myints))
        std::cout << "The contents of both sequences are equal.\n";
    else
        std::cout << "The contents of both sequences differ.\n";

    myvector [3] = 81;

    if (NAME_SPACE::equal (myvector.begin(), myvector.end(), myints, mypredicate))
        std::cout << "The contents of both sequences are equal.\n";
    else
        std::cout << "The contents of both sequences differ.\n";

    return 0;
}