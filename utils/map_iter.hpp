/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:48:21 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/23 14:32:51 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITER_HPP
#define MAP_ITER_HPP

# include <iterator>
# include "iterator_traits.hpp"

namespace ft
{
	template <typename T, typename _Tree>
	class Iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		public:
				typedef T															value_type;
				typedef typename ft::iterator_traits<value_type>::pointer         	pointer;
				typedef typename ft::iterator_traits<value_type>::reference			reference;
				Iterator() : root(nullptr), current(nullptr)
				{
				}
				explicit Iterator(_Tree it) : root(it)
				{
					this->current = root->min(root);
				}
				template <class iter, class Tree>
				Iterator (const Iterator<iter, Tree> & it) : root(it.root), current(it.current)
				{
				}
				~Iterator()
				{
				}
				reference operator*() const
				{
					return current->data;
				}
				Iterator& operator++()
				{
					current = current->findSuccessor(root, current->data.first);
					return *this;
				}
				Iterator  operator++(int)
				{
					Iterator temp = *this;
					++(*this);
					return *this;
				}
				Iterator& operator--()
				{
					current = current->findPredecessor(root, current->data.first);
					return *this;
				}
				Iterator  operator--(int)
				{
					Iterator temp = *this;
					--(*this);
					return temp;
				}
				pointer operator->() const
				{
					return &(operator*());
				}
				template <class _Iterator>
				friend bool operator== (const _Iterator& lhs,
								const _Iterator& rhs);
				template <class _Iterator>
				friend bool operator!= (const _Iterator& lhs,
								const _Iterator& rhs);
				template <class _Iterator>
				friend bool operator<  (const _Iterator& lhs,
								const _Iterator& rhs);
				template <class _Iterator>
				friend bool operator<= (const _Iterator& lhs,
								const _Iterator& rhs);
				template <class _Iterator>
				friend bool operator>  (const _Iterator& lhs,
								const _Iterator& rhs);
				template <class _Iterator>
				friend bool operator>= (const _Iterator& lhs,
								const _Iterator& rhs);

			private:
				_Tree root;
				_Tree current;
	};
	template <class Iterator>
	bool operator!=(const Iterator &lhs, const Iterator &rhs)
	{
		return (lhs.current != rhs.current);
	}
	template <class Iterator>
	bool operator==(const Iterator &lhs, const Iterator &rhs)
	{
		return (lhs.current == rhs.current);
	}
	template <class Iterator>
	bool operator<(const Iterator &lhs, const Iterator &rhs)
	{
		return (lhs.current < rhs.current);
	}
	template <class Iterator>
	bool operator<=(const Iterator &lhs, const Iterator &rhs)
	{
		return (lhs.current <= rhs.current);
	}
	template <class Iterator>
	bool operator>(const Iterator &lhs, const Iterator &rhs)
	{
		return (lhs.current > rhs.current);
	}
	template <class Iterator>
	bool operator>=(const Iterator &lhs, const Iterator &rhs)
	{
		return (lhs.current >= rhs.current);
	}
}

#endif // MAP_ITER_HPP