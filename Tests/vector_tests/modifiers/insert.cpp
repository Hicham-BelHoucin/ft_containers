/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:19:13 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/21 10:13:27 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Tests.hpp"

int main (void)
{
    vector myvector(3,100);
    iter_type it;

    it = myvector.begin();
    it = myvector.insert ( it , 200 );
    std::cout << "size : " << myvector.size() << std::endl;


    it = myvector.begin();
    myvector.insert (it, 4, 1337);
    std::cout << "size : " << myvector.size() << std::endl;

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    vector anothervector (2,400);
    myvector.insert (it,anothervector.begin(),anothervector.end());
    std::cout << "size : " << myvector.size() << std::endl;

    int myarray [] = { 501,502,503 };
    myvector.insert (myvector.end(), myarray, myarray+3);
    std::cout << "size : " << myvector.size() << std::endl;

    std::cout << "myvector contains:";
    for (it = myvector.begin(); it < myvector.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
}