/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:25:57 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/24 18:29:15 by hbel-hou         ###   ########.fr       */
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
    
};

#endif // SET_HPP