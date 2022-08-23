/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 09:45:02 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/23 15:19:32 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "../utils/iterator_traits.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/is_integral.hpp"
#include "../utils/pair.hpp"
#include "../utils/BinarySearchTree.hpp"
#include "../utils/make_pair.hpp"
#include "../utils/pair.hpp"
#include "../utils/map_iter.hpp"

namespace ft
{
    template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key, T> >    // map::allocator_type
           > 
    class map
    {
        public:
			typedef Key																							key_type;
			typedef T																							mapped_type;
			typedef Compare																						key_compare;
			typedef Alloc																						allocator_type;
			typedef typename	ft::pair<const Key, T>															value_type;
			typedef typename	allocator_type::reference 														reference;
			typedef typename	allocator_type::const_reference 												const_reference;
			typedef typename    allocator_type::pointer															pointer;
			typedef typename    allocator_type::const_pointer													const_pointer;
			typedef typename	iterator_traits<pointer>::difference_type										difference_type;
			typedef typename	allocator_type::size_type														size_type;
			typedef typename	ft::Iterator<pointer, BinarySearchTree<key_type, mapped_type, Compare> *>		iterator;
			typedef typename	ft::Iterator<const_pointer, BinarySearchTree<key_type, mapped_type, Compare> *>	const_iterator;


			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : allocator(alloc), root(NULL), _size(0)
			{	
			}
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = nullptr) : allocator(alloc), root(NULL)
			{
				while (first != last)
				{
					root = root->insert(root, *first);
					first++;
				}
			}
			~map()
			{

			}
			/*
			map (const map& x) : allocator(x.alloc)
			{

			}
			map& operator= (const map& x)
			{

			*/
			iterator begin()
			{
				return iterator(root);	
			}
			const_iterator begin() const
			{
				return const_iterator(root);	
			}
			iterator end()
			{
				return iterator(root->end);
			}
			const_iterator end() const
			{
				return const_iterator(root->end);
			}
			/*
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
			*/
			bool empty() const
			{
				return _size == 0 ? true : false;	
			}
			size_type size() const
			{
				return _size;	
			}
			/*
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
			*/
			void clear()
			{
				root->clear();
				_size = 0;
			}
			/*
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