/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:47:09 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/05 10:39:39 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

namespace ft
{
    template<typename _Tp>
    struct Node
    {
        _Tp     data;
        size_t  height;
        Node    *right;
        Node    *left;
        Node    *parent;
        Node    *end;

        Node()
        {
            this->data = _Tp();
            this->height = 1;
            this->end = NULL;
            this->right = NULL;
            this->left = NULL;
            this->parent = NULL;
        }
        Node(_Tp data)
        {
            this->data = data;
            this->height = 1;
            this->end = NULL;
            this->right = NULL;
            this->left = NULL;
            this->parent = NULL;
        }
        friend bool operator== (const Node& lhs, const Node& rhs)
		{
			return lhs.data.first == rhs.data.first;
		}
		friend bool operator> (const Node& lhs, const Node& rhs)
		{
			return lhs.data.first > rhs.data.first;
		}
		friend bool operator< (const Node& lhs, const Node& rhs)
		{
			return lhs.data.first < rhs.data.first;
		}
    };
}

#endif // NODE_HPP