/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:21:30 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/05 10:45:36 by hbel-hou         ###   ########.fr       */
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
		typedef ft::pair<const key_type, value_type>														dataType;
		typedef typename Alloc::template rebind<Node<ft::pair<const key_type, value_type> > >::other 		newAlloc;
		typedef	typename				newAlloc::pointer													Tree;
		typedef	typename				newAlloc::const_pointer												constTree;
		typedef	size_t																						size_type;
		newAlloc																							alloc;
		Tree																								root;


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

		Tree rightRotate(Tree root)
		{
			Tree new_root;
			Tree child;

			// init
			new_root = root->left;
			child = new_root->right;
			// Perform rotation
			new_root->right = root;
			root->left = child;
			// Update heights
			root->height = std::max(height(root->left), height(root->right)) + 1;
			new_root->height = std::max(height(new_root->left), height(new_root->right)) + 1;
			// Return new root
			return new_root;;
		}

		Tree leftRotate(Tree root)
		{
			Tree new_root;
			Tree child;

			// init
			new_root = root->right;
			child = new_root->left;
			// Perform rotation
			new_root->left = root;
			root->right = child;
			// Update heights
			root->height = std::max(height(root->left), height(root->right)) + 1;
			new_root->height = std::max(height(new_root->left), height(new_root->right)) + 1;
			// Return new root
			return new_root;
		}

		Tree  min(Tree root)
		{
			if (!root)
				return root;
			else if (root->right && Compare()(root->right->data.first, root->data.first))
				return min(root->right);
			else if (root->left && Compare()(root->left->data.first, root->data.first))
				return min(root->left);
			return root;
		}

		Tree  min(Tree root) const
		{
			if (!root)
				return root;
			else if (root->right && Compare()(root->right->data.first, root->data.first))
				return min(root->right);
			else if (root->left && Compare()(root->left->data.first, root->data.first))
				return min(root->left);
			return root;
		}

		Tree  max(Tree root)
		{
			if (!root)
				return root;
			else if (root->right && !Compare()(root->right->data.first, root->data.first))
				return max(root->right);
			else if (root->left && !Compare()(root->left->data.first, root->data.first))
				return max(root->left);
			return root;
		}

		constTree  max(constTree root)
		{
			if (!root)
				return root;
			else if (root->right && !Compare()(root->right->data.first, root->data.first))
				return max(root->right);
			else if (root->left && !Compare()(root->left->data.first, root->data.first))
				return max(root->left);
			return root;
		}

		key_type	lowerBound(Tree root, key_type key) const
		{
			Tree             		_min;
			Tree             		next;
			key_type 				next_key;

			if (find(root, key))
				return key;
			_min = min(root);
			next = _min;
			next_key = next->data.first;
			while (next != root->end && Compare()(next->data.first, key) && !Compare()(key, _min->data.first))
			{
				next = findSuccessor(root, next->data.first);
				next_key = next->data.first;
			}
			if (Compare()(next_key, key))
				next_key = key;
			return next_key;
		}

		key_type	upperBound(Tree root, key_type key) const
		{
			if (find(root, key))
				return findSuccessor(root, key)->data.first;
			return lowerBound(root, key);
		}

		Tree	find(Tree root, key_type key) const
		{
			if (root == NULL)
				return NULL;
			if (!Compare()(root->data.first, key) && !Compare()(key, root->data.first))
				return root;
			if (Compare()(key, root->data.first))
				root = find(root->left, key);
			else if (!Compare()(key, root->data.first))
				root = find(root->right, key);
			return root;
		}

		constTree	find(constTree root, key_type key) const
		{
			if (root == NULL)
				return NULL;
			if (!Compare()(root->data.first, key) && !Compare()(key, root->data.first))
				return root;
			if (Compare()(key, root->data.first))
				root = find(root->left, key);
			else if (!Compare()(key, root->data.first))
				root = find(root->right, key);
			return root;
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
				if (!Compare()(current->data.first, node->data.first))
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
				if (!Compare()(current->data.first, node->data.first))
				{
					Predecessor = node;
					node = node->right;
				}
				else
					node = node->left;
			}
			return Predecessor;
		}

		Tree  findSuccessor(Tree  root, key_type key) const
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
				if (Compare()(current->data.first, node->data.first))
				{
					Successor = node;
					node = node->left;
				}
				else
					node = node->right;
			}
			return Successor;
		}

		constTree  findSuccessor(constTree  root, key_type key) const
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
				if (Compare()(current->data.first, node->data.first))
				{
					Successor = node;
					node = node->left;
				}
				else
					node = node->right;
			}
			return Successor;
		}

		void	Delete(Tree  &root, key_type key)
		{
			Tree temp;

			temp = NULL;
			if (!root)
				return ;
			if (Compare()(key, root->data.first))
				Delete(root->left, key);
			else if (!Compare()(key, root->data.first))
				Delete(root->right, key);
			if (!Compare()(root->data.first, key) && !Compare()(key, root->data.first))
			{
				if (!root->left && !root->right)
				{
					destroyAndDeallocate(root);
					root = NULL;
				}
				else if (root->right && !root->left)
				{
					temp = root;
					root = root->right;
					destroyAndDeallocate(temp);
				}
				else if (root->left && !root->right)
				{
					temp = root;
					root = root->left;
					destroyAndDeallocate(temp);
				}
				else
				{
					temp = min(root->right);
					root->data = temp->data;
					Delete(root->right, temp->data.first);
				}
			}
		}

		Tree	DeleteRange(Tree  root, key_type min, key_type max)
		{
			Tree  temp;
			key_type next;
			if (min == max)
			{
				Delete(root, max);
				return root;
			}
			temp = findSuccessor(root, min);
			if (!temp)
				return root;
			next = temp->data.first;
			Delete(root, min);
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

		void	destroyAndDeallocate(Tree root)
		{
			if (root->end)
			{
				destroyAndDeallocate(root->end);
				root->end = NULL;
			}
			alloc.destroy(root);
			alloc.deallocate(root, 1);
		}

		void    clear(Tree &root)
		{
			if (!root)
				return ;
			clear(root->left);
			clear(root->right);
			destroyAndDeallocate(root);
			if (root->end)
				destroyAndDeallocate(root->end);
			return;
		}

		Tree cloneBinaryTree(Tree root)
		{
			if (root == NULL)
				return NULL;
			Tree root_copy = createNewNode(root->data);
			root_copy->left = cloneBinaryTree(root->left);
			root_copy->right = cloneBinaryTree(root->right);

			return root_copy;
		}

		void	insert(Tree &root, dataType data)
		{
			int		blanceFactor;

			if (!root)
			{
				root = createNewNode(data);
				return ;
			}
			if (!Compare()(root->data.first, data.first) && !Compare()(data.first, root->data.first))
				return ;
			else if (Compare()(root->data.first, data.first))
				insert(root->right, data);
			else if (!Compare()(root->data.first, data.first))
				insert(root->left, data);
			root->height = 1 + std::max(height(root->left), height(root->right));
			blanceFactor = getBlanceFactor(root);
			if (blanceFactor > 1 && Compare()(data.first, root->left->data.first))
				root = rightRotate(root);
			else if (blanceFactor < -1 && !Compare()(data.first, root->right->data.first))
				root = leftRotate(root);
			else if (blanceFactor > 1 && !Compare()(data.first, root->left->data.first))
			{
				root->left = leftRotate(root->left);
				root = rightRotate(root);
			}
			else if (blanceFactor < -1 && Compare()(data.first, root->right->data.first))
			{
				root->right = rightRotate(root->right);
				root = leftRotate(root);
			}
			if (!root->end)
				root->end = createNewNode(dataType());
		}
	};
}

#endif // BINARY_SEARCH_TREE_HPP