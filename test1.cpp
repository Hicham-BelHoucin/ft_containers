/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:07:39 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/29 13:47:51 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/BinarySearchTree.hpp"
#include "utils/pair.hpp"
#include <map>

using namespace ft;

int main(void)
{
	BinarySearchTree<int, int> *root = new BinarySearchTree<int, int>(pair<int, int>(5, 5));
	std::map<int ,int> map;
	int	rejectedints[] = {4, 6, 8, 9, 2};

	for (int i = 1; i < 5; i++)
		if (i != 3)
		(root = root->insert(root, pair<int, int>(i, std::rand() % 30)));
	for (int i = 1; i < 5; i++)
		if (i != 3)
			(map.insert(std::pair<int, int>(i, std::rand() % 30)));
	root->Inorder(root);
	std::cout << root->lowerBound(root, 2) << std::endl;
	std::cout << map.lower_bound(2)->first << std::endl;
	return 0;
}