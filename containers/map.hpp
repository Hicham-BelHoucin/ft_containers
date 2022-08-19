/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 09:45:02 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/18 15:21:11 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "../utils/iterator_traits.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/is_integral.hpp"
#include "../utils/pair.hpp"
#include "../utils/make_pair.hpp"

namespace ft
{
	template<typename key_type, typename value_type, typename Compare = std::less<key_type> >
	struct BinarySearchTree {
		ft::pair<key_type, value_type> 	data;
		BinarySearchTree				*right;
		BinarySearchTree				*left;

		BinarySearchTree(ft::pair<key_type, value_type> data)
		{
			this->data = data;
			this->right = NULL;
			this->left = NULL;
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
			// root = balanceTree(root, data);
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
	};
    template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key, T> >    // map::allocator_type
           > 
    class map
    {
        public:
			typedef Key															key_type;
			typedef T															mapped_type;
			typedef Compare														key_compare;
			typedef Alloc														allocator_type;
			// typedef typename    allocator_type::referance						referance;
			// typedef typename    allocator_type::const_referance					const_referance;
			typedef typename    allocator_type::pointer							pointer;
			typedef typename    allocator_type::const_pointer					const_pointer;
			typedef typename	iterator_traits<pointer>::difference_type		difference_type;
			typedef typename	allocator_type::size_type						size_type;


			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : allocator(alloc), root(NULL)
			{	
			}
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = nullptr) : allocator(alloc), root(NULL)
			{
				// while (first != last)
				// {
				// 	root = root->insert(root, );
				// 	first++;
				// }
			}
			/*
			map (const map& x) : allocator(x.alloc)
			{

			}
			~map()
			{

			}
			map& operator= (const map& x)
			{

			}
			iterator begin()
			{
				
			}
			const_iterator begin() const
			{

			}
			iterator end()
			{

			}
			const_iterator end() const
			{
				
			}
			reverse_iterator rbegin()
			{

			}
			const_reverse_iterator rbegin() const
			{
				
			}
			reverse_iterator rend()
			{

			}
			const_reverse_iterator rend() const
			{
				
			}
			bool empty() const
			{
				
			}
			size_type size() const
			{
				
			}
			size_type max_size() const
			{

			}
			*/
			mapped_type& operator[] (const key_type& k)
			{
				if (root->find(root, k))
					return root->find(root, k)->data.second;
				else
					root = root->insert(root, ft::pair<key_type, mapped_type>(k, mapped_type()));
				return root->find(root, k)->data.second;
			}
			/*
			pair<iterator,bool> insert (const value_type& val)
			{

			}
			iterator insert (iterator position, const value_type& val)
			{

			}
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				
			}
			void erase (iterator position)
			{

			}
			size_type erase (const key_type& k)
			{

			}
		    void erase (iterator first, iterator last)
			{

			}
			void swap (map& x)
			{
				
			}
			void clear()
			{
				
			}
			key_compare key_comp() const
			{

			}
			value_compare value_comp() const
			{
				
			}
			iterator find (const key_type& k)
			{

			}
			const_iterator find (const key_type& k) const
			{

			}
			size_type count (const key_type& k) const
			{
				
			}
			iterator lower_bound (const key_type& k)
			{

			}
			const_iterator lower_bound (const key_type& k) const
			{

			}
			iterator upper_bound (const key_type& k)
			{
				
			}
			const_iterator upper_bound (const key_type& k) const
			{

			}
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{

			}
			pair<iterator,iterator>             equal_range (const key_type& k)
			{

			}
			allocator_type get_allocator() const
			{
				
			}
			*/
		public:
			BinarySearchTree<key_type, mapped_type, Compare> *	root;
			Alloc												allocator;
			size_type											_size;
	};
}

#endif // MAP_HPP