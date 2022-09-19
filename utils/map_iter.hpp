/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:48:21 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/19 11:16:13 by hbel-hou         ###   ########.fr       */
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
			Tree	**root;
			Tree	*current;
		public:
			mapIterator() : root(NULL), current(NULL) 
			{
			}
			mapIterator(Tree* & root, Tree* & current) : root(&root), current(current) 
			{
			}
			mapIterator(const mapIterator & other) : root(other.root), current(other.current) 
			{
			}
			~mapIterator()
			{
			}
			Tree ** getRoot(void) const
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
				current = BST.findSuccessor(*root, current->data.first);
				return *this;
			}
			mapIterator operator++(int) {
				mapIterator temp = *this;
				++(*this);
				return temp;
			}
			mapIterator & operator--() {
				if (current == (*root)->end)
					current = *root;
				else
					current = BST.findPredecessor(*root, current->data.first);
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
	class constMapIterator : public mapIterator<key_type, mapped_type, Compare, Alloc>
	{
		public:
			typedef typename mapIterator<key_type, mapped_type, Compare, Alloc>::Tree 							Tree;
			typedef	typename mapIterator<key_type, mapped_type, Compare, Alloc>::value_type						value_type;
			typedef	typename mapIterator<key_type, mapped_type, Compare, Alloc>::reference						reference;
			typedef	typename mapIterator<key_type, mapped_type, Compare, Alloc>::pointer						pointer;
			constMapIterator() : mapIterator<key_type, mapped_type, Compare, Alloc>()
			{
			}
			constMapIterator(const constMapIterator & other )
			{
				this->root = other.root;
				this->current = other.current;
			}
			constMapIterator(Tree* root, Tree * current) : mapIterator<key_type, mapped_type, Compare, Alloc>(root, current)
			{
			}
			~constMapIterator()
			{
			}
			const reference operator*() const {
				return this->current->data;
			}
			const pointer operator->() const {
				return &(operator*());
			}
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
		protected:
			Tree	**root;
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
				if (current == (*root)->end)
					current = (*root)->max(*root);
				else if (current)
					current = current->findPredecessor(*root, current->data.first);
				return *this;
			}
			reverse_map_iter operator++(int) {
				reverse_map_iter temp = *this;
				++(*this);
				return temp;
			}
			reverse_map_iter & operator--() {
				current = current->findSuccessor(*root, current->data.first);
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
		private:
			Tree	*root;
			Tree	*current;
		public:
			const_reverse_map_iter() : root(NULL), current(NULL) 
			{
			}
			const_reverse_map_iter(iterator_type it) : current(it.getCurrent()) 
			{
				this->root = &(**(it.getRoot()));
			}
			template<typename Iter>
			const_reverse_map_iter(const const_reverse_map_iter<Iter> & other) : current(other.getCurrent()) 
			{
				this->root = &(**(other.getRoot()));
			}
			~const_reverse_map_iter() 
			{
			}
			const reference operator*() const {
				const_reverse_map_iter temp(*this);
				++temp;
				return temp.current->data;
			}
			const_reverse_map_iter & operator++() {
				if (current == (root)->end)
					current = (root)->max(root);
				else if (current)
					current = (root)->findPredecessor(root, current->data.first);
				return *this;
			}
			const_reverse_map_iter operator++(int) {
				const_reverse_map_iter temp = *this;
				++(*this);
				return temp;
			}
			const_reverse_map_iter & operator--() {
				current = current->findSuccessor(root, current->data.first);
				return *this;
			}
			const_reverse_map_iter operator--(int) {
				const_reverse_map_iter temp = *this;
				--(*this);
				return temp;
			}
			const pointer operator->() const {
				return &(operator*());
			}
			template <class Iterator>
			friend bool operator!=(const Iterator &lhs, const Iterator &rhs)
			{
				return (lhs.current != rhs.current);
			}
	};
}

#endif // MAP_ITER_HPP