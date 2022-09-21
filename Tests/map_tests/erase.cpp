/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:04:52 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/21 09:51:56 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tests.hpp"

// typedef NAME_SPACE::map<char,int>::Tree Tree;

// void print2DUtil(Tree *root, int space)
// {
//     if (root == NULL)
//         return;
//     space += COUNT;
//     print2DUtil(root->right, space);
//     std::cout<<std::endl;
//     for (int i = COUNT; i < space; i++)
//         std::cout<<" ";
//     std::cout<< root->data.first << "\n";
//     print2DUtil(root->left, space);
// }

// void print2D(Tree *root)
// {
//     print2DUtil(root, 0);
// }

int main ()
{
    NAME_SPACE::map<char,int> mymap;
    NAME_SPACE::map<char,int>::iterator it;
    NAME_SPACE::map<char,int>::iterator end;

    // insert some values:
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;

    it=mymap.find('b');
    std::cout << it->first << std::endl;
    mymap.erase (it);                   // erasing by iterator

    mymap.erase ('c');                  // erasing by key

    it=mymap.find ('e');
    // end=mymap.find ('f');
    end = mymap.end();                // erasing by key
    mymap.erase (it, end);                  // erasing by range
    // show content:
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    return 0;
}