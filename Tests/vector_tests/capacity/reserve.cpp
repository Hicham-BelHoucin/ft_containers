/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:45:15 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/08 14:56:06 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Tests.hpp"

int main ()
{
    NAME_SPACE::vector<TESTED_TYPE>::size_type  sz;
    NAME_SPACE::vector<TESTED_TYPE>             foo(5);

    SetValues(foo.begin(), foo.end());
    sz = foo.capacity();
    std::cout << sz << std::endl;
    foo.reserve(10);
    sz = foo.capacity();
    std::cout << sz << std::endl;
    foo.reserve(50);
    sz = foo.capacity();
    std::cout << sz << std::endl;
    foo.reserve(80);
    sz = foo.capacity();
    std::cout << sz << std::endl;
    foo.reserve(100);
    sz = foo.capacity();
    std::cout << sz << std::endl;
    return 0;
}