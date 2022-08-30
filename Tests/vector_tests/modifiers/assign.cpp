/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 07:52:00 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/30 11:59:35 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Tests.hpp"

int main(void)
{
    std::cout << "Testing assign : " << std::endl;
    NAME_SPACE::vector<TESTED_TYPE> first;
    NAME_SPACE::vector<TESTED_TYPE> second;
    NAME_SPACE::vector<TESTED_TYPE> third;

    first.assign (70,100);

    NAME_SPACE::vector<TESTED_TYPE>::iterator it;
    it = first.begin() + 1;

    second.assign (it, first.end() - 1);

    int myints[] = {1776, 7, 4};
    third.assign (myints, myints + 3);

    std::cout << "Size of first: " << int (first.size()) << std::endl;
    PrintVectorValues(first.begin(), first.end());
    std::cout << "Size of second: " << int (second.size()) << std::endl;
    PrintVectorValues(second.begin(), second.end());
    std::cout << "Size of third: " << int (third.size()) << std::endl;
    PrintVectorValues(third.begin(), third.end());
}