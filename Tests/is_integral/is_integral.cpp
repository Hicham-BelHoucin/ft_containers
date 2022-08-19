/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:32:04 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/11 10:34:51 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tests.hpp"

int main() 
{
    std::cout << std::boolalpha;
    std::cout << "is_integral:" << std::endl;
    std::cout << "char: " << NAME_SPACE::is_integral<char>::value << std::endl; 
    std::cout << "int: " << NAME_SPACE::is_integral<int>::value << std::endl;
    std::cout << "float: " << NAME_SPACE::is_integral<float>::value << std::endl;
    return 0;
}