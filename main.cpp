/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:53:34 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/18 15:18:02 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "utils/pair.hpp"
#include "utils/make_pair.hpp"

#include <iostream>     // std::cout

int main () 
{
    ft::pair <std::string,double> product1;
    ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
    ft::pair <std::string,double> product3 (product2);          // copy constructor

    product1 = ft::make_pair(std::string("lightbulbs"),0.99);
    product2.first = "shoes";
    product2.second = 39.90;

    std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
    std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
    std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
    return 0;
}
*/
/*
int main ()
{
  std::pair<int,char> foo (10,'z');
  std::pair<int,char> bar (90,'a');

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

  return 0;
}
*/

#include "containers/map.hpp"
# define COUNT 4
typedef ft::BinarySearchTree<int, int> Tree;

void print2DUtil(Tree *root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    std::cout<<std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout<<" ";
    std::cout<< root->data.first << "\n";
    print2DUtil(root->left, space);
}

void print2D(Tree *root)
{
    print2DUtil(root, 0);
}

// int main(void)
// {
// 	Tree	*	root = new Tree(ft::pair<int, int>(14, 14));
// 	int myints[] = {14, 17, 11, 7, 53, 4, 13, 12, 8, 60, 19, 16, 20};

// 	for (int i = 1; i < 13; i++)
// 		root = root->insert(root, ft::pair<int, int>(myints[i], myints[i]));
// 	print2D(root);
// 	// std::cout << root->find(root, 53)->data.first << std::endl;
// 	return 0;
// }


#include <map>
bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main ()
{
    ft::map<int,int> first;
    first[2]=2;
    first[5]=5;
    first[4]=4;
    first[3]=3;
    // first['d']=70;
	// for (int i = 1; i < 10; i++)
	// 	first[i] = i;
    print2D(first.root);

    return 0;
}