/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:45:52 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/12 12:09:21 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
    template <class T1, class T2> 
    struct pair
    {
        typedef T1              first_type;
        typedef T2              second_type;
        first_type              first;
        second_type             second;
        pair() : first(), second()
        {
        };
        template<class U, class V>
        pair (const pair<U, V>& pr) : first(pr.first), second(pr.second)
        {
        };
        pair (const first_type& a, const second_type& b) : first(a), second(b)
        {
        };
        pair& operator= (const pair& pr)
        {
            this->first = pr.first;
            this->second = pr.second;
            return *this;
        };
        template <class _T1, class _T2>
        friend bool operator== (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs);
        template <class _T1, class _T2>
        friend bool operator!= (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs);
        template <class _T1, class _T2>
        friend bool operator<  (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs);
        template <class _T1, class _T2>
        friend bool operator<= (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs);
        template <class _T1, class _T2>
        friend bool operator>  (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs);
        template <class _T1, class _T2>
        friend bool operator>= (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs);
    };
    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return !(lhs == rhs);
    }
    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return lhs.first < rhs.first && lhs.second < rhs.second;
    }
    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return !(rhs < lhs);
    }
    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return rhs < lhs;
    }
    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return !(lhs < rhs);
    }
}

#endif // PAIR_HPP