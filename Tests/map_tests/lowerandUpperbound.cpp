/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowerandUpperbound.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:33:12 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/29 15:15:35 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tests.hpp"

int main ()
{
    NAME_SPACE::map<int, int> mymap;
    NAME_SPACE::map<int, int>::iterator itlow,itup;
    int	rejectedints[] = {4, 6, 8, 9, 2};

    for (int i = 1; i < 15; i++)
        if (i != 6)
            mymap[i] = i;


    itlow=mymap.lower_bound (6);  // itlow points to b
    std::cout << itlow->first << itlow ->second << std::endl;
    itlow=mymap.lower_bound (-12);  // itlow points to b
    std::cout << itlow->first << itlow ->second << std::endl;



    // retruns map::end and it should be dereferenced .

    // itlow=mymap.lower_bound (454);  // itlow points to b
    // std::cout << itlow->first << itlow ->second << std::endl;
    
    
    itlow=mymap.lower_bound (9);  // itlow points to b
    std::cout << itlow->first << itlow ->second << std::endl;
    itlow=mymap.lower_bound (2);  // itlow points to b
    std::cout << itlow->first << itlow ->second << std::endl;


    itup=mymap.upper_bound (6);   // itup points to e (not d!)
    std::cout << itup->first << itup ->second << std::endl;
    itup=mymap.upper_bound (-12);   // itup points to e (not d!)
    std::cout << itup->first << itup ->second << std::endl;
    itup=mymap.upper_bound (9);   // itup points to e (not d!)
    std::cout << itup->first << itup ->second << std::endl;
    itup=mymap.upper_bound (2);   // itup points to e (not d!)
    std::cout << itup->first << itup ->second << std::endl;

    // mymap.erase(itlow,itup);        // erases [itlow,itup)

    // print content:
    // for (NAME_SPACE::map<int, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    // std::cout << it->first << " => " << it->second << '\n';    

    return 0;
}