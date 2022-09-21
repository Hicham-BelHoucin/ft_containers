/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:36:16 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/21 10:44:22 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./map.hpp"

# define NS ft

int main(void)
{
    NS::map<int, int>           map;
    NS::map<int, int>::iterator begin, end;

    for (int i = 0; i < 1000; i++)
        map[i] = i;
    begin = map.begin();
    end = map.end();
    for (; begin != end; begin++)
        std::cout << "key : " << begin->first << "\nvalue : " << begin->second << std::endl;
}