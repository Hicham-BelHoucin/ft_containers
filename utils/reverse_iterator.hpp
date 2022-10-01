/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:35:15 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/30 15:14:25 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "Iterator.hpp"

namespace ft
{
	template <typename iterator>
	class reverse_iterator : public Iterator<iterator>
	{
		public:
			typedef iterator                                           				iterator_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type 	difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer         	pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference			reference;
			/******************************[ constructor ]**********************************/

			reverse_iterator() : _ptr(nullptr)
			{
			}
			explicit reverse_iterator (iterator_type it) : _ptr(it.base())
			{
			}
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _ptr(rev_it.base().base())
			{
			}

			/******************************[ operators ]**********************************/

			iterator_type base() const
			{
				return iterator_type(this->_ptr);
			}

			reference operator*() const
			{
				return *(this->_ptr - 1);
			}

			reverse_iterator operator+ (difference_type n) const
			{
				reverse_iterator tmp = *this;
				tmp._ptr -= n;
				return (tmp);
			}

			reverse_iterator& operator++()
			{
				this->_ptr--;
				return *this;
			}

			reverse_iterator  operator++(int)
			{
				reverse_iterator tmp = *this;
				++(*this);
				return tmp;
			}

			reverse_iterator& operator+= (difference_type n)
			{
				this->_ptr -= n;
				return *this;
			}

			reverse_iterator operator- (difference_type n) const
			{
				reverse_iterator tmp = *this;
				tmp._ptr += n;
				return tmp;
			}

			reverse_iterator& operator--()
			{
				this->_ptr++;
				return *this;
			}
			reverse_iterator  operator--(int)
			{
				reverse_iterator tmp = *this;
				--(*this);
				return tmp;
			}

			reverse_iterator& operator-= (difference_type n)
			{
				this->_ptr += n;
				return *this;
			}

			pointer operator->() const
			{
				return &(operator*());
			}

			reference operator[] (difference_type n) const
			{
				++n;
				return *(this->_ptr - n);
			}

			template <class _Tp, class __Tp>
			friend bool operator==(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs)
			{
				return (lhs._ptr == rhs._ptr);
			}
			template <class _Tp, class __Tp>
			friend bool operator!=(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs)
			{
				return (lhs._ptr != rhs._ptr);
			}
			template <class _Tp, class __Tp>
			friend bool operator<(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs)
			{
				return (lhs._ptr < rhs._ptr);
			}
			template <class _Tp, class __Tp>
			friend bool operator<=(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs)
			{
				return (lhs._ptr <= rhs._ptr);
			}
			template <class _Tp, class __Tp>
			friend bool operator>(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs)
			{
				return (lhs._ptr > rhs._ptr);
			}
			template <class _Tp, class __Tp>
			friend bool operator>=(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs)
			{
				return (lhs._ptr >= rhs._ptr);
			}
			template <class _Tp>
			friend reverse_iterator<_Tp> operator+ (
						typename reverse_iterator<_Tp>::difference_type n,
						const reverse_iterator<_Tp>& rev_it)
			{
				return rev_it + n;
			}
			template <class _Tp, class __Tp>
			friend typename reverse_iterator<_Tp>::difference_type operator- (
				const reverse_iterator<_Tp>& lhs,
				const reverse_iterator<__Tp>& rhs)
			{
				return rhs._ptr - lhs._ptr;
			}

		private:
			pointer _ptr;
	};
}

#endif // REVERSE_ITERATOR_HPP