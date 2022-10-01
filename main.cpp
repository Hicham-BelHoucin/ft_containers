/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:53:34 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/30 13:09:29 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/BinarySearchTree.hpp"
# define COUNT 5
typedef ft::BinarySearchTree<int, int>::Tree Tree;

void	Inorder(Tree root, int space)
{
	if (!root)
		return ;
	Inorder(root->right, space + COUNT);
	for (int i = 0; i < space; i++)
		std::cout << " ";
	std::cout << root->data.first;
	std::cout << std::endl;
	Inorder(root->left, space + COUNT);
}

#include <vector>

int main(void)
{
    // ft::BinarySearchTree<int, int> BST;

	// int i = 3;
	// BST.root = BST.insert(BST.root, ft::pair<int,int>(i,i));
	// BST.root = BST.insert(BST.root, ft::pair<int,int>(i,i));
	// BST.root = BST.insert(BST.root, ft::pair<int,int>(i,i));
	// for (int i = 0; i < 8; i++)
	// 	BST.root = BST.insert(BST.root, ft::pair<int,int>(i,i));

	// Inorder(BST.root, 0);

	std::vector<int>		v(100, 2);

	std::vector<int>::iterator it = v.begin();
	std::vector<int>::const_iterator it1 = v.begin();

	if (it == it1)
		std::cout << "hello" << std::endl;

}