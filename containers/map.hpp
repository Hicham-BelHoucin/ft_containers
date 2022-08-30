/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 09:45:02 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/30 16:41:54 by hbel-hou         ###   ########.fr       */
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
           class Alloc = std::allocator<ft::pair<const Key, T>	> >    // map::allocator_type
    class map
    {
        public:
			class ValueCopmare
			{
				friend class map;
				private:
					Compare		compare_fun;
					ValueCopmare(Compare c) : compare_fun(c) {};
				public:
					typedef bool	return_type;
					typedef	typename ft::pair<const Key, T>		value_type;
					return_type operator() (const value_type & x, const value_type &y)
					{
						return (compare_fun(x.first, y.first));
					}
			};
			typedef Key																				key_type;
			typedef T																				mapped_type;
			typedef Compare																			key_compare;
			typedef BinarySearchTree<key_type, mapped_type, Compare>								Tree;
			typedef Alloc																			allocator_type;
			typedef	ValueCopmare																	value_compare;
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
					insert(*first);
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
				Tree * temp = NULL;

				if (!root)
					return iterator();
				temp = root->min(root);
				return iterator(root, temp);
			}
			const_iterator begin() const
			{
				Tree * temp = NULL;

				if (!root)
					return const_iterator();
				temp = root->min(root);
				return const_iterator(root, temp);
			}
			iterator end()
			{
				if (!root)
					return iterator();
				return iterator(root, root->end);
			}
			const_iterator end() const
			{
				if (!root)
					return const_iterator();
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
				{
					root = root->insert(root, ft::pair<key_type, mapped_type>(k, mapped_type()));
					_size++;
				}
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
				iterator 	it;
				bool		inserted;
				
				inserted = true;
				root = root->insert(root, val);
				it = find(val.first);
				if (it->second != val.second)
					inserted = false;
				_size++;
				return ft::pair<iterator, bool>(it, inserted);
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
				while (first != last)
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
				root = root->DeleteRange(root, min, max);
			}

			void clear()
			{
				root->clear(root);
			}

			void swap (map& x)
			{
				Tree *__swap;

				__swap = &(*x.root);
				x.root = &(*(this->root));
				this->root = __swap;
				return ;
			}

			/* //////////////////////////[  Operations ]/////////////////////////////// */

			iterator find (const key_type& k)
			{
				Tree * temp;

				temp = root->find(root, k);
				if (temp != NULL)
					return iterator(root, temp);
				return end();
			}
			const_iterator find (const key_type& k) const
			{
				Tree * temp;

				temp = root->find(root, k);
				if (temp)
					return iterator(root, temp);
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
				key_type  toFind;

				toFind = root->lowerBound(root, k);
				return find(toFind);
			}
			const_iterator lower_bound (const key_type& k) const
			{
				key_type  toFind;

				toFind = root->lowerBound(root, k);
				return find(toFind);
			}
			iterator upper_bound (const key_type& k)
			{
				key_type  toFind;

				toFind = root->upperBound(root, k);
				return find(toFind);
			}
			const_iterator upper_bound (const key_type& k) const
			{
				key_type  toFind;

				toFind = root->upperBound(root, k);
				return find(toFind);
			}
			ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				const_iterator _element;
				const_iterator _next_element;

				_element = lower_bound(k);
				_next_element = upper_bound(k);
				return ft::pair<iterator, iterator>(_element, _next_element);
			}
			ft::pair<iterator,iterator>             equal_range (const key_type& k)
			{
				iterator _element;
				iterator _next_element;

				_element = lower_bound(k);
				_next_element = upper_bound(k);
				return ft::pair<iterator, iterator>(_element, _next_element);
			}

			/* //////////////////////////[  Observers ]/////////////////////////////// */


			key_compare key_comp() const
			{
				return comp;
			}

			value_compare value_comp() const
			{
				return 	ValueCopmare(comp);
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