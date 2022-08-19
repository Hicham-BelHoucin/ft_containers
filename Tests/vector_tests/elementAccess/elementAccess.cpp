/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:08:19 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/08 15:18:30 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Tests.hpp"

int main ()
{
    vector myvector(15);


    std::cout << "testing [] operator : " << std::endl;
    for (int i = 0; i < 15; i++)
        myvector[i] = i + 1;
    for (int i = 0; i < 15; i++)
        std::cout << ' ' << myvector[i];
    std::cout << std::endl;
    std::cout << "testing at() : " << std::endl;
    for (int i = 0; i < 15; i++)
        myvector.at(i) = i + 1;
    for (int i = 0; i < 15; i++)
        std::cout << ' ' << myvector.at(i);
    std::cout << std::endl;
    myvector.front() += 15;
    myvector.back() += 21;
    std::cout << "myvector.front() is : " << myvector.front() << '\n';
    std::cout << "myvector.back() is : " << myvector.back() << '\n';
}