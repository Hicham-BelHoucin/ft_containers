/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:29:54 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/23 17:30:51 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tests.hpp"

int main ()
{
    NAME_SPACE::map<char,int> mymap;
    char c;

    mymap ['a']=101;
    mymap ['c']=202;
    mymap ['f']=303;

    for (c='a'; c<'h'; c++)
    {
    std::cout << c;
    if (mymap.count(c)>0)
        std::cout << " is an element of mymap.\n";
    else 
        std::cout << " is not an element of mymap.\n";
    }

    return 0;
}