/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:38:48 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/18 10:15:59 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <map>
#include "./utils/pair.hpp"

template<typename key_type, typename value_type, typename Compare = std::less<key_type> >
struct BinarySearchTree {
	ft::pair<const key_type, value_type> 	data;
	BinarySearchTree						*right;
	BinarySearchTree						*left;
	BinarySearchTree						*end;

	BinarySearchTree()
	{
		this->data = ft::pair<const key_type, value_type>();
		this->right = NULL;
		this->left = NULL;
		this->end = NULL;
	}
	BinarySearchTree(ft::pair<key_type, value_type> data)
	{
		this->data = data;
		this->right = NULL;
		this->left = NULL;
		this->end = NULL;
	}	
	friend bool operator== (const BinarySearchTree& lhs, const BinarySearchTree& rhs)
	{
		return lhs.data.first == rhs.data.first;
	}
	friend bool operator> (const BinarySearchTree& lhs, const BinarySearchTree& rhs)
	{
		return lhs.data.first > rhs.data.first;
	}
	friend bool operator< (const BinarySearchTree& lhs, const BinarySearchTree& rhs)
	{
		return lhs.data.first < rhs.data.first;
	}
};
typedef int key_type;
typedef int value_type;

int			hieght(BinarySearchTree<key_type, value_type>	*root)
{
	int		leftSubTree;
	int		rightSubTree;

	if (root == NULL)
		return 0;
	leftSubTree = hieght(root->left);
	rightSubTree = hieght(root->right);
	return std::max(leftSubTree, rightSubTree) + 1;
}
int			getBalanceFactor(BinarySearchTree<key_type, value_type> *root)
{
	if (root == NULL)
		return 0;
	return hieght(root->left) - hieght(root->right);
}

