/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:57:28 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/08 15:02:51 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Tests.hpp"

int main ()
{
    vector                      myvector;
    iter_type                   begin, end;


    std::cout << (myvector.empty() ? "true" : "false") << std::endl;

    myvector.push_back(1);

    std::cout << (myvector.empty() ? "true" : "false") << std::endl;

    begin = myvector.begin();
    end = myvector.end();
    PrintVectorValues(begin, end);
    return 0;
}