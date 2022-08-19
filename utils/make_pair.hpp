/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:27:56 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/12 13:30:00 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR
#define MAKE_PAIR

#include "pair.hpp"

namespace ft
{
    template <class T1, class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return pair<T1, T2>(x, y);
    };
}

#endif // MAKE_PAIR