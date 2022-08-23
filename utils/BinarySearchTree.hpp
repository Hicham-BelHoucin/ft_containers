/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:21:30 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/23 15:00:43 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

namespace ft
{
    template<typename key_type, typename value_type, typename Compare = std::less<key_type> >
	struct BinarySearchTree {
		ft::pair<const key_type, value_type> 	data;
		BinarySearchTree				*right;
		BinarySearchTree				*left;
		BinarySearchTree				*end;

		BinarySearchTree(ft::pair<key_type, value_type> data)
		{
			this->data = data;
			this->right = NULL;
			this->left = NULL;
			this->end = NULL;
		}
		int			hieght(BinarySearchTree	*root)
		{
			int		leftSubTree;
			int		rightSubTree;

			if (root == NULL)
				return 0;
			leftSubTree = hieght(root->left);
			rightSubTree = hieght(root->right);
			return std::max(leftSubTree, rightSubTree) + 1;
		}
		int			getBalanceFactor(BinarySearchTree *root)
		{
			if (root == NULL)
				return 0;
			return hieght(root->left) - hieght(root->right);
		}
		BinarySearchTree * leftRotate(BinarySearchTree * root)
		{
			BinarySearchTree * first;
			BinarySearchTree * second;

			first = root->right;
			second = first->left;
			first->left = root;
			root->right = second;
			return first;
		}
		BinarySearchTree * rightRotate(BinarySearchTree * root)
		{
			BinarySearchTree * first;
			BinarySearchTree * second;

			first = root->left;
			second = first->right;
			first->right = root;
			root->left = second;
			return first;
		}
		BinarySearchTree	*balanceTree(BinarySearchTree *root, ft::pair<key_type, value_type> key)
		{
			int balance;

			balance = getBalanceFactor(root);
			if (balance > 1 && Compare()(key.first, root->left->data.first))
				return rightRotate(root);
			if (balance < -1 && !Compare()(key.first, root->right->data.first))
				return leftRotate(root);
			if (balance > 1 && !Compare()(key.first, root->left->data.first))
			{
				root->left =  leftRotate(root->left);
				return rightRotate(root);
			}
			if (balance < -1 && Compare()(key.first, root->right->data.first))
			{
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
			return root;
		}
		BinarySearchTree	*insert(BinarySearchTree *root, ft::pair<key_type, value_type> data)
		{
			if (root == NULL)
				root = new BinarySearchTree(data);
			else if (Compare()(data.first, root->data.first))
				root->left = insert(root->left, data);
			else if (!Compare()(data.first, root->data.first))
				root->right = insert(root->right, data);
			else if (data.first == root->data.first)
				return root;
			root = balanceTree(root, data);
			root->end = new BinarySearchTree(ft::pair<key_type, value_type>());
			return root;
		}
		BinarySearchTree	*find(BinarySearchTree *root, key_type key)
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
		void    clear(BinarySearchTree *root)
		{
			if (!root)
				return ;
			clear(root->left);
			clear(root->right);
			delete root;
			return;
		}
		BinarySearchTree * min(BinarySearchTree *root)
		{
			if (!root->left)
				return root;
			return min(root->left);
		}
		BinarySearchTree * max(BinarySearchTree *root)
		{
			if (!root->right)
				return root;
			return max(root->right);
		}
		BinarySearchTree * findPredecessor(BinarySearchTree * root, key_type key)
		{
			BinarySearchTree * Predecessor;
			BinarySearchTree * current;
			BinarySearchTree * node;

			current = root->find(root, key);
			if (!current)
				return NULL;
			if (current->left)
				return root->max(current->left);
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
		BinarySearchTree * findSuccessor(BinarySearchTree * root, key_type key)
		{
			BinarySearchTree * current;
			BinarySearchTree * Successor;
			BinarySearchTree * node;

			current = root->find(root, key);
			if (!current)
				return NULL;
			if (current->right)
				return root->min(current->right);
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
}

#endif // BINARY_SEARCH_TREE_HPP