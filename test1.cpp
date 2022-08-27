/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:07:39 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/26 10:36:48 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/BinarySearchTree.hpp"
#include "utils/pair.hpp"

using namespace ft;

int main(void)
{
	BinarySearchTree<int, int> *root = new BinarySearchTree<int, int>(pair<int, int>(5, 5));
	BinarySearchTree<int, int> *second;

	for (int i = 1; i < 10; i++)
		root = root->insert(root, pair<int, int>(i, std::rand() % 30));
	root = root->DeleteRange(root, 2, 4);
	second = root->DuplicateTree(second, root);
	// root->Inorder(second);
	root->Inorder(second);
	return 0;
}