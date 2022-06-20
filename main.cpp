/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:16:22 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/06/20 16:55:28 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "Vector.hpp"

int main(void)
{
    // std::vector<int> myvec;

    // myvec.push_back(2);
    // myvec.push_back(2);
    // myvec.push_back(2);
    // myvec.push_back(2);
    // myvec.push_back(2);
    
    // std::cout <<  myvec.size() << std::endl;
    // std::cout <<  myvec.capacity() << std::endl;
    // myvec.reserve(300);
    // std::cout <<  myvec.size() << std::endl;
    // std::cout <<  myvec.capacity() << std::endl;
    // myvec.shrink_to_fit();
    // std::cout <<  myvec.size() << std::endl;
    // std::cout <<  myvec.capacity() << std::endl;

    ft::vector<int> myvec;

    myvec.push_back(1);
    myvec.push_back(2);
    myvec.push_back(3);
    myvec.push_back(4);
    myvec.push_back(5);
    myvec.push_back(6);
    myvec.push_back(7);

    for (int i = 0; i < myvec.size(); i++)
        std::cout <<  myvec[i] << std::endl;
}