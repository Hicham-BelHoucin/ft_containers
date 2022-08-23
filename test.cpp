/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:38:48 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/23 15:03:43 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <map>
#include"containers/map.hpp"
#define COUNT 4
#define MAX 9

#define RR "RR"
#define RL "RL"
#define LL "LL"
#define LR "LR"


struct node {
	int				key;
	node			*right;
	node			*left;
};

node 	*newNode(int key)
{
	node	*newnode;

	newnode = new node();
	newnode->key = key;
	newnode->right = NULL;
	newnode->left = NULL;
	return newnode;
}

int height(node *node)
{
	int left_side;
	int right_side;

	if(node == NULL)
		return 0;
	left_side = height(node -> left);
	right_side = height(node -> right);
	return std::max(left_side, right_side) + 1;
}

int getBalance(node *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}


node *leftRotate(node *root)
{
    node *child;
    node *T2;

	child = root->right;
	T2 = child->left;
    child->left = root;
    root->right = T2;
    return child;
}

node *rightRotate(node *root)
{
    node *child;
    node *T2;

	child = root->left;
	T2 = child->right;
    child->right = root;
    root->left = T2;
    return child;
}


node	*balanceTree(node *root, int key)
{
	int balance;

	balance = getBalance(root);
	if (balance > 1 && key < root->left->key)
        return rightRotate(root);
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);
    if (balance > 1 && key > root->left->key)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
	return root;
}

node	*insert(node *root, int key)
{
	if (root == NULL)
		root = newNode(key);
	else if (key < root->key)
		root->left = insert(root->left, key);
	else if (key > root->key)
		root->right = insert(root->right, key);
	else
		return root;
	return root;
}


void print2DUtil(node *root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    std::cout<<std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout<<" ";
    std::cout<< root->key << "\n";
    print2DUtil(root->left, space);
}

void print2D(node *root)
{
    print2DUtil(root, 0);
}


// int main(void)
// {
// 	node	*root = NULL;
// 	node	*wantedNode;
// 	int myints[] = {14, 17, 11, 7, 53, 4, 13, 12, 8, 60, 19, 16, 20};

// 	for (int i = 0; i < 9; i++)
// 		root = insert(root, myints[i]);
// 	print2D(root);
// 	return 0;
// }



int main(void)
{
	// std::vector<std::string>::iterator iter1;
	// std::vector<std::string> vector;
	std::map<int, int> map;
	std::map<int, int>::iterator begin;
	std::map<int, int>::iterator end;

	map[12] = 58;
	map[13] = 12;
	map[11] = 13;
	map[15] = 42;

	begin = map.begin();
	end = map.end();

	// (*begin).first;
	
	std::cout << (*end).first << std::endl;
}