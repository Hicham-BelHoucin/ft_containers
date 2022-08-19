/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:27:08 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/11 11:30:43 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tests.hpp"

template <class T>
typename NAME_SPACE::enable_if<NAME_SPACE::is_integral<T>::value,bool>::type
is_odd (T i) 
{
    return bool(i % 2);
}

template < class T>
bool is_even (T i, typename NAME_SPACE::enable_if<NAME_SPACE::is_integral<T>::value>::type* = nullptr)
{
    return !bool(i % 2);
}

int main() 
{

    short int i = 1;    // code does not compile if type of i is not integral

    std::cout << std::boolalpha;
    std::cout << "i is odd: " << is_odd(i) << std::endl;
    std::cout << "i is even: " << is_even(i) << std::endl;

    return 0;
}