/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:53:34 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/25 10:14:49 by hbel-hou         ###   ########.fr       */
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

int main(void)
{
    ft::BinarySearchTree<int, int> BST;

	int i = 3;
	BST.root = BST.insert(BST.root, ft::pair<int,int>(i,i));
	BST.root = BST.insert(BST.root, ft::pair<int,int>(i,i));
	BST.root = BST.insert(BST.root, ft::pair<int,int>(i,i));
	for (int i = 0; i < 8; i++)
		BST.root = BST.insert(BST.root, ft::pair<int,int>(i,i));

	Inorder(BST.root, 0);
}