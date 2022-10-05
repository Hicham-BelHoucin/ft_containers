/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 10:58:42 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/05 12:52:28 by hbel-hou         ###   ########.fr       */
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
	Node			*end;
	Node    		*left;
	Node    		*right;

	Node (T data, int color, Node * parent)
	{
		this->data = data;
		this->color = color;
		this->parent = parent;
		this->left = NULL;
		this->right = NULL;
		this->end = NULL;
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
	typedef	T			value_type;
	typedef	T			key_type;
	// typedef	Node<T>	*	Tree;
	typedef typename Alloc::template rebind<Node<value_type> >::other 		nodeAlloc;
	typedef	typename nodeAlloc::pointer										Tree;
	typedef	typename nodeAlloc::const_pointer								constTree;
	typedef	typename nodeAlloc::size_type									size_type;
	Tree				root;
	int					rotations;
	nodeAlloc			alloc;

	RedBlackTree(const nodeAlloc & alloc = nodeAlloc() ) : root(NULL), rotations(0), alloc(alloc)
	{
	}

	size_type	max_size(void)
	{
		return alloc.max_size();
	}

	Tree  min(Tree root)
	{
		if (!root)
			return root;
		else if (root->right && Compare()(root->right->data, root->data))
			return min(root->right);
		else if (root->left && Compare()(root->left->data, root->data))
			return min(root->left);
		return root;
	}

	Tree  min(Tree root) const
	{
		if (!root)
			return root;
		else if (root->right && Compare()(root->right->data, root->data))
			return min(root->right);
		else if (root->left && Compare()(root->left->data, root->data))
			return min(root->left);
		return root;
	}

	Tree  max(Tree root)
	{
		if (!root)
			return root;
		else if (root->right && !Compare()(root->right->data, root->data))
			return max(root->right);
		else if (root->left && !Compare()(root->left->data, root->data))
			return max(root->left);
		return root;
	}

	constTree  max(constTree root)
	{
		if (!root)
			return root;
		else if (root->right && !Compare()(root->right->data, root->data))
			return max(root->right);
		else if (root->left && !Compare()(root->left->data, root->data))
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
		next_key = next->data;
		while (next != root->end && Compare()(next->data, key) && !Compare()(key, _min->data))
		{
			next = findSuccessor(root, next->data);
			next_key = next->data;
		}
		if (Compare()(next_key, key))
			next_key = key;
		return next_key;
	}

	key_type	upperBound(Tree root, key_type key) const
	{
		if (find(root, key))
			return findSuccessor(root, key)->data;
		return lowerBound(root, key);
	}

	Tree	find(Tree root, key_type key) const
	{
		if (root == NULL)
			return NULL;
		if (!Compare()(root->data, key) && !Compare()(key, root->data))
			return root;
		if (Compare()(key, root->data))
			root = find(root->left, key);
		else if (!Compare()(key, root->data))
			root = find(root->right, key);
		return root;
	}

	constTree	find(constTree root, key_type key) const
	{
		if (root == NULL)
			return NULL;
		if (!Compare()(root->data, key) && !Compare()(key, root->data))
			return root;
		if (Compare()(key, root->data))
			root = find(root->left, key);
		else if (!Compare()(key, root->data))
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
			if (!Compare()(current->data, node->data))
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
			if (!Compare()(current->data, node->data))
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
			if (Compare()(current->data, node->data))
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
			if (Compare()(current->data, node->data))
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
		if (Compare()(key, root->data))
			Delete(root->left, key);
		else if (!Compare()(key, root->data))
			Delete(root->right, key);
		if (!Compare()(root->data, key) && !Compare()(key, root->data))
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
				Delete(root->right, temp->data);
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
		next = temp->data;
		Delete(root, min);
		root = DeleteRange(root, next, max);
		return root;
	}

	void	destroyAndDeallocate(Tree root)
	{
		if (!root)
			return ;
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

	Tree	createNewNode(value_type data, int color, Tree parent)
	{
		Tree	temp;
		temp = alloc.allocate(1);
		alloc.construct(temp, Node<value_type>(data, color, parent));
		return temp;
	}

	Tree cloneBinaryTree(Tree root)
	{
		if (root == NULL)
			return NULL;
		Tree root_copy = createNewNode(root->data, root->color, root->parent);
		root_copy->left = cloneBinaryTree(root->left);
		root_copy->right = cloneBinaryTree(root->right);
		return root_copy;
	}

	Tree rightRotate(Tree root)
	{
		Tree new_root;
		Tree child;

		if (!root->left)
			return root;
		// init
		new_root = root->left;
		child = new_root->right;
		// Perform rotation
		new_root->right = root;
		root->left = child;
		// change parent
		new_root->parent = root->parent;
		root->parent = new_root;
		// Return new root
		return new_root;
	}

	Tree leftRotate(Tree root)
	{
		Tree new_root;
		Tree child;

		if (!root->right)
			return root;
		// init
		new_root = root->right;
		child = new_root->left;
		// Perform rotation
		new_root->left = root;
		root->right = child;
		// change parent
		new_root->parent = root->parent;
		root->parent = new_root;
		// Return new root
		return new_root;
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
				root = createNewNode(data, BLACK, parent);
			else
				root = createNewNode(data, RED, parent);
		}
		else if (!Compare()(root->data, data) && !Compare()(data, root->data))
			return root;
		else if (Compare()(root->data, data))
		{
			root->right = insertHelper(root->right, data, root, rotations);
			if (root->color == RED && root->right->color == RED)
			{
				redconfilct = true;
				data = root->right->data;
			}
		}
		else if (!Compare()(root->data , data))
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
		if (!root->end)
			root->end = createNewNode(value_type(), BLACK, NULL);
		return root;
	}

	void	insert(value_type data)
	{
		root = insertHelper(root, data, NULL, rotations);
		return ;
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