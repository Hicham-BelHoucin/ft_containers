/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:48:21 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/02 11:18:57 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITER_HPP
#define MAP_ITER_HPP

# include <iterator>
# include "./iterator_traits.hpp"
# include "./BinarySearchTree.hpp"
# include "./pair.hpp"

namespace ft
{
	template <typename bstType, typename value_type, typename Alloc, typename Tree>
	class mapIterator : public std::iterator<std::bidirectional_iterator_tag, value_type>
	{
		public:
			typedef typename Alloc::template rebind<Tree>::other 			nodeAlloc;
			typedef	typename nodeAlloc::pointer								Nodeptr;
			typedef	value_type*													pointer;
			typedef value_type&													reference;
		private:
			bstType	BST;
			Nodeptr root;
			Nodeptr current;
		public:
			mapIterator() : root(), current()
			{
			}
			mapIterator(Nodeptr root, Nodeptr current) : root(root), current(current)
			{
			}
			mapIterator(const mapIterator & other) : root(other.root), current(other.current)
			{
			}
			~mapIterator()
			{
			}
			reference operator*() const {
				return current->data;
			}
			mapIterator & operator++() {
				current = BST.findSuccessor(root, current->data.first);
				if (!current)
					current = root->end;
				return *this;
			}
			mapIterator operator++(int) {
				mapIterator temp = *this;
				++(*this);
				return temp;
			}
			mapIterator & operator--() {
				if (current == root->end)
					current = BST.max(root->right);
				else
					current = BST.findPredecessor(root, current->data.first);
				return *this;
			}
			mapIterator operator--(int) {
				mapIterator temp = *this;
				--(*this);
				return temp;
			}
			pointer operator->() const {
				return &(operator*());
			}
			template <typename _bstType, typename _value_type, typename _Alloc, typename _Tree>
			friend bool operator!=(const mapIterator<_bstType, _value_type, _Alloc, _Tree> &lhs, const mapIterator<_bstType, _value_type, _Alloc, _Tree> &rhs)
			{
				return (lhs.current != rhs.current);
			}
			template <typename _bstType, typename _value_type, typename _Alloc, typename _Tree>
			friend bool operator==(const mapIterator<_bstType, _value_type, _Alloc, _Tree> &lhs, const mapIterator<_bstType, _value_type, _Alloc, _Tree> &rhs)
			{
				return (lhs.current == rhs.current);
			}
	};

}

#endif // MAP_ITER_HPP