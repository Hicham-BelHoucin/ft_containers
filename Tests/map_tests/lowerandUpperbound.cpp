/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowerandUpperbound.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:33:12 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/26 14:41:42 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tests.hpp"

int main ()
{
    NAME_SPACE::map<char,int> mymap;
    NAME_SPACE::map<char,int>::iterator itlow,itup;

    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;

    itlow=mymap.lower_bound ('b');  // itlow points to b
    itup=mymap.upper_bound ('d');   // itup points to e (not d!)


    std::cout << itlow->first << itlow ->second << std::endl;
    std::cout << itup->first << itup ->second << std::endl;

    mymap.erase(itlow,itup);        // erases [itlow,itup)

    // print content:
    for (NAME_SPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';    

    return 0;
}