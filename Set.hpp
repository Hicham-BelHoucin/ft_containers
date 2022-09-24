/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:25:57 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/24 18:41:28 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <iostream>     // std::cout
#include <functional>   // std::less

template < class T, // set::key_type/value_type
    class Compare = std::less<T>,        // set::key_compare/value_compare
    class Alloc = std::allocator<T> >     // set::allocator_type
class set
{
    public:
        typedef T                                       key_type;
        typedef T                                       value_type;
        typedef size_t                                  size_type;
        // typedef T                                       value_type; add key compare
        // typedef T                                       value_type; add value compare
        typedef Alloc                                   allocator_type;
        typedef typename    Alloc::reference            reference
        typedef typename    Alloc::const_reference      const_reference
        typedef typename    Alloc::pointer              pointer
        typedef typename    Alloc::const_pointer        const_pointer
		// still :
			/*
				iterator
				const_iterator
				reverse_iterator
				const_reverse_iterator
				difference_type
			*/
		
};

#endif // SET_HPP