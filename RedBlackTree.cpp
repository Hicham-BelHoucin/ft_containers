/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:44:18 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/02 12:27:50 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

# define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
# define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
# define RESET   "\033[0m"
# define COUNT 5

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

struct Node
{
	int             data;
	int             color;
	Node    		*parent;
	Node    		*left;
	Node    		*right;

	Node(int data, int color, Node * parent)
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

/*
	insertion :
		1 -> insert like in normal binary search tree
		2 -> if newnode is not root node we color it with red
		3 -> if newnode is root node we color it with black
		4 -> if newnode's parent is red then we have red red conflict and we need to fix it :
			to fix it need to check color of it parent's sibling :
				1 -> if color of it's parent's sibling is black or null :
					- if we have left right insertion condition we need to do a left right rotation and recolor parent and grandparent
					- if we have right right insertion condition we need to do a left rotation and recolor parent and grandparent
					- if we have left left insertion condition we need to do a right rotation and recolor parent and grandparent
					- if we have right left insertion condition we need to do a right left rotation and recolor parent and grandparent
				2 -> if color of it's parent sibling is red :
					- recolor parent and sibling and if grandparent of newnode ids not root node then recolor it and recheck with grandparent .
*/

typedef	Node*	Tree;

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

/*
					    x
					  /  \
					nil  16
*/

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

/*
	cases:
		1 -> if root is rightchild and newnode is rightchild :
			you will need a RR rotation
		2 -> if root is leftchild and newnode is leftchild :
			you will need a LL rotation
		3 -> if root is leftchild and newnode is rightchild:
			you will need LR rotation
		3 -> if root is rightchild and newnode is leftchild:
			you will need RL rotation
*/

int		getRotationType(Tree root, int data)
{
	Tree	newnode;

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

Tree	fixTree(Tree root, int & rotations, int data)
{
	Tree	sibling = NULL;
	int		neededrotation;

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
		else
		{
			rotations = neededrotation;
			// puts("hi");
		}
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

Tree	insert(Tree root, int data, Tree parent, int & rotations)
{
	bool	redconfilct = false;
	if (!root)
	{
		if (!parent)
			root = new Node(data, BLACK, parent);
		else
			root = new Node(data, RED, parent);
	}
	else if (root->data == data)
		return root;
	else if (root->data < data)
	{
		root->right = insert(root->right, data, root, rotations);
		if (root->color == RED && root->right->color == RED)
		{
			redconfilct = true;
			data = root->right->data;
		}
	}
	else if (root->data > data)
	{
		root->left = insert(root->left, data, root, rotations);
		if (root->color == RED && root->left->color == RED)
		{
			redconfilct = true;
			data = root->left->data;
		}
	}
	if (rotations == RR)
	{
		root = leftRotate(root);
		root->changeColor();
		root->left->changeColor();
		rotations = 0;
	}
	else if (rotations == LL)
	{
		root = rightRotate(root);
		root->changeColor();
		root->right->changeColor();
		rotations = 0;
	}
	if (redconfilct == true)
		root = fixTree(root, rotations, data);
	return root;
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

bool isHeightBalanced(Tree root, int &rootMax)
{
    // Base case
    if (root == nullptr) {
        return true;
    }

    // to hold the maximum height of the left and right subtree
    int leftMax = 0, rightMax = 0;

    // proceed only if both left and right subtrees are balanced
    if (isHeightBalanced(root->left, leftMax) &&
        isHeightBalanced(root->right, rightMax))
    {
        // calculate the minimum and maximum height of the left and right subtree
        int rootMin = std::min(leftMax, rightMax) + 1;
        rootMax = std::max(leftMax, rightMax) + 1;

        // return true if the root node is height-balanced
        return (rootMax <= 2*rootMin);
    }

    // return false if either left or right subtree is unbalanced
    return false;
}


// A wrapper over isBalancedUtil()
bool isBalanced(Tree root)
{
    int maxh, minh;
    // return isBalancedUtil(root, maxh, minh);
    return isHeightBalanced(root, maxh);
}

int main(void)
{
	Tree root = NULL;
	int j = 0;
	// root = insert(root, 10, root, i);
	// root = insert(root, 18, root, i);
	// root = insert(root, 7, root, i);
	// root = insert(root, 15, root, i);
	// root = insert(root, 16, root, i);
	// root = insert(root, 30, root, i);
	// root = insert(root, 25, root, i);
	// root = insert(root, 40, root, i);
	// root = insert(root, 60, root, i);
	// root = insert(root, 2, root, i);
	// root = insert(root, 1, root, i);
	// root = insert(root, 70, root, i);

	for (int i = 0; i < 20; i--)
		root = insert(root, std::rand() % 1000 + 1, root, j);

	// Inorder(root, 0);
	isBalanced(root) ? std::cout << "Balanced\n" : std::cout << "Not Balanced\n";
	return 0;
}