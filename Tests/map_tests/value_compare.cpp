/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_copare.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:01:51 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/29 11:03:35 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tests.hpp"

int main ()
{
    NAME_SPACE::map<char,int> mymap;

    mymap['x']=1001;
    mymap['y']=2002;
    mymap['z']=3003;

    std::cout << "mymap contains:\n";

    NAME_SPACE::pair<char,int> highest = *mymap.rbegin();          // last element

    NAME_SPACE::map<char,int>::iterator it = mymap.begin();
    do {
    std::cout << it->first << " => " << it->second << '\n';
    } while ( mymap.value_comp()(*it++, highest) );

    return 0;
}