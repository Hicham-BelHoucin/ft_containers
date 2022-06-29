/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:16:22 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/06/29 18:25:54 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "Vector.hpp"

int main(void)
{
    // {
    //     std::cout << "original vector :" << std::endl;
    //     // std::vector<int> myvec;
    //     std::vector<int> myvec;

    //     myvec.push_back(1);
    //     myvec.push_back(2);
    //     myvec.push_back(3);
    //     // myvec.push_back(4);
    //     // myvec.push_back(5);
    //     // myvec.push_back(6);
    //     // myvec.push_back(7);
    //     // myvec.push_back(1);
    //     // myvec.push_back(2);
    //     // myvec.push_back(3);
    //     // myvec.push_back(4);
    //     // myvec.push_back(5);
    //     // myvec.push_back(6);
    //     // myvec.push_back(7);

    //     // std::cout << "      size : " << myvec.size() << std::endl;
    //     // std::cout << "      size : " << myvec.max_size() << std::endl;
    //     // std::cout <<  "     capacity : " << myvec.capacity() << std::endl;
    //     myvec.resize(0, 5);
    //     std::cout << "      size : " << myvec.size() << std::endl;
    //     // std::cout <<  "     capacity : " << myvec.capacity() << std::endl;
    //     // myvec.shrink_to_fit();
    //     // std::cout << "      size : " << myvec.size() << std::endl;
    //     // std::cout <<  "     capacity : " << myvec.capacity() << std::endl;


    //     for (int i = 0; i < myvec.size(); i++)
    //         std::cout <<  myvec[i] << std::endl;
    // }

    // {
    //     std::cout << "my vector :" << std::endl;

    //     ft::vector<int> myvec;
    //     myvec.push_back(1);
    //     myvec.push_back(2);
    //     myvec.push_back(3);
    // //     myvec.push_back(4);
    // //     myvec.push_back(5);
    // //     myvec.push_back(6);
    // //     myvec.push_back(7);
    // //     myvec.push_back(1);
    // //     myvec.push_back(2);
    // //     myvec.push_back(3);
    // //     myvec.push_back(4);
    // //     myvec.push_back(5);
    // //     myvec.push_back(6);
    // //     myvec.push_back(7);

    // //     std::cout << "      size : " << myvec.size() << std::endl;
    //     // std::cout << "      size : " << myvec.max_size() << std::endl;
    // //     std::cout <<  "     capacity : " << myvec.capacity() << std::endl;
    //         myvec.resize(0);
    //         std::cout << "      size : " << myvec.size() << std::endl;
    // //     std::cout <<  "     capacity : " << myvec.capacity() << std::endl;
    // //     myvec.shrink_to_fit();
    // //     std::cout << "      size : " << myvec.size() << std::endl;
    // //     std::cout <<  "     capacity : " << myvec.capacity() << std::endl;


    //     for (int i = 0; i < myvec.size(); i++)
    //         std::cout <<  myvec[i] << std::endl;
    // }
    {
        ft::vector<int> foo (3,100);   // three ints with a value of 100
        ft::vector<int> bar (5,200);   // five ints with a value of 200

        foo.swap(bar);

        std::cout << "foo contains:";
        for (unsigned i=0; i<foo.size(); i++)
            std::cout << ' ' << foo[i];
        std::cout << '\n';

        std::cout << "bar contains:";
        for (unsigned i=0; i<bar.size(); i++)
            std::cout << ' ' << bar[i];
        std::cout << '\n';
    }
    // {
    //     std::vector<int> first;
    //     std::vector<int> second;
    //     std::vector<int> third;


    //     // std::vector<int>::iterator it;
    //     // it=first.begin()+1;

    //     // second.assign (it,first.end()-1); // the 5 central values of first

    //     int myints[] = {1776,7,4};
    //     third.assign (myints,myints+3);   // assigning from array.
    //     first.push_back(5);
    //     first.push_back(6);
    //     first.push_back(7);
    //     first.assign (7,100);             // 7 ints with a value of 100
    //     std::cout << "Size of first: " << int (first.size()) << '\n';
    //     for (int i = 0; i < first.size(); i++)
    //         std::cout << first[i] << std::endl;
    //     std::cout << "Size of second: " << int (second.size()) << '\n';
    //     std::cout << "Size of third: " << int (third.size()) << '\n';
    // }
}