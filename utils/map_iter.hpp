/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:48:21 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/21 09:56:54 by hbel-hou         ###   ########.fr       */
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
	template <typename key_type, typename mapped_type, typename Compare, typename Alloc>
	class mapIterator : public std::iterator<std::bidirectional_iterator_tag, ft::pair<const key_type, mapped_type> >
	{
		public:
			typedef BinarySearchTree<key_type, mapped_type, Compare, Alloc>	bstType;
			typedef	ft::pair<const key_type, mapped_type>					value_type;
			typedef Node<value_type>								 		Tree;
			typedef	value_type&												reference;
			typedef	value_type*												pointer;
		protected:
			bstType	BST;
			Tree	*root;
			Tree	*current;
		public:
			mapIterator() : root(NULL), current(NULL) 
			{
			}
			mapIterator(Tree* & root, Tree* & current) : root(root), current(current) 
			{
			}
			mapIterator(const mapIterator & other) : root(other.root), current(other.current) 
			{
			}
			~mapIterator()
			{
			}
			Tree * getRoot(void) const
			{
				return root;
			}
			Tree * getCurrent(void) const
			{
				return current;
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
					current = root;
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
			template <class Iterator>
			friend bool operator!=(const Iterator &lhs, const Iterator &rhs)
			{
				return (lhs.current != rhs.current);
			}
			template <class Iterator>
			friend bool operator==(const Iterator &lhs, const Iterator &rhs)
			{
				return (lhs.current == rhs.current);
			}
			template <class Iterator>
			friend bool operator<(const Iterator &lhs, const Iterator &rhs)
			{
				return (lhs.current < rhs.current);
			}
			template <class Iterator>
			friend bool operator<=(const Iterator &lhs, const Iterator &rhs)
			{
				return (lhs.current <= rhs.current);
			}
			template <class Iterator>
			friend bool operator>(const Iterator &lhs, const Iterator &rhs)
			{
				return (lhs.current > rhs.current);
			}
			template <class Iterator>
			friend bool operator>=(const Iterator &lhs, const Iterator &rhs)
			{
				return (lhs.current >= rhs.current);
			}
	};
	template <typename key_type, typename mapped_type, typename Compare, typename Alloc>
	class constMapIterator
	{
		public:
			typedef BinarySearchTree<key_type, mapped_type, Compare, Alloc>			bstType;
			typedef	ft::pair<const key_type, mapped_type>							value_type;
			typedef Node<value_type>								 				Tree;
			typedef	const value_type&												reference;
			typedef	const value_type*												pointer;
		constMapIterator() : BST(), root(NULL), current(NULL)
		{
		}
		constMapIterator(Tree const * root, Tree const * current) : BST(), root(root), current(current)
		{
		}
		~constMapIterator()
		{
		}
		Tree const * getRoot(void) const
		{
			return root;
		}
		Tree const * getCurrent(void) const
		{
			return current;
		}
		reference operator*() const {
			return current->data;
		}
		pointer operator->() const {
			return &(operator*());
		}
		constMapIterator & operator++() {
			current = BST.findSuccessor(root, current->data.first);
			return *this;
		}
		constMapIterator operator++(int) {
			constMapIterator temp = *this;
			++(*this);
			return temp;
		}
		constMapIterator & operator--() {
			if (current == root->end)
				current = BST.max(root);
			else
				current = BST.findPredecessor(root, current->data.first);
			return *this;
		}
		constMapIterator operator--(int) {
			constMapIterator temp = *this;
			--(*this);
			return temp;
		}
		template <class Iterator>
		friend bool operator!=(const Iterator &lhs, const Iterator &rhs)
		{
			return (lhs.current != rhs.current);
		}
		template <class Iterator>
		friend bool operator!=(const Iterator &lhs, const Iterator &rhs)
		{
			return (lhs.current != rhs.current);
		}
		template <class Iterator>
		friend bool operator==(const Iterator &lhs, const Iterator &rhs)
		{
			return (lhs.current == rhs.current);
		}
		template <class Iterator>
		friend bool operator<(const Iterator &lhs, const Iterator &rhs)
		{
			return (lhs.current < rhs.current);
		}
		template <class Iterator>
		friend bool operator<=(const Iterator &lhs, const Iterator &rhs)
		{
			return (lhs.current <= rhs.current);
		}
		template <class Iterator>
		friend bool operator>(const Iterator &lhs, const Iterator &rhs)
		{
			return (lhs.current > rhs.current);
		}
		template <class Iterator>
		friend bool operator>=(const Iterator &lhs, const Iterator &rhs)
		{
			return (lhs.current >= rhs.current);
		}
		private:
			bstType		BST;
			Tree const *root;
			Tree const *current;
	};
	template <typename iterator>
	class reverse_map_iter 
	{
		public:
			typedef iterator											iterator_type;
			typedef typename iterator::Tree 							Tree;
			typedef	typename iterator::value_type						value_type;
			typedef	typename iterator::reference						reference;
			typedef	typename iterator::pointer							pointer;
			typedef	typename iterator::bstType							bstType;
		protected:
			bstType	BST;
			Tree	*root;
			Tree	*current;
		public:
			reverse_map_iter() : root(NULL), current(NULL) 
			{
			}
			reverse_map_iter(iterator_type it) : root(it.getRoot()), current(it.getCurrent()) 
			{
			}
			template<typename Iter>
			reverse_map_iter(const reverse_map_iter<Iter> & other) : root(other.getRoot()), current(other.getCurrent()) 
			{
			}
			~reverse_map_iter() 
			{
			}
			reference operator*() const {
				reverse_map_iter temp(*this);
				++temp;
				return temp.current->data;
			}
			reverse_map_iter & operator++() {
				if (current == root->end)
					current = BST.max(root);
				else if (current)
					current = BST.findPredecessor(root, current->data.first);
				return *this;
			}
			reverse_map_iter operator++(int) {
				reverse_map_iter temp = *this;
				++(*this);
				return temp;
			}
			reverse_map_iter & operator--() {
				current = BST.findSuccessor(root, current->data.first);
				return *this;
			}
			reverse_map_iter operator--(int) {
				reverse_map_iter temp = *this;
				--(*this);
				return temp;
			}
			pointer operator->() const {
				return &(operator*());
			}
			template <class Iterator>
			friend bool operator!=(const Iterator &lhs, const Iterator &rhs)
			{
				return (lhs.current != rhs.current);
			}
			// template <class Iterator>
			// friend bool operator==(const Iterator &lhs, const Iterator &rhs)
			// {
			// 	return (lhs.current == rhs.current);
			// }
			// template <class Iterator>
			// friend bool operator<(const Iterator &lhs, const Iterator &rhs)
			// {
			// 	return (lhs.current < rhs.current);
			// }
			// template <class Iterator>
			// friend bool operator<=(const Iterator &lhs, const Iterator &rhs)
			// {
			// 	return (lhs.current <= rhs.current);
			// }
			// template <class Iterator>
			// friend bool operator>(const Iterator &lhs, const Iterator &rhs)
			// {
			// 	return (lhs.current > rhs.current);
			// }
			// template <class Iterator>
			// friend bool operator>=(const Iterator &lhs, const Iterator &rhs)
			// {
			// 	return (lhs.current >= rhs.current);
			// }
	};
	template <typename iterator>
	class const_reverse_map_iter
	{
		public:
			typedef iterator											iterator_type;
			typedef typename iterator::Tree 							Tree;
			typedef	typename iterator::value_type						value_type;
			typedef	typename iterator::reference						reference;
			typedef	typename iterator::pointer							pointer;
			typedef	typename iterator::bstType							bstType;
		const_reverse_map_iter()
		{
		}
		const_reverse_map_iter(iterator_type it) : it(it)
		{
		}
		~const_reverse_map_iter()
		{
		}
		const_reverse_map_iter & operator++() {
			it--;
			return *this;
		}
		const_reverse_map_iter operator++(int) {
			const_reverse_map_iter temp = *this;
			++(*this);
			return temp;
		}
		const reference operator*() const {
			iterator_type temp = it;
			temp--;
			return *temp;
		}
		const pointer operator->() {
			return &(operator*());
		}
		// template <class Iterator>
		friend bool operator!=(const const_reverse_map_iter &lhs, const const_reverse_map_iter &rhs)
		{
			return (lhs.it != rhs.it);
		}
		private:
			iterator_type it;
	};
}

#endif // MAP_ITER_HPP