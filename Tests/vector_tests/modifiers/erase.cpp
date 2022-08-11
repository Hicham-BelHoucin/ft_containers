/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:13:18 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/09 13:32:15 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Tests.hpp"

int main ()
{
    vector myvector;

    for (int i=1; i<=10; i++) myvector.push_back(i);

    myvector.erase (myvector.begin()+5);

    myvector.erase (myvector.begin(),myvector.begin()+3);

    std::cout << "myvector contains:";
    for (unsigned i=0; i < myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';

    return 0;
}