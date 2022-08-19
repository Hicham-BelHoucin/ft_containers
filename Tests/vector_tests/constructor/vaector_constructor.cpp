/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 08:09:55 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/08 14:14:56 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Tests.hpp"

int main ()
{
    int myints[] = {16, 2, 77, 29};
    NAME_SPACE::vector<TESTED_TYPE> first;
    NAME_SPACE::vector<TESTED_TYPE> second (4,100);
    NAME_SPACE::vector<TESTED_TYPE> third (second.begin(),second.end());
    NAME_SPACE::vector<TESTED_TYPE> fourth (third);
    NAME_SPACE::vector<TESTED_TYPE> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    NAME_SPACE::vector<TESTED_TYPE> sixth;

    sixth = fifth;
    PrintVectorValues(first.begin(), first.end());
    PrintVectorValues(second.begin(), second.end());
    PrintVectorValues(third.begin(), third.end());
    PrintVectorValues(fourth.begin(), fourth.end());
    PrintVectorValues(fifth.begin(), fifth.end());
    PrintVectorValues(sixth.begin(), sixth.end());
    return 0;
}