/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:15:06 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/30 15:09:25 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Tests.hpp"

int main ()
{
    NAME_SPACE::vector<TESTED_TYPE> myints;
    std::cout << "0. size: " << myints.size() << std::endl;

    for (int i = 0; i < 10; i++) myints.push_back(i);
    std::cout << "1. size: " << myints.size() << std::endl;
    PrintVectorValues(myints.begin(), myints.end());

    myints.insert (myints.end(),10,10);
    std::cout << "2. size: " << myints.size() << std::endl;
    PrintVectorValues(myints.begin(), myints.end());

    myints.pop_back();
    std::cout << "3. size: " << myints.size() << std::endl;
    PrintVectorValues(myints.begin(), myints.end());

    return 0;
}