/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:44:18 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/11 13:44:18 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

# define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
# define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define RED 1
#define BLACK 0

struct RedBlackTree
{
	int             data;
	int             color;
	RedBlackTree    *parent;
	RedBlackTree    *left;
	RedBlackTree    *right;

	RedBlackTree(int data, int color)
	{
		this->data = data;
		this->color = color;
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
	}
};

RedBlackTree    *&siblingColor(RedBlackTree * node)
{
	RedBlackTree * parent;
	
	parent = node->parent;
	// std::cout << 'n' << parent->right->data << std::endl;
	// std::cout << parent->left->data << std::endl;
	// std::cout << parent->right->data << std::endl;
	if (parent->left == node)
		return parent->right;
	return parent->left;
}

void    inorder(RedBlackTree * root)
{
	if (root == NULL)
		return ;
	inorder(root->left);
	// std::cout << "\033[0m";
	std::cout << (!root->parent ? "root : " : "child : ") << (root->color ? BOLDRED : BOLDBLACK) << root->data << std::endl;
	// std::cout << (root->color ? "RED" : "BLACK") << std::endl;
	std::cout << "\033[0m";
	// if (root->parent)
	//     std::cout << "preant : " << root->parent->data << std::endl;
	inorder(root->right);
}
#define COUNT 5
void print2DUtil(RedBlackTree *root, int space)
{
	if (root == NULL)
		return;
	space += COUNT;
	print2DUtil(root->right, space);
	std::cout<<std::endl;
	for (int i = COUNT; i < space; i++)
		std::cout<<" ";
	// std::cout << root->color << '~' << root->data << std::endl;
	std::cout<< (root->color ? BOLDRED : BOLDBLACK) << root->data << "\033[0m" << "\n";
	print2DUtil(root->left, space);
}

void print2D(RedBlackTree *root)
{
	print2DUtil(root, 0);
}

void    blanceTree(RedBlackTree * &parent, RedBlackTree * &newNode, RedBlackTree * &sibling)
{
	/*
		if parent of new node is RED , then check the color of parent's sibling of new node :
			1 - if color is black or null then suitable a rotation and recolor.
			2 - if color is red then recolor and check if parent's parent of new node id not root 
				node then recolor and recheck .
	*/
	if (!parent || !newNode)
			return ;
	if (parent->color == RED)
	{
		if (!sibling || sibling->color == BLACK)
		{
			// suitable a rotation and recolor
			puts("suitable a rotation and recolor");
		std::cout << newNode->data << std::endl;
		}
		else if (sibling && sibling->color == RED)
		{
			puts("hello");
			/*
				recolor and check if parent's parent of new node id not root 
				node then recolor and recheck .
			*/
			sibling->color = BLACK;
			parent->color = BLACK;
			if (parent->parent)
			{
				parent->parent->color = parent->parent->color ? BLACK : RED;
				blanceTree(parent->parent->parent, parent->parent, siblingColor(parent->parent)); 
			}
		}
	}
}

void insert(RedBlackTree *&root, int data)
{
	if (!root)
		root = new RedBlackTree(data, BLACK);
	if (root->data < data)
	{
		insert(root->right, data);
		root->right->parent = root;
		root->right->color = RED;
		blanceTree(root, root->right, siblingColor(root->right));
	}
	else if (root->data > data)
	{
		insert(root->left, data);
		root->left->parent = root;
		root->left->color = RED;
		blanceTree(root, root->left, siblingColor(root->left));
	}
}

int main(void)
{
	RedBlackTree *root = NULL;

	insert(root, 10);
	insert(root, 18);
	insert(root, 7);
	insert(root, 15);
	print2D(root);
	// inorder(root);
	// for (int i = 0; i < 5; i++)
		// root = insert(root, i);
	// std::cout << "done" << std::endl;
	// inorder(root);
}