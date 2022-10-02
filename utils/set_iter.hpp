/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:30:30 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/02 16:33:41 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETITER_HPP
#define SETITER_HPP

# include <iterator>
# include "./iterator_traits.hpp"

namespace ft
{
	template <typename bstType, typename value_type, typename Alloc, typename Tree>
	class setIterator : public std::iterator<std::bidirectional_iterator_tag, value_type>
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
			setIterator() : root(), current()
			{
			}
			setIterator(Nodeptr root, Nodeptr current) : root(root), current(current)
			{
			}
			setIterator(const setIterator & other) : root(other.root), current(other.current)
			{
			}
			~setIterator()
			{
			}
			reference operator*() const {
				return current->data;
			}
			setIterator & operator++() {
				current = BST.findSuccessor(root, current->data);
				if (!current)
					current = root->end;
				return *this;
			}
			setIterator operator++(int) {
				setIterator temp = *this;
				++(*this);
				return temp;
			}
			setIterator & operator--() {
				if (current == root->end)
					current = BST.max(root->right);
				else
					current = BST.findPredecessor(root, current->data);
				return *this;
			}
			setIterator operator--(int) {
				setIterator temp = *this;
				--(*this);
				return temp;
			}
			pointer operator->() const {
				return &(operator*());
			}
			template <typename _bstType, typename _value_type, typename _Alloc, typename _Tree>
			friend bool operator!=(const setIterator<_bstType, _value_type, _Alloc, _Tree> &lhs, const setIterator<_bstType, _value_type, _Alloc, _Tree> &rhs)
			{
				return (lhs.current != rhs.current);
			}
			template <typename _bstType, typename _value_type, typename _Alloc, typename _Tree>
			friend bool operator==(const setIterator<_bstType, _value_type, _Alloc, _Tree> &lhs, const setIterator<_bstType, _value_type, _Alloc, _Tree> &rhs)
			{
				return (lhs.current == rhs.current);
			}
	};

}

#endif // SETITER_HPP