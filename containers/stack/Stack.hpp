/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:53:27 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/27 11:49:56 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "../vector/vector.hpp"
#include <deque>

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		protected:
			Container _c;
		public:
			typedef T												value_type;
			typedef Container										container_type;
			typedef typename container_type::size_type				size_type;
		explicit stack (const container_type& ctnr = container_type()) : _c(ctnr)
		{
		}
		bool empty() const
		{
			return _c.empty();
		}
		size_type size() const
		{
			return _c.size();
		}
		value_type& top()
		{
			return _c.back();
		}
		const value_type& top() const
		{
			return _c.back();
		}
		void push (const value_type& val)
		{
			_c.push_back(val);
		}
		void pop()
		{
			_c.pop_back();
		}
		template <class _T, class _Container>
		friend bool operator== (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs)
		{
			return lhs._c == rhs._c;
		}
		template <class _T, class _Container>
		friend bool operator!= (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs)
		{
			return lhs._c != rhs._c;
		}
		template <class _T, class _Container>
		friend bool operator<  (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs)
		{
			return lhs._c < rhs._c;
		}
		template <class _T, class _Container>
		friend bool operator<= (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs)
		{
			return lhs._c <= rhs._c;
		}
		template <class _T, class _Container>
		friend bool operator>  (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs)
		{
			return lhs._c > rhs._c;
		}
		template <class _T, class _Container>
		friend bool operator>= (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs)
		{
			return lhs._c >= rhs._c;
		}
	};
}

#endif // STACK_HPP