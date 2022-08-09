/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 10:38:09 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/09 10:40:11 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Tests.hpp"

int main ()
{
    NAME_SPACE::vector<TESTED_TYPE> myvector;

    for (int i = 0; i < 200; i++)
        myvector.push_back(i);

    std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";

    return 0;
}