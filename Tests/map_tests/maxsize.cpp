/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxsize.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:13:22 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/30 14:56:21 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tests.hpp"

int main ()
{
    int i;  
    NAME_SPACE::map<int,int> mymap;

    if (mymap.max_size() > 1000)
    {
        for (i = 0; i < 1000; i++) mymap[i]=0;
            std::cout << "The map contains 1000 elements.\n";
    }
    else std::cout << "The map could not hold 1000 elements.\n";

    return 0;
}