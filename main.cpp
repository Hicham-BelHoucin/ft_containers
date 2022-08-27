/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:53:34 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/27 11:20:49 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./containers/map.hpp"
# define NAME_SPACE std

template <class T>
void    printMap(T first)
{
    typedef typename T::iterator iterator;
    iterator begin;
    iterator end;

    begin = first.begin();
    end = first.end();
    while (begin != end)
    {
        std::cout << begin->first << std::endl;
        begin++;
    }
    std::cout << "/***********************************/" << std::endl;
}

int main ()
{
    {
        NAME_SPACE::map<char,int> first;

        first['a']=10;
        first['b']=30;
        first['c']=50;
        first['d']=70;

        NAME_SPACE::map<char,int> second (first.begin(),first.end());

        NAME_SPACE::map<char,int> third (second);

        // NAME_SPACE::map<char,int,classcomp> fourth;                 // class as Compare

        // bool(*fn_pt)(char,char) = fncomp;
        // NAME_SPACE::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

        printMap(first);
        printMap(second);
        printMap(third);
        // printMap(fourth);
        // printMap(fifth);
    }
    return 0;
}