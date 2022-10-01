/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:36:08 by mleblanc          #+#    #+#             */
/*   Updated: 2022/10/01 11:52:51 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_prelude.hpp"

void map_test_clear()
{
    SETUP_ARRAYS();

    {
        strmap m;

        PRINT_ALL(m);

        m.clear();

        PRINT_ALL(m);

        m.insert(strstr_arr, strstr_arr + 16);

        PRINT_ALL(m);

        m.clear();

        PRINT_ALL(m);
    }
}

MAIN(map_test_clear)
