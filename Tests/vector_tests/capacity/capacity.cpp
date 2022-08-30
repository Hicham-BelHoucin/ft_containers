/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:03:05 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/30 11:54:33 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Tests.hpp"

int main ()
{
    vector myvector(15);

    SetValues(myvector.begin(), myvector.end());

    std::cout << myvector.capacity() << std::endl;

    myvector.reserve(820000);
    
    std::cout << myvector.capacity() << std::endl;
}