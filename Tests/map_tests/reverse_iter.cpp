/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iter.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:32:57 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/21 12:45:45 by hbel-hou         ###   ########.fr       */
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
        NAME_SPACE::map<char,int>::iterator rit;
        NAME_SPACE::map<char,int>::iterator end;
        rit = mymap.begin();
        mymap.erase(rit);
        // rit = mymap.begin();
        end = mymap.end();
        for (; rit != end; ++rit)
            std::cout << rit->first << " => " << rit->second << '\n';
    }
    {
        NAME_SPACE::map<char,int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        // show content:
        NAME_SPACE::map<char,int>::reverse_iterator rit;
        NAME_SPACE::map<char,int>::reverse_iterator end;
        rit = mymap.rbegin();
        end = mymap.rend();
        for (; rit != end; ++rit)
            std::cout << rit->first << " => " << rit->second << '\n';
    }
    {
        NAME_SPACE::map<char,int> first;

        first['x'] = 400;
        first['y'] = 500;
        first['z'] = 600;
        // for (int i = 1; i < 20; i++)
        //     first[i] = i;
        const NAME_SPACE::map<char,int> mymap(first);
        // // show content:
        NAME_SPACE::map<char,int>::const_reverse_iterator rit;
        NAME_SPACE::map<char,int>::const_reverse_iterator end;
        rit = mymap.rbegin();
        end = mymap.rend();
        for (;rit != end; rit++)
        {
            std::cout << rit->first << " => " << rit->second << '\n';
        }
    }
    {
        NAME_SPACE::map<char,int> first;

        first['x'] = 400;
        first['y'] = 500;
        first['z'] = 600;
        // for (int i = 1; i < 20; i++)
        //     first[i] = i;
        const NAME_SPACE::map<char,int> mymap(first);
        // // show content:
        NAME_SPACE::map<char,int>::const_iterator rit;
        NAME_SPACE::map<char,int>::const_iterator end;
        rit = mymap.begin();
        // std::cout << rit->first << " => " << rit->second << '\n';
        end = mymap.end();
        for (;rit != end; ++rit)
        {
            std::cout << rit->first << " => " << rit->second << '\n';
        }
    }

    return 0;
}