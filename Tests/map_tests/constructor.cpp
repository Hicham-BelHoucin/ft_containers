/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:27:42 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/26 09:42:27 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tests.hpp"

bool fncomp (char lhs, char rhs) 
{
    return lhs<rhs;
}

struct classcomp 
{
    bool operator() (const char& lhs, const char& rhs) const
    {
        return lhs<rhs;
    }
};

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

        // NAME_SPACE::map<char,int> second (first.begin(),first.end());

        NAME_SPACE::map<char,int> third (first);

        // NAME_SPACE::map<char,int,classcomp> fourth;                 // class as Compare

        // bool(*fn_pt)(char,char) = fncomp;
        // NAME_SPACE::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

        // printMap(first);
        // printMap(second);
        // printMap(third);
        // printMap(fourth);
        // printMap(fifth);
    }
    {
        // NAME_SPACE::map<char,int> first;
        // NAME_SPACE::map<char,int> second;

        // first['x']=8;
        // first['y']=16;
        // first['z']=32;

        // second=first;                // second now contains 3 ints
        // first=NAME_SPACE::map<char,int>();  // and first is now empty

        // std::cout << "Size of first: " << first.size() << '\n';
        // std::cout << "Size of second: " << second.size() << '\n';
    }
    return 0;
}