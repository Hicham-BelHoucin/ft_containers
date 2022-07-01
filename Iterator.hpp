/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:51:29 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/06/30 13:15:19 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>

namespace ft
{
    template<typename T>
    class Iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
        protected:
            typedef T                                                                               value_type;
            typedef typename std::iterator<std::random_access_iterator_tag, T>::difference_type  difference_type;
            typedef typename std::iterator<std::random_access_iterator_tag, T>::pointer          pointer;
			typedef typename std::iterator<std::random_access_iterator_tag, T>::reference		reference;
        public:
            Iterator() : _ptr(nullptr)
            {
            }
            Iterator(const pointer & copy) : _ptr(copy._ptr)
            {
            }
			Iterator & operator=(const pointer & assign)
			{
				this->_ptr = assign._ptr;
				return *this;
			}
			~Iterator()
			{
			}
			reference operator*() const
			{
				/*
					Returns a reference to the element pointed to by the iterator.
					Internally, the function decreases a copy of its base iterator and returns the result of dereferencing it.
					The iterator shall point to some object in order to be dereferenceable.
				*/
				return *_ptr;
			}
        private:
            pointer _ptr;
    };
}

#endif // ITERATOR_HPP