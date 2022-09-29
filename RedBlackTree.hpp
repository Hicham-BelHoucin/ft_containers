/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 10:58:42 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/26 17:35:02 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

# include <iostream>
# define BOLDBLACK	"\033[1m\033[30m"      /* Bold Black */
# define BOLDRED	"\033[1m\033[31m"      /* Bold Red */
# define RESET		"\033[0m"
# define COUNT 		15

typedef enum s_colors {
	BLACK = 0,
	RED,
} t_colors ;

typedef enum s_cases {
	LL = 1,
	RR,
	LR,
	RL,
} t_cases ;

template<typename T>
struct Node
{
	T             	data;
	int             color;
	Node    		*parent;
	Node    		*left;
	Node    		*right;

	Node(T data, int color, Node * parent)
	{
		this->data = data;
		this->color = color;
		this->parent = parent;
		this->left = NULL;
		this->right = NULL;
	}
	bool	isLeftChild() {
		return parent ? this == parent->left : false;
	}
	void	changeColor() {
		color = color == RED ? BLACK : RED;
	}
};

template<class T, //key_type/value_type
			class Compare, // key_compare/value_compare
			class Alloc > // allocator_type
class RedBlackTree
{
	public:
	typedef	Node<T>	*	Tree;
	typedef	T			value_type;
	Tree				root;
	int					rotations;

	RedBlackTree() : rotations(0), root(NULL)
	{
	}

	Tree rightRotate(Tree y)
	{
		if (!y->left)
			return y;
		Tree x = y->left;
		Tree T2 = x->right;

		// Perform rotation
		x->right = y;
		y->left = T2;
		// change parent
		x->parent = y->parent;
		y->parent = x;
		// Return new root
		return x;
	}

	Tree leftRotate(Tree x)
	{
		if (!x->right)
			return x;
		Tree y = x->right;
		Tree T2 = y->left;

		// Perform rotation
		y->left = x;
		x->right = T2;
		// change parent
		y->parent = x->parent;
		x->parent = y;
		// Return new root
		return y;
	}

	int		getRotationType(Tree root, value_type data)
	{
		Tree	newnode = NULL;

		if (root->left && root->left->data == data)
			newnode = root->left;
		else if (root->right && root->right->data == data)
			newnode = root->right;
		if (!newnode || !root)
			return 0;
		if (!root->isLeftChild() && !newnode->isLeftChild())
			return RR;
		else if (root->isLeftChild() && newnode->isLeftChild())
			return LL;
		else if (root->isLeftChild() && !newnode->isLeftChild())
			return LR;
		else if (!root->isLeftChild() && newnode->isLeftChild())
			return RL;
		return 0;
	}

	Tree	fixTree(Tree root, int & rotations, value_type data)
	{
		Tree	sibling = NULL;
		int		neededrotation = 0;

		if (!root)
			return root;
		if (root->parent)
			sibling = root->isLeftChild() ? root->parent->right : root->parent->left;
		if (!sibling || sibling->color == BLACK)
		{
			neededrotation = getRotationType(root, data);
			if (neededrotation == LR)
			{
				root = leftRotate(root);
				rotations = LL;
			}
			else if (neededrotation == RL)
			{
				root = rightRotate(root);
				rotations = RR;
			}
			else if (neededrotation != 0)
				rotations = neededrotation;
		}
		else if (sibling && sibling->color == RED)
		{
			root->changeColor();
			sibling->changeColor();
			if (root->parent->parent)
				root->parent->changeColor();
		}
		return root;
	}

	Tree	insertHelper(Tree root, value_type data, Tree parent, int & rotations)
	{
		bool	redconfilct = false;

		if (!root)
		{
			if (!parent)
				root = new Node<T>(data, BLACK, parent);
			else
				root = new Node<T>(data, RED, parent);
		}
		else if (root->data == data)
			return root;
		else if (root->data < data)
		{
			root->right = insertHelper(root->right, data, root, rotations);
			if (root->color == RED && root->right->color == RED)
			{
				redconfilct = true;
				data = root->right->data;
			}
		}
		else if (root->data > data)
		{
			root->left = insertHelper(root->left, data, root, rotations);
			if (root->color == RED && root->left->color == RED)
			{
				data = root->left->data;
				redconfilct = true;
			}
		}
		if (rotations == RR)
		{
			root = leftRotate(root);
			root->changeColor();
			if (root->left)
				root->left->changeColor();
			rotations = 0;
		}
		else if (rotations == LL)
		{
			root = rightRotate(root);
			root->changeColor();
			if (root->right)
				root->right->changeColor();
			rotations = 0;
		}
		if (redconfilct == true)
			root = fixTree(root, rotations, data);
		return root;
	}

	Tree	insert(Tree root, value_type data)
	{
		return insertHelper(root, data, NULL, rotations);
	}

	void	Inorder(Tree root, int space)
	{
		if (!root)
			return ;
		Inorder(root->right, space + COUNT);
		for (int i = 0; i < space; i++)
			std::cout << " ";
		std::cout << (root->color == BLACK ? BOLDBLACK : BOLDRED) << root->data << RESET;
		std::cout << std::endl;
		Inorder(root->left, space + COUNT);
	}
};

#endif // RED_BLACK_TREE_HPP