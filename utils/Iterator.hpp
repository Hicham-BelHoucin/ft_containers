/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:51:29 by hbel-hou          #+#    #+#             */
/*   Updated: 2023/02/19 22:47:00 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>
# include "iterator_traits.hpp"
# include <iostream>

namespace ft
{
    template<typename T>
    class Iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
        public:
            typedef T													value_type;
            typedef typename ft::iterator_traits<T>::difference_type 	difference_type;
            typedef typename ft::iterator_traits<T>::pointer         	pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;
            Iterator() : _ptr(nullptr)
            {
            }
			explicit Iterator(pointer it) : _ptr(it)
			{
			}
			template <class iter>
			Iterator (const Iterator<iter> & it) : _ptr(it.base())
			{
			}
			~Iterator()
			{
			}
			reference operator*() const
			{
				return *_ptr;
			}
			value_type base() const
			{
				return this->_ptr;
			}
			Iterator operator+ (difference_type n) const
			{
				Iterator temp = *this;
				temp._ptr += n;
				return temp;
			}
			Iterator& operator++()
			{
				this->_ptr++;
				return *this;
			}
			Iterator  operator++(int)
			{
				Iterator temp = *this;
				++(*this);
				return temp;
			}
			Iterator& operator+= (difference_type n)
			{
				this->_ptr += n;
				return (*this);
			}

			Iterator& operator-= (difference_type n)
			{
				this->_ptr -= n;
				return (*this);
			}
			Iterator operator- (difference_type n) const
			{
				Iterator temp = *this;
				temp._ptr -= n;
				return temp;
			}
			Iterator& operator--()
			{
				this->_ptr--;
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
			reference operator[] (difference_type n) const
			{
				return *(_ptr + n);
			}
			template <class _Tp, class __Tp>
			friend bool operator==(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs)
			{
				return (lhs._ptr == rhs._ptr);
			}
			template <class _Tp, class __Tp>
			friend bool operator!=(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs)
			{
				return (lhs._ptr != rhs._ptr);
			}
			template <class _Tp, class __Tp>
			friend bool operator<(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs)
			{
				return (lhs._ptr < rhs._ptr);
			}
			template <class _Tp, class __Tp>
			friend bool operator<=(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs)
			{
				return (lhs._ptr <= rhs._ptr);
			}
			template <class _Tp, class __Tp>
			friend bool operator>(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs)
			{
				return (lhs._ptr > rhs._ptr);
			}
			template <class _Tp, class __Tp>
			friend bool operator>=(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs)
			{
				return (lhs._ptr >= rhs._ptr);
			}
			template <class _Tp>
			friend Iterator<_Tp> operator+ (
						typename Iterator<_Tp>::difference_type n,
						const Iterator<_Tp>& rev_it)
			{
				return rev_it + n;
			}
			template <class _Tp, class __Tp>
			friend typename Iterator<_Tp>::difference_type operator- (
				const Iterator<_Tp>& lhs,
				const Iterator<__Tp>& rhs)
			{
				return lhs._ptr - rhs._ptr;
			}

        private:
            pointer _ptr;
    };
}

#endif // ITERATOR_HPP