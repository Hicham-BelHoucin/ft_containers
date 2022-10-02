/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 09:45:02 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/02 11:17:53 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

# include <iostream>
# include "../../utils/iterator_traits.hpp"
# include "../../utils/enable_if.hpp"
# include "../../utils/is_integral.hpp"
# include "../../utils/pair.hpp"
# include "../../utils/BinarySearchTree.hpp"
# include "../../utils/Node.hpp"
# include "../../utils/equal.hpp"
# include "../../utils/make_pair.hpp"
# include "../../utils/pair.hpp"
# include "../../utils/map_iter.hpp"
# include "../../utils/rev_map_iter.hpp"
# include "../../utils/lexicographical_compare.hpp"

namespace ft
{
    template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key, T> >	>    // map::allocator_type
    class map
    {
		private:
			template <class _Tp>
			void    swap(_Tp & x, _Tp & y)
			{
				_Tp temp;
				temp = x;
				x = y;
				y = temp;
			}
        public:
			class ValueCopmare
			{
				friend class map;
				private:
					Compare		compare_fun;
					ValueCopmare(Compare c) : compare_fun(c) {};
				public:
					typedef bool								return_type;
					typedef	typename ft::pair<const Key, T>		value_type;
					return_type operator() (const value_type & x, const value_type &y)
					{
						return (compare_fun(x.first, y.first));
					}
			};
			typedef Key																				key_type;
			typedef T																				mapped_type;
			typedef Compare																			key_compare;
			typedef Alloc																			allocator_type;
			typedef BinarySearchTree<key_type, mapped_type, Compare, Alloc>							Tree;
			typedef typename Tree::Tree																treePointer;
			typedef	ValueCopmare																	value_compare;
			typedef typename	ft::pair<const Key, T>												value_type;
			typedef typename	allocator_type::reference 											reference;
			typedef typename	allocator_type::const_reference 									const_reference;
			typedef typename    allocator_type::pointer												pointer;
			typedef typename    allocator_type::const_pointer										const_pointer;
			typedef typename	ft::mapIterator<Tree, value_type, Alloc, Node<value_type> >				iterator;
			typedef typename	ft::mapIterator<Tree, const value_type, Alloc, const Node<value_type> >			const_iterator;
			typedef typename	ft::reverse_map_iter<iterator>										reverse_iterator;
			typedef typename	ft::reverse_map_iter<const_iterator>							const_reverse_iterator;
			typedef typename	iterator_traits<pointer>::difference_type							difference_type;
			typedef typename	allocator_type::size_type											size_type;


			/* //////////////////////////[ Constructor ]/////////////////////////////// */

			explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
			:
				BST(),
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
				BST(),
				allocator(alloc),
				_size(0),
				comp(comp)
			{
				while (first != last)
				{
					BST.insert(BST.root, *first);
					_size++;
					first++;
				}
			}
			map (const map& x)
			{
				BST.root = BST.cloneBinaryTree(x.BST.root);
				_size = x._size;
				comp = x.comp;
				allocator = x.allocator;
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
				// BST.clear(BST.root);
				if (BST.root)
					clear();
			}

			/* //////////////////////////[ Iterators ]/////////////////////////////// */

			iterator begin()
			{
				treePointer	temp;

				if (!BST.root)
					return iterator();
				temp = BST.min(BST.root);
				return iterator(BST.root, temp);
			}

			const_iterator begin() const
			{
				treePointer	temp;

				if (!BST.root)
					return const_iterator();
				temp = BST.min(BST.root);
				return const_iterator(BST.root, temp);
			}

			iterator end()
			{
				if (!BST.root)
					return iterator();
				return iterator(BST.root, BST.root->end);
			}

			const_iterator end() const
			{
				if (!BST.root)
					return const_iterator();
				return const_iterator(BST.root, BST.root->end);
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
				if (BST.find(BST.root, k))
					return BST.find(BST.root, k)->data.second;
				else
				{
					BST.insert(BST.root, ft::pair<key_type, mapped_type>(k, mapped_type()));
					_size++;
				}
				return BST.find(BST.root, k)->data.second;
			}

			mapped_type& at (const key_type& k)
			{
				if (BST.find(BST.root, k))
					return BST.find(BST.root, k)->data.second;
				throw std::out_of_range("out of range !");
			}

			const mapped_type& at (const key_type& k) const
			{
				if (BST.find(BST.root, k))
					return BST.find(BST.root, k)->data.second;
				throw std::out_of_range("out of range !");
			}

			/* //////////////////////////[  Modifiers ]/////////////////////////////// */

			ft::pair<iterator,bool> insert (const value_type& val)
			{
				iterator 	it;
				bool		inserted;

				(void)val;
				inserted = true;
				if (BST.find(BST.root, val.first))
					inserted = false;
				BST.insert(BST.root, val);
				it = find(val.first);
				if (inserted)
					_size++;
				return ft::pair<iterator, bool>(it, inserted);
			}

			iterator insert (iterator position, const value_type& val)
			{
				treePointer temp;

				(void)position;
				if (BST.find(BST.root, val.first))
				{
					temp = BST.find(BST.root, val.first);
					return iterator(BST.root, temp);
				}
				insert(val);
				temp = BST.find(BST.root, val.first);
				return iterator(BST.root, temp);
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
				if (BST.root)
				{
					BST.Delete(BST.root, position->first);
					_size--;
				}
			}

			size_type erase (const key_type& k)
			{
				if (BST.root && BST.find(BST.root, k))
				{
					BST.Delete(BST.root, k);
					_size--;
					return 1;
				}
				return 0;
			}

			void erase (iterator first, iterator last)
			{
				size_type i;
				key_type min;
				key_type max;

				i = std::distance(first, last);
				if (BST.root)
				{
					min = first->first;
					if (last == end())
						max = BST.max(BST.root)->data.first;
					else
					{
						last--;
						max = last->first;
					}
					BST.root = BST.DeleteRange(BST.root, min, max);
					_size -= i;
				}
			}

			void clear()
			{
				if (BST.root)
				{
					BST.clear(BST.root);
					BST.root = NULL;
					_size = 0;
				}
			}

			void swap (map& x)
			{
				swap(x.BST.root, BST.root);
				swap(_size, x._size);
				swap(comp, x.comp);
				swap(allocator, x.allocator);
				return ;
			}

			/* //////////////////////////[  Operations ]/////////////////////////////// */

			iterator find (const key_type& k)
			{
				treePointer temp;

				temp = BST.find(BST.root, k);
				if (temp)
					return iterator(BST.root, temp);
				return end();
			}

			const_iterator find (const key_type& k) const
			{
				treePointer temp;

				temp = BST.find(BST.root, k);
				if (temp)
					return const_iterator(BST.root, temp);
				return end();

			}

			size_type count (const key_type& k) const
			{
				if (BST.find(BST.root, k))
					return (1);
				return (0);
			}

			iterator lower_bound (const key_type& k)
			{
				key_type  toFind;

				if (!BST.root || std::numeric_limits<key_type>::max() <= k)
					return end();
				toFind = BST.lowerBound(BST.root, k);
				return find(toFind);
			}

			const_iterator lower_bound (const key_type& k) const
			{
				key_type  toFind;

				if (!BST.root || std::numeric_limits<key_type>::max() <= k)
					return end();
				toFind = BST.lowerBound(BST.root, k);
				return find(toFind);
			}

			iterator upper_bound (const key_type& k)
			{
				key_type  toFind;

				if (!BST.root || std::numeric_limits<key_type>::max() <= k)
					return end();
				toFind = BST.upperBound(BST.root, k);
				return find(toFind);
			}

			const_iterator upper_bound (const key_type& k) const
			{
				key_type  toFind;

				if (!BST.root || std::numeric_limits<key_type>::max() <= k)
					return end();
				toFind = BST.upperBound(BST.root, k);
				return find(toFind);
			}
			ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				const_iterator _element;
				const_iterator _next_element;

				if (find(k) == end())
					return ft::pair<const_iterator, const_iterator>(end(), end());
				_element = lower_bound(k);
				_next_element = upper_bound(k);
				return ft::pair<const_iterator, const_iterator>(_element, _next_element);
			}
			ft::pair<iterator,iterator>             equal_range (const key_type& k)
			{
				iterator _element;
				iterator _next_element;

				// if (find(k) == end())
				// 	return ft::pair<iterator, iterator>(end(), end());
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

			template <class _Key, class _T, class _Compare, class _Alloc>
			friend bool operator== ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs )
			{
				if (lhs.size() != rhs.size())
					return false;
				return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
			}
			template <class _Key, class _T, class _Compare, class _Alloc>
			friend bool operator!= ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs )
			{
				return !(lhs == rhs);
			}
			template <class _Key, class _T, class _Compare, class _Alloc>
			friend bool operator<= ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs )
			{
				return !(rhs < lhs);
			}
			template <class _Key, class _T, class _Compare, class _Alloc>
			friend bool operator > ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs )
			{
				return rhs < lhs;
			}
			template <class _Key, class _T, class _Compare, class _Alloc>
			friend bool operator< ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs )
			{
				return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
			}
			template <class _Key, class _T, class _Compare, class _Alloc>
			friend bool operator>= ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs )
			{
				return 	!(lhs < rhs);
			}
			template <class _Key, class _T, class _Compare, class _Alloc>
			friend void swap (map<_Key,_T,_Compare,_Alloc>& x, map<_Key,_T,_Compare,_Alloc>& y);

		private:
			Tree 												BST;
			Alloc												allocator;
			size_type											_size;
			key_compare											comp;
	};

	template <class _Key, class _T, class _Compare, class _Alloc>
	void swap (map<_Key,_T,_Compare,_Alloc>& x, map<_Key,_T,_Compare,_Alloc>& y)
	{
		x.swap(y);
	}
}

#endif // MAP_HPP