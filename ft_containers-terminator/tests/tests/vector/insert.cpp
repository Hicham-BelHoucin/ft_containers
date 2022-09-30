/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:51:25 by mleblanc          #+#    #+#             */
/*   Updated: 2022/09/29 18:13:36 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_prelude.hpp"

void vec_test_insert()
{
    SETUP_ARRAYS();

    {
        strvector v;

        strvector::iterator it = v.insert(v.end(), b_string[54]);

        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_ALL(v);

        it = v.insert(v.end(), b_string[23]);

        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_ALL(v);

        it = v.insert(v.begin(), b_string[19]);

        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_ALL(v);

        it = v.insert(v.begin() + 1, b_string[0]);

        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_ALL(v);

        it = v.insert(v.begin() + 1, b_string[1]);

        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_ALL(v);

        it = v.insert(v.begin() + 2, b_string[2]);

        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_ALL(v);

        it = v.insert(v.begin() + 3, b_string[3]);

        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_ALL(v);

        it = v.insert(v.begin() + 2, b_string[4]);

        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_ALL(v);

        it = v.insert(v.end(), b_string[5]);

        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_ALL(v);
    }

    {
        intvector v;

        intvector::iterator it = v.insert(v.begin(), 64);

        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_ALL(v);

        it = v.insert(v.end(), 420);

        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_ALL(v);
    }
}

MAIN(vec_test_insert)
