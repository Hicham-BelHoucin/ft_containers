/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:37:28 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/30 11:56:54 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Tests.hpp"

int main ()
{
    NAME_SPACE::vector<TESTED_TYPE> myvector;

    
    for (int i = 1; i < 10;i++)
        myvector.push_back(i);

    myvector.resize(5);
    PrintVectorValues(myvector.begin(), myvector.end());
    myvector.resize(8, 100);
    PrintVectorValues(myvector.begin(), myvector.end());
    myvector.resize(12);
    PrintVectorValues(myvector.begin(), myvector.end());

    return 0;
}