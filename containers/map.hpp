/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 09:45:02 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/27 14:44:50 by hbel-hou         ###   ########.fr       */
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
			typedef Key																				key_type;
			typedef T																				mapped_type;
			typedef Compare																			key_compare;
			typedef BinarySearchTree<key_type, mapped_type, Compare>								Tree;
			typedef Alloc																			allocator_type;
			typedef typename	ft::pair<const Key, T>												value_type;
			typedef typename	allocator_type::reference 											reference;
			typedef typename	allocator_type::const_reference 									const_reference;
			typedef typename    allocator_type::pointer												pointer;
			typedef typename    allocator_type::const_pointer										const_pointer;
			typedef typename	ft::mapIterator<key_type, mapped_type, Compare>						iterator;
			typedef typename	ft::constMapIterator<key_type, mapped_type, Compare>				const_iterator;
			typedef typename	ft::reverse_map_iter<iterator>										reverse_iterator;
			typedef typename	ft::const_reverse_map_iter<const_iterator>							const_reverse_iterator;
			typedef typename	iterator_traits<pointer>::difference_type							difference_type;
			typedef typename	allocator_type::size_type											size_type;


			/* //////////////////////////[ Constructor ]/////////////////////////////// */
			explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
			:
				root(NULL),
				allocator(alloc),
				_size(0),
				comp(comp)
			{	
			}
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = nullptr)
			:
				allocator(alloc),
				_size(0),
				root(NULL),
				comp(comp)
			{
				while (first != last)
				{
					// You Need To Replace That Line
					root = root->insert(root, *first);
					// insert(first);
					first++;
				}
			}
			map (const map& x)
			{
				allocator = x.allocator;
				_size = x._size;
				comp = x.comp;
				root = x.root->DuplicateTree(root, x.root);
			}
			map& operator= (const map& x)
			{
				clear();
				new (this) map(x);
				return *this;
			}
			/* //////////////////////////[ Destructor ]/////////////////////////////// */
			~map()
			{
				clear();
			}

			/* //////////////////////////[ Iterators ]/////////////////////////////// */

			iterator begin()
			{
				Tree * temp;

				temp = root->min(root);
				return iterator(root, temp);
			}
			const_iterator begin() const
			{
				Tree * temp;

				temp = root->min(root);
				return const_iterator(root, temp);
			}
			iterator end()
			{
				return iterator(root, root->end);
			}
			const_iterator end() const
			{
				return const_iterator(root, root->end);
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(end());
			}
			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(end());
			}

			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			}

			/* //////////////////////////[ Capacity ]/////////////////////////////// */

			bool empty() const
			{
				return _size == 0 ? true : false;	
			}
			size_type size() const
			{
				return _size;	
			}
			size_type max_size() const
			{
				return this->allocator.max_size();
			}

			/* //////////////////////////[  Element access ]/////////////////////////////// */

			mapped_type& operator[] (const key_type& k)
			{
				if (root->find(root, k))
					return root->find(root, k)->data.second;
				else
					root = root->insert(root, ft::pair<key_type, mapped_type>(k, mapped_type()));
				return root->find(root, k)->data.second;
			}
			mapped_type& at (const key_type& k)
			{
				if (root->find(root, k))
					return root->find(root, k)->data.second;
				throw std::out_of_range("out of range !");
			}
			const mapped_type& at (const key_type& k) const
			{
				if (root->find(root, k))
					return root->find(root, k)->data.second;
				throw std::out_of_range("out of range !");
			}

			/* //////////////////////////[  Modifiers ]/////////////////////////////// */
			
			ft::pair<iterator,bool> insert (const value_type& val)
			{
				Tree *temp;
				if (root->find(root, val.first))
				{
					temp = root->find(root, val.first);
					return ft::pair<iterator, bool>(iterator(root, temp), false);
				}
				root = root->insert(root, val);
				temp = root->find(root, val.first);
				_size++;
				return ft::pair<iterator, bool>(iterator(root, temp), true);
			}

			iterator insert (iterator position, const value_type& val)
			{
				Tree * temp;
			
				if (root->find(root, val.first))
				{
					temp = root->find(root, val.first);
					return iterator(root, temp);
				}
				insert(val);
				temp = root->find(root, val.first);
				return iterator(root, temp);
			}

			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last, 
			  		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = nullptr)
			{
				while (first < last)
				{
					insert(*first);
					first++;
				}
			}

			void erase (iterator position)
			{
				root = root->Delete(root, position->first);
				_size--;
			}

			size_type erase (const key_type& k)
			{
				root = root->Delete(root, k);
				_size--;
				return 1;
			}

			void erase (iterator first, iterator last)
			{
				size_type i;
				key_type min;
				key_type max;

				i = 0;
				min = first->first;
				if (last == end())
					max = root->max(root)->data.first;
				else
				{
					last--;
					max = last->first;
				}
				while (first < last)
				{
					first ++;
					i++;
				}
				_size -= i;
				// std::cout << "min : " << min << "  max :" << max << std::endl;
				root = root->DeleteRange(root, min, max);
			}

			void clear()
			{
				root->clear(root);
			}

			void swap (map& x)
			{
				map temp = x;
				x = *this;
				*this = temp;
			}

			/* //////////////////////////[  Operations ]/////////////////////////////// */

			iterator find (const key_type& k)
			{
				Tree * temp;
			
				if (root->find(root, k))
				{
					temp = root->find(root, k);
					return iterator(root, temp);
				}
				return end();
			}
			const_iterator find (const key_type& k) const
			{
				Tree * temp;
			
				if (root->find(root, k))
				{
					temp = root->find(root, k);
					return iterator(root, temp);
				}
				return end();
				
			}
			size_type count (const key_type& k) const
			{
				if (root->find(root, k))
					return (1);
				return (0);
			}
			iterator lower_bound (const key_type& k)
			{
				iterator it;
				Tree *temp;
				temp = root->findPredecessor(root, k);
				it = iterator(root, temp);
				it++;
				return it;
			}
			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator it;
				Tree *temp;
				temp = root->findPredecessor(root, k);
				it = const_iterator(root, temp);
				it++;
				return it;
			}
			iterator upper_bound (const key_type& k)
			{
				iterator it;;
				Tree *temp;
				temp = root->findSuccessor(root, k);
				it = iterator(root, temp);
				return it;
			}
			const_iterator upper_bound (const key_type& k) const
			{
				Tree *temp;
				const_iterator it;
				temp = root->findSuccessor(root, k);
				it = const_iterator(root, temp);
				return it;
			}
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				
			}
			pair<iterator,iterator>             equal_range (const key_type& k)
			{

			}

			/* //////////////////////////[  GetAllocator ]/////////////////////////////// */

			allocator_type get_allocator() const
			{
				return Alloc(allocator);
			}

		private:
			Tree 												*root;
			Alloc												allocator;
			size_type											_size;
			key_compare											comp;
	};
}

#endif // MAP_HPP