BinarySearchTree<key_type, value_type> * leftRotate(BinarySearchTree<key_type, value_type> * root)
{
	BinarySearchTree<key_type, value_type> * first;
	BinarySearchTree<key_type, value_type> * second;

	first = root->right;
	second = first->left;
	first->left = root;
	root->right = second;
	return first;
}
BinarySearchTree<key_type, value_type> * rightRotate(BinarySearchTree<key_type, value_type> * root)
{
	BinarySearchTree<key_type, value_type> * first;
	BinarySearchTree<key_type, value_type> * second;

	first = root->left;
	second = first->right;
	first->right = root;
	root->left = second;
	return first;
}
BinarySearchTree<key_type, value_type>	*balanceTree(BinarySearchTree<key_type, value_type> *root, ft::pair<key_type, value_type> data)
{
	int balance;

	balance = getBalanceFactor(root);
	if (balance > 1 && data.first < root->data.first)
		return rightRotate(root);
	if (balance < -1 && data.first > root->data.first)
		return leftRotate(root);
	if (balance > 1 && data.first > root->data.first)
	{
		root->left =  leftRotate(root->left);
		return rightRotate(root);
	}
	if (balance < -1 && data.first < root->data.first)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
BinarySearchTree<key_type, value_type>	*find(BinarySearchTree<key_type, value_type> *root, key_type key)
{
	if (root == NULL)
		return NULL;
	if (root->data.first == key)
		return root;
	if (key < root->data.first)
		root = find(root->left, key);
	else if (key > root->data.first)
		root = find(root->right, key);
	return root;
}
void    clear(BinarySearchTree<key_type, value_type> *root)
{
	if (!root)
		return ;
	clear(root->left);
	clear(root->right);
	delete root;
	return;
}
BinarySearchTree<key_type, value_type> * min(BinarySearchTree<key_type, value_type> *root)
{
	if (!root->left)
		return root;
	return min(root->left);
}
BinarySearchTree<key_type, value_type> * max(BinarySearchTree<key_type, value_type> *root)
{
	if (!root->right)
		return root;
	return max(root->right);
}
BinarySearchTree<key_type, value_type> * findPredecessor(BinarySearchTree<key_type, value_type> * root, key_type key)
{
	BinarySearchTree<key_type, value_type> * Predecessor;
	BinarySearchTree<key_type, value_type> * current;
	BinarySearchTree<key_type, value_type> * node;

	current = find(root, key);
	if (!current)
		return NULL;
	if (current->left)
		return max(current->left);
	Predecessor = NULL;
	node = root;
	while (node != current)
	{
		if (*current > *node)
		{
			Predecessor = node;
			node = node->right;
		}
		else
			node = node->left;
	}
	return Predecessor;
}
BinarySearchTree<key_type, value_type> * findSuccessor(BinarySearchTree<key_type, value_type> * root, key_type key)
{
	BinarySearchTree<key_type, value_type> * current;
	BinarySearchTree<key_type, value_type> * Successor;
	BinarySearchTree<key_type, value_type> * node;

	current = find(root, key);
	if (!current)
		return NULL;
	if (current->right)
		return min(current->right);
	Successor = root->end;
	node = root;
	while (node != current)
	{
		if (*current < *node)
		{
			Successor = node;
			node = node->left;
		}
		else
			node = node->right;
	}
	return Successor;
}
key_type	lowerBound(BinarySearchTree<key_type, value_type> *root, key_type key)
{
	BinarySearchTree<key_type, value_type> 		*_min;
	BinarySearchTree<key_type, value_type> 		*next;
	key_type 				next_key;

	if (find(root, key))
		return key;
	_min = min(root);
	next = _min;
	next_key = next->data.first;
	while (next != root->end && next->data.first < key && key > _min->data.first)
	{
		next = findSuccessor(root, next->data.first);
		next_key = next->data.first;
	}
	if (next_key < key)
		next_key = key;
	return next_key;
}
key_type	upperBound(BinarySearchTree<key_type, value_type> *root, key_type key)
{
	if (find(root, key))
		return findSuccessor(root, key)->data.first;
	return lowerBound(root, key);
}

BinarySearchTree<key_type, value_type>	*Delete(BinarySearchTree<key_type, value_type> * root, key_type key)
{
	BinarySearchTree<key_type, value_type> *temp;
	if (!root)
		return NULL;
	if (key < root->data.first)
		root->left = Delete(root->left, key);
	else if (key > root->data.first)
		root->right = Delete(root->right, key);
	if (root->data.first == key)
	{
		if (!root->left && !root->right)
		{
			delete root;
			root = NULL;
		}
		else if (root->right && !root->left)
		{
			temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->left && !root->right)
		{
			temp = root;
			root = root->left;
			delete temp;
		}
		else
		{
			temp = min(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data.first);
		}
	}
	return root;
}
BinarySearchTree<key_type, value_type>	*DeleteRange(BinarySearchTree<key_type, value_type> * root, key_type min, key_type max)
{
	BinarySearchTree<key_type, value_type> * temp;
	key_type next;
	if (min == max)
		return Delete(root, max);
	temp = findSuccessor(root, min);
	if (!temp)
		return root;
	next = temp->data.first;
	root = Delete(root, min);
	root = DeleteRange(root, next, max);
	return root;
}

void	Inorder(BinarySearchTree<key_type, value_type> * root)
{
	if (!root)
		return ;
	if (root->left)
		Inorder(root->left);
	std::cout << "key : " << root->data.first << std::endl;
	std::cout << "value : " << root->data.second << std::endl;
	std::cout << "/*******************\\" << std::endl;
	if (root->right)
		Inorder(root->right);
}

BinarySearchTree<key_type, value_type>	*DuplicateTree(BinarySearchTree<key_type, value_type> * newRoot, BinarySearchTree<key_type, value_type> * root)
{
	if (!root)
		return NULL;
	newRoot = new BinarySearchTree<key_type, value_type>(root->data);
	newRoot->left = DuplicateTree(newRoot->left, root->left);
	newRoot->right = DuplicateTree(newRoot->right, root->right);
	return newRoot;
}

typedef BinarySearchTree<key_type, value_type> Tree;

void	insert(BinarySearchTree<key_type, value_type>* &root, ft::pair<key_type, value_type> data)
{
    Tree *curr = root;
 
    // pointer to store the parent of the current Tree
    static Tree *parent = NULL;
 
    // if the tree is empty, create a new node and set it as root
    if (root == NULL)
    {
        root = new Tree(data);
        return;
    }
 
    // traverse the tree and find the parent node of the given key
	if (parent == NULL){

		while (curr != NULL)
		{
			// update the parent to the current node
			parent = curr;
	
			// if the given key is less than the current node, go to the
			// left subtree; otherwise, go to the right subtree.
			if (data.first < curr->data.first) {
				curr = curr->left;
			}
			else {
				curr = curr->right;
			}
		}
	}
	if (data.first == parent->data.first)
		return ;
    // construct a node and assign it to the appropriate parent pointer
    if (data.first < parent->data.first) {
        parent->left = new Tree(data);
		parent = parent->left;
    }
    else if (!(data.first == parent->data.first))
	{
        parent->right = new Tree(data);
		parent = parent->right;
    }
	
}

void print2DUtil(Tree *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += 5;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current Tree after space
    // count
    std::cout <<std::endl;
    for (int i = 5; i < space; i++)
        std::cout <<" ";
    std::cout << root->data.first <<"\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(Tree *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

int main(void)
{
	BinarySearchTree<key_type, value_type> *root = new BinarySearchTree<key_type, value_type>(ft::pair<key_type, value_type>(1,1));

	for (int i = 1; i < 100; i++)
		insert(root, ft::pair<key_type, value_type>(i, std::rand() % 25));
	// Inorder(root);
	print2D(root);
	return 0;
}
