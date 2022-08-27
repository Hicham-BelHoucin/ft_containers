/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iter.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:32:57 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/27 18:27:12 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tests.hpp"

int main ()
{
    {
        NAME_SPACE::map<char,int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        // show content:
        NAME_SPACE::map<char,int>::reverse_iterator rit;
        for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
            std::cout << rit->first << " => " << rit->second << '\n';
    }
    {
        NAME_SPACE::map<char,int> first;

        first['x'] = 100;
        first['y'] = 200;
        first['z'] = 300;
        // for (int i = 1; i < 20; i++)
        //     first[i] = i;
        const NAME_SPACE::map<char,int> mymap(first);

        // show content:
        NAME_SPACE::map<char,int>::const_reverse_iterator rit;
        for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
        {
            std::cout << rit->first << " => " << rit->second << '\n';
        }
    }

    return 0;
}