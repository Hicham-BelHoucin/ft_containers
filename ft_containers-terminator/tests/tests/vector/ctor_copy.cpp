/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctor_copy.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:35:45 by mleblanc          #+#    #+#             */
/*   Updated: 2022/09/30 13:24:50 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_prelude.hpp"

void vec_test_ctor_copy()
{
    SETUP_ARRAYS();

    {
        doublevector v1(b_double, b_double + b_size);

        CHECK_AND_PRINT_ALL(v1);

        doublevector v2(v1);

        CHECK_AND_PRINT_ALL(v2);

        if (&v1[0] == &v2[0]) {
            PRINT_MSG("Copy ctor doesn't do a deep copy!");
        }
    }

    {
        strvector v1(b_string, b_string + b_size);

        CHECK_AND_PRINT_ALL(v1);

        strvector v2(v1);

        CHECK_AND_PRINT_ALL(v2);

        if (&v1[0] == &v2[0]) {
            PRINT_MSG("Copy ctor doesn't do a deep copy!");
        }
    }
}

MAIN(vec_test_ctor_copy)
