/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 10:45:33 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/27 11:08:00 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tests.hpp"

int main ()
{
    NAME_SPACE::map<int,int> foo,bar;

    // foo['x']=100;
    // foo['y']=200;

    // bar['a']=11;
    // bar['b']=22;
    // bar['c']=33;

    for (int i = 0; i < 10000; i++)
        bar[i]=i;
    for (int i = 0; i < 10000; i++)
        foo[i]=i;

    foo.swap(bar);

    std::cout << "foo contains:\n";
    for (NAME_SPACE::map<int,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

    std::cout << "bar contains:\n";
    for (NAME_SPACE::map<int,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

    return 0;
}