/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_allocator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:57:00 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/23 17:57:43 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tests.hpp"

int main ()
{
    int psize;
    NAME_SPACE::map<char,int> mymap;
    NAME_SPACE::pair<const char,int>* p;

    // allocate an array of 5 elements using mymap's allocator:
    p=mymap.get_allocator().allocate(5);

    // assign some values to array
    psize = sizeof(std::map<char,int>::value_type)*5;

    std::cout << "The allocated array has a size of " << psize << " bytes.\n";

    mymap.get_allocator().deallocate(p,5);

    return 0;
}