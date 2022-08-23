/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:53:34 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/23 15:04:42 by hbel-hou         ###   ########.fr       */
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
#include <iostream>
#include <stack>
#include "utils/iterator_traits.hpp"
#include "utils/enable_if.hpp"
#include "utils/is_integral.hpp"
#include "utils/pair.hpp"
#include "utils/make_pair.hpp"

#include "containers/map.hpp"
// #include "containers/Vector.hpp"
// #include "containers/Stack.hpp"
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

// void    Inorder(Tree *root, ft::vector<Tree> &vector)
// {
//     if (!root)
//         return ;
//     Inorder(root->left, vector);
//     vector.push_back(*root);
//     Inorder(root->right, vector);
//     return;
// }

// struct mini_iterator {
// 	ft::stack<Tree * > stack;
// 	Tree * current;

// 	mini_iterator() : current(NULL) {}
// 	mini_iterator(Tree * root) : current(root) {
// 		setcurrent();
// 	}
// 	void	setcurrent() {
// 		while (current -> left) {
// 			stack.push(current);
// 			current = current -> left;
// 		}
// 	}
// 	Tree * begin () {
// 		return current;
// 	}
// 	Tree * end () {
// 		return nullptr;
// 	}
// 	Tree & operator++() {

// 		if (current->right)
// 			current = current->right;
// 		else
// 		{
// 			if (!stack.size())
// 				current = nullptr;
// 			else
// 				current = stack.top();
// 			stack.pop();
// 		}
// 		return *current;
// 	}
// 	ft::pair<int ,int> & operator*() {
// 		return current->data;
// 	}
// 	ft::pair<int ,int> * operator->() const
// 	{
// 		return &current->data;
// 	}
// 	friend bool operator!= (const mini_iterator& lhs, const mini_iterator& rhs)
// 	{
// 		return lhs.current != rhs.current;
// 	}
// };


Tree * findPredecessor(Tree * root, int key)
{
	Tree * Predecessor;
	Tree * current;
	Tree * Parent;

	current = root->find(root, key);
	if (!current)
		return NULL;
	if (current->left)
		return root->max(current->left);
	Predecessor = NULL;
	Parent = root;
	while (Parent != current)
	{
		if (*current > *Parent)
		{
			Predecessor = Parent;
			Parent = Parent->right;
		}
		else
			Parent = Parent->left;
	}
	return Predecessor;
}

Tree * findSuccessor(Tree * root, int key)
{
	Tree * current;
	Tree * Successor;
	Tree * Parent;

	current = root->find(root, key);
	if (!current)
		return NULL;
	if (current->right)
		return root->min(current->right);
	Successor = NULL;
	Parent = root;
	while (Parent != current)
	{
		if (*current < *Parent)
		{
			Successor = Parent;
			Parent = Parent->left;
		}
		else
			Parent = Parent->right;
	}
	return Successor;
}

int main ()
{
    // std::map<int,int> first;
    // // std::map<int,int>::iterator it;
	int myints[] = {14, 17, 11, 7, 53, 4, 13, 12, 8};
	Tree * Predecessor = NULL;
	Tree * Successor = NULL;
    // ft::vector<Tree> vector;
    // first[2]=2;
    // first[5]=5;
    // first[4]=4;
    // first[3]=3;
    // it = first.begin();
    // it ++;
    // it ++;
    // it --;
    // std::cout << it->first << std::endl;
    // second[2]=2;
    // second[5]=5;
    // second[4]=4;
	// mini_iterator end = mini_iterator(second.root).end();
	// mini_iterator end = second.root;
    // second[3]=3;
    ft::map<int,int> second;
    ft::map<int,int>::iterator it;
    ft::map<int,int>::iterator end;
	for (int i = 0; i < 9 ;i ++)
		second[myints[i]] = myints[i];
	// second.root = second.root->insert(second.root, ft::pair<int ,int >(50, 50));
	// second.root = second.root->insert(second.root, ft::pair<int ,int >(30, 30));
    // second.root = second.root->insert(second.root, ft::pair<int ,int >(20, 20));
    // second.root = second.root->insert(second.root, ft::pair<int ,int >(40, 40));
    // second.root = second.root->insert(second.root, ft::pair<int ,int >(70, 70));
    // second.root = second.root->insert(second.root, ft::pair<int ,int >(60, 60));
    // second.root = second.root->insert(second.root, ft::pair<int ,int >(80, 80));
	// int key;

	it = second.begin();
	it++;
	it--;
	// std::cout << (*it).first << std::endl;
	end = second.end();
	while (it != end)
	{
		std::cout << it->first << std::endl;
		it++;
	}
	// // it++;
	// std::cout << it->data.first << std::endl;
	// key = 12;
	// Predecessor = findPredecessor(second.root, key);
	// Successor =  findSuccessor(second.root, key);
	// if (Predecessor)
	// 	std::cout << "Predecessor is : " << Predecessor->data.first << std::endl;
	// if (Successor)
	// 	std::cout << "Successor is : " << Successor->data.first << std::endl;
	// std::cout << second.root->min(second.root)->data.first;
	// std::cout << " > " << key << " > ";
	// std::cout << second.root->max(second.root)->data.first << std::endl;
	// print2D(second.root);
	// mini_iterator begin(second.root);
	// while (begin.current != begin.end())
	// {
	// 	std::cout << (*begin).first << std::endl;
	// 	++begin;
	// }

	// std::cout << "stack :: " << begin.stack.top()->data.first << std::endl;
	// std::cout << "iter :: " << begin.current->data.first << std::endl;
	// while (!it.stack.empty())
	// {
	// 	// std::cout << it.stack.size() << std::endl;
	// 	it.stack.pop();
	// }
    // // clear(second.root);
    // // first['d']=70;
	// for (int i = 0; i < vector.size(); i++)
    //     std::cout << vector[i].data.first << std::endl;
	// for (int i = 0; i < vector.size(); i++)
    //     vector[i].data.second = 15;
	// for (int i = 0; i < vector.size(); i++)
    //     std::cout << vector[i].data.second << std::endl;
    // std::cout << "****************" << std::endl;
    // for (std::pair<int ,int> it : first)
    //     std::cout << it.first << std::endl;
    return 0;
}