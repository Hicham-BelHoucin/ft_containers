/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:48:21 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/01 18:53:59 by hbel-hou         ###   ########.fr       */
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
			typedef	typename Alloc::reference								reference;
			typedef	typename Alloc::pointer									pointer;
		private:
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
			template <typename _key_type, typename _mapped_type, typename _Compare, typename _Alloc>
			friend bool operator!=(const mapIterator<_key_type, _mapped_type, _Compare, _Alloc> &lhs, const mapIterator<_key_type, _mapped_type, _Compare, _Alloc> &rhs)
			{
				return (lhs.current != rhs.current);
			}
			template <typename _key_type, typename _mapped_type, typename _Compare, typename _Alloc>
			friend bool operator==(const mapIterator<_key_type, _mapped_type, _Compare, _Alloc> &lhs, const mapIterator<_key_type, _mapped_type, _Compare, _Alloc> &rhs)
			{
				return (lhs.current == rhs.current);
			}
	};
	// template <typename key_type, typename mapped_type, typename Compare, typename Alloc>
	// class constMapIterator
	// {
	// 	public:
	// 		typedef BinarySearchTree<key_type, mapped_type, Compare, Alloc>			bstType;
	// 		typedef	ft::pair<const key_type, mapped_type>							value_type;
	// 		typedef Node<value_type>								 				Tree;
	// 		typedef	const value_type&												reference;
	// 		typedef	const value_type*												pointer;
	// 	private:
	// 		bstType		BST;
	// 		Tree const *root;
	// 		Tree const *current;
	// 	public:
	// 	constMapIterator() : BST(), root(NULL), current(NULL)
	// 	{
	// 	}
	// 	constMapIterator(Tree const * root, Tree const * current) : BST(), root(root), current(current)
	// 	{
	// 	}
	// 	template <typename __Iterator>
	// 	constMapIterator(const __Iterator & other) : BST(), root(other.getRoot()), current(other.getCurrent())
	// 	{
	// 	}
	// 	~constMapIterator()
	// 	{
	// 	}
	// 	Tree const * getRoot(void) const
	// 	{
	// 		return root;
	// 	}
	// 	Tree const * getCurrent(void) const
	// 	{
	// 		return current;
	// 	}
	// 	reference operator*() const {
	// 		return current->data;
	// 	}
	// 	pointer operator->() const {
	// 		return &(operator*());
	// 	}
	// 	constMapIterator & operator++() {
	// 		current = BST.findSuccessor(root, current->data.first);
	// 		return *this;
	// 	}
	// 	constMapIterator operator++(int) {
	// 		constMapIterator temp = *this;
	// 		++(*this);
	// 		return temp;
	// 	}
	// 	constMapIterator & operator--() {
	// 		if (current == root->end)
	// 			current = BST.max(root);
	// 		else
	// 			current = BST.findPredecessor(root, current->data.first);
	// 		return *this;
	// 	}
	// 	constMapIterator operator--(int) {
	// 		constMapIterator temp = *this;
	// 		--(*this);
	// 		return temp;
	// 	}
	// 	template <typename _k, typename _m, typename _C, typename _A>
	// 	friend bool operator!=(const mapIterator<_k, _m, _C, _A> &lhs, const constMapIterator<_k, _m, _C, _A> &rhs)
	// 	{
	// 		return (lhs.current != rhs.current);
	// 	}
	// 	template <typename _k, typename _m, typename _C, typename _A>
	// 	friend bool operator==(const mapIterator<_k, _m, _C, _A> &lhs, const constMapIterator<_k, _m, _C, _A> &rhs)
	// 	{
	// 		return (lhs.current == rhs.current);
	// 	}
	// };
}

#endif // MAP_ITER_HPP