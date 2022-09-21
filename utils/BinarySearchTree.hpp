/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:21:30 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/20 15:37:55 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

#include <iostream>
#include "./pair.hpp"
#include "./Node.hpp"

namespace ft
{
    template<typename key_type, typename value_type, typename Compare = std::less<key_type>, 
		typename Alloc = std::allocator<Node<ft::pair<const key_type, value_type> > > >
	struct BinarySearchTree {
		typedef ft::pair<const key_type, value_type>			dataType;
		typedef typename Alloc::template rebind<Node<ft::pair<const key_type, value_type> > >::other newAlloc;
		typedef	typename				newAlloc::pointer			Tree;
		typedef typename Alloc::template rebind<const Node<ft::pair<const key_type, value_type> > >::other constnewAlloc;
		typedef	typename				constnewAlloc::pointer			constTree;
		typedef	size_t											size_type;
		newAlloc													alloc;
		Tree													root;

		
		BinarySearchTree(const Alloc & allocator = newAlloc()) : alloc(allocator), root(NULL) {}


		size_t      height(Tree root)
		{
			if (!root)
				return 0;
			return root->height;
		}


		size_type	max_size(void)
		{
			return alloc.max_size();
		}

		int		getBlanceFactor(Tree root)
		{
			if (!root)
				return 0;
			return height(root->left) - height(root->right);
		}

		Tree rightRotate(Tree y)
		{
			Tree x = y->left;
			Tree T2 = x->right;

			// Perform rotation
			x->right = y;
			y->left = T2;

			// Update heights
			y->height = std::max(height(y->left),
							height(y->right)) + 1;
			x->height = std::max(height(x->left),
							height(x->right)) + 1;

			// Return new root
			return x;
		}

		Tree leftRotate(Tree x)
		{
			Tree y = x->right;
			Tree T2 = y->left;

			// Perform rotation
			y->left = x;
			x->right = T2;

			// Update heights
			x->height = std::max(height(x->left),
							height(x->right)) + 1;
			y->height = std::max(height(y->left),
							height(y->right)) + 1;

			// Return new root
			return y;
		}

		Tree  min(Tree root)
		{
			if (!root->left)
				return root;
			return min(root->left);
		}

		Tree  min(Tree root) const
		{
			if (!root->left)
				return root;
			return min(root->left);
		}

		Tree  max(Tree root)
		{
			if (!root->right)
				return root;
			return max(root->right);
		}
		
		constTree  max(constTree root)
		{
			if (!root->right)
				return root;
			return max(root->right);
		}

		key_type	lowerBound(Tree root, key_type key)
		{
			Tree             		_min;
			Tree             		next;
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

		key_type	upperBound(Tree root, key_type key)
		{
			if (find(root, key))
				return findSuccessor(root, key)->data.first;
			return lowerBound(root, key);
		}

		Tree	find(Tree root, key_type key) const
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

		constTree	find(constTree root, key_type key) const
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

		void    clear(Tree root)
		{
			if (!root)
				return ;
			clear(root->left);
			clear(root->right);
			delete root;
			return;
		}

		constTree  findPredecessor(constTree  root, key_type key)
		{
			constTree  Predecessor;
			constTree  current;
			constTree  node;

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
		Tree  findPredecessor(Tree  root, key_type key)
		{
			Tree  Predecessor;
			Tree  current;
			Tree  node;

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

		Tree  findSuccessor(Tree  root, key_type key)
		{
			Tree  current;
			Tree  Successor;
			Tree  node;

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
		constTree  findSuccessor(constTree  root, key_type key)
		{
			constTree  current;
			constTree  Successor;
			constTree  node;

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

		Tree	Delete(Tree  root, key_type key)
		{
			Tree temp;
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

		Tree	DeleteRange(Tree  root, key_type min, key_type max)
		{
			Tree  temp;
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

		Tree	createNewNode(const dataType & Data)
		{
			Tree	temp;
			temp = alloc.allocate(1);
			alloc.construct(temp, Node<dataType>(ft::pair<key_type, value_type>(Data)));
			return temp;
		}

		void	Inorder(Tree root) const
		{
			if (!root)
				return ;
			Inorder(root->left);
			std::cout << root->data.first << std::endl;
			Inorder(root->right);
		}

		Tree cloneBinaryTree(Tree root)
		{
			// base case
			if (root == NULL) {
				return NULL;
			}
		
			// create a new node with the same data as the root node
			// Tree root_copy = new Node<dataType>(root->data);
			Tree root_copy = createNewNode(root->data);
		
			// clone the left and right subtree
			root_copy->left = cloneBinaryTree(root->left);
			root_copy->right = cloneBinaryTree(root->right);
		
			// return cloned root node
			return root_copy;
		}

		Tree	insert(Tree root, dataType data)
		{
			int		blanceFactor;

			if (!root)
				return createNewNode(data);
			else if (root->data.first == data.first)
				return root;
			else if (root->data.first < data.first)
				root->right = insert(root->right, data);
			else if (root->data.first > data.first)
				root->left = insert(root->left, data);
			root->height = 1 + std::max(height(root->left), height(root->right));
			blanceFactor = getBlanceFactor(root);
			if (blanceFactor > 1 && data.first < root->left->data.first)
				return rightRotate(root);
			if (blanceFactor < -1 && data.first > root->right->data.first)
				return leftRotate(root);
			if (blanceFactor > 1 && data.first > root->left->data.first)
			{
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
			if (blanceFactor < -1 && data.first < root->right->data.first)
			{
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
			root->end = createNewNode(dataType());
			return root;
		}
	};
}

#endif // BINARY_SEARCH_TREE_HPP