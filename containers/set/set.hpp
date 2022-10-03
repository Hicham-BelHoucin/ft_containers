/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:25:57 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/03 13:08:34 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

# include <iostream>     // std::cout
# include <functional>   // std::less
# include "../../utils/set_iter.hpp"
# include "../../utils/pair.hpp"
# include "../../utils/rev_map_iter.hpp"
# include "../../utils/iterator_traits.hpp"
# include "../../utils/RedBlackTree.hpp"
# include "../../utils/is_integral.hpp"
# include "../../utils/enable_if.hpp"
# include "../../utils/equal.hpp"
# include "../../utils/lexicographical_compare.hpp"

namespace ft
{
	template < class T, // set::key_type/value_type
		class Compare = std::less<T>,        // set::key_compare/value_compare
		class Alloc = std::allocator<T> >     // set::allocator_type
	class set
	{
		private:
			typedef	RedBlackTree<T, Compare, Alloc>															Tree;
			typedef	typename Tree::Tree																		treePointer;
			template <class _Tp>
			void    swap(_Tp & x, _Tp & y)
			{
				_Tp temp;
				temp = x;
				x = y;
				y = temp;
			}
		public:
			typedef T                                       												key_type;
			typedef T                                       												value_type;
			typedef	Compare																					key_compare;
			typedef	Compare																					value_compare;
			typedef Alloc                                   												allocator_type;
			typedef typename    Alloc::reference            												reference;
			typedef typename    Alloc::const_reference      												const_reference;
			typedef typename	ft::setIterator<Tree, value_type, Alloc, Node<value_type> >					iterator;
			typedef typename	ft::setIterator<Tree, const value_type, Alloc, const Node<value_type> >		const_iterator;
			typedef typename	ft::reverse_map_iter<iterator>												reverse_iterator;
			typedef typename	ft::reverse_map_iter<const_iterator>										const_reverse_iterator;
			typedef typename    Alloc::pointer              												pointer;
			typedef typename    Alloc::const_pointer        												const_pointer;
			typedef typename    Alloc::size_type        													size_type;
			typedef typename	iterator_traits<pointer>::difference_type									difference_type;

			/* //////////////////////////[ Constructor ]/////////////////////////////// */

			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : BST(), _size(0), allocator(alloc), comp(comp)
			{
			};

			template <class InputIterator>
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = nullptr) : BST(), _size(0), allocator(alloc), comp(comp)
			{
				while (first != last)
				{
					BST.insert(*first);
					_size++;
					first ++;
				}
			};

			set (const set& x)
			{
				BST.root = BST.cloneBinaryTree(x.BST.root);
				_size = x._size;
				comp = x.comp;
				allocator = x.allocator;
			}

			/* //////////////////////////[ Assignment ]/////////////////////////////// */

			set& operator= (const set& x)
			{
				clear();
				new (this) set(x);
				return *this;
			}

			/* //////////////////////////[ Destructor ]/////////////////////////////// */

			~set()
			{
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

			/* //////////////////////////[ Destructor ]/////////////////////////////// */

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
				BST.max_size();
			}

			/* //////////////////////////[ Modifiers ]/////////////////////////////// */

			ft::pair<iterator,bool> insert (const value_type& val)
			{
				iterator 	it;
				bool		inserted;

				(void)val;
				inserted = true;
				if (BST.find(BST.root, val))
					inserted = false;
				BST.insert(val);
				it = find(val);
				if (inserted)
					_size++;
				return ft::pair<iterator, bool>(it, inserted);
			}

			iterator insert (iterator position, const value_type& val)
			{
				treePointer temp;

				(void)position;
				if (BST.find(BST.root, val))
				{
					temp = BST.find(BST.root, val);
					return iterator(BST.root, temp);
				}
				insert(val);
				temp = BST.find(BST.root, val);
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
					BST.Delete(BST.root, *position);
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
					min = *first;
					if (last == end())
						max = BST.max(BST.root)->data;
					else
					{
						last--;
						max = *last;
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

			void swap (set& x)
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

				_element = lower_bound(k);
				_next_element = upper_bound(k);
				return ft::pair<iterator, iterator>(_element, _next_element);
			}

			/* //////////////////////////[  Observers ]/////////////////////////////// */

			key_compare key_comp() const
			{
				return key_comp();
			}

			value_compare value_comp() const
			{
				return value_comp();
			}

			/* //////////////////////////[  GetAllocator ]/////////////////////////////// */

			allocator_type get_allocator() const
			{
				return Alloc(allocator);
			}

			/* //////////////////////////[  relational operators ]/////////////////////////////// */

			template <class  _T, class  _Compare, class  _Alloc>
			friend bool operator== ( const set< _T, _Compare, _Alloc>& lhs, const set< _T, _Compare, _Alloc>& rhs )
			{
				if (lhs.size() != rhs.size())
					return false;
				return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
			}
			template <class  _T, class  _Compare, class  _Alloc>
			friend bool operator!= ( const set< _T, _Compare, _Alloc>& lhs, const set< _T, _Compare, _Alloc>& rhs )
			{
				return !(lhs == rhs);
			}
			template <class  _T, class  _Compare, class  _Alloc>
			friend bool operator<= ( const set< _T, _Compare, _Alloc>& lhs, const set< _T, _Compare, _Alloc>& rhs )
			{
				return !(rhs < lhs);
			}
			template <class  _T, class  _Compare, class  _Alloc>
			friend bool operator> ( const set< _T, _Compare, _Alloc>& lhs, const set< _T, _Compare, _Alloc>& rhs )
			{
				return rhs < lhs;
			}
			template <class  _T, class  _Compare, class  _Alloc>
			friend bool operator< ( const set< _T, _Compare, _Alloc>& lhs, const set< _T, _Compare, _Alloc>& rhs )
			{
				return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
			}
			template <class  _T, class  _Compare, class  _Alloc>
			friend bool operator>= ( const set< _T, _Compare, _Alloc>& lhs, const set< _T, _Compare, _Alloc>& rhs )
			{
				return !(lhs < rhs);
			}
			template <class  _T, class  _Compare, class  _Alloc>
			friend void swap (set< _T, _Compare, _Alloc>& x, set< _T, _Compare, _Alloc>& y);

			private :
				Tree			BST;
				size_type		_size;
				allocator_type	allocator;
				Compare			comp;
	};

	template <class  _T, class  _Compare, class  _Alloc>
	void swap (set< _T, _Compare, _Alloc>& x, set< _T, _Compare, _Alloc>& y)
	{
		x.swap(y);
	}

} // namespace ft

#endif // SET_HPP