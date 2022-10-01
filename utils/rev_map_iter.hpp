/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_map_iter.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:10:40 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/01 18:56:24 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_MAP_ITER_HPP
#define REV_MAP_ITER_HPP

namespace ft
{
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
		reverse_map_iter()
		{
		}
		reverse_map_iter(iterator_type it) : it(it)
		{
		}
		~reverse_map_iter()
		{
		}
		reverse_map_iter & operator++() {
			it--;
			return *this;
		}
		reverse_map_iter operator++(int) {
			reverse_map_iter temp = *this;
			++(*this);
			return temp;
		}
		reverse_map_iter & operator--() {
			it++;
			return *this;
		}
		reverse_map_iter operator--(int) {
			reverse_map_iter temp = *this;
			--(*this);
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
		template <class revIterator>
		friend bool operator!=(const reverse_map_iter<revIterator> &lhs, const reverse_map_iter<revIterator> &rhs)
		{
			return (lhs.it != rhs.it);
		}
		template <class revIterator>
		friend bool operator==(const reverse_map_iter<revIterator> &lhs, const reverse_map_iter<revIterator> &rhs)
		{
			return (lhs.it == rhs.it);
		}
		private:
			iterator_type it;
	};
}

#endif // REV_MAP_ITER_HPP