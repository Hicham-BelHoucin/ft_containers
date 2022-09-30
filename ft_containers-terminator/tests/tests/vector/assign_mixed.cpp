/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_mixed.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:29:13 by mleblanc          #+#    #+#             */
/*   Updated: 2022/09/29 18:32:23 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_prelude.hpp"

void test_vec_assign_mixed()
{
    SETUP_ARRAYS();

    // {
    //     strvector v;

    //     v.assign(b_string, b_string + b_size);

    //     CHECK_AND_PRINT_ALL(v);

    //     v.assign(65, "HelloWorld");

    //     CHECK_AND_PRINT_ALL(v);

    //     v.assign(s_string, s_string + s_size);

    //     CHECK_AND_PRINT_ALL(v);
    // }

    {
        doublevector v;

        v.assign(b_double, b_double + b_size);

        CHECK_AND_PRINT_ALL(v);

        v.assign(65, 1.234567);

        CHECK_AND_PRINT_ALL(v);

        v.assign(65, 8765.234567);

        CHECK_AND_PRINT_ALL(v);

        v.assign(s_double, s_double + s_size);

        CHECK_AND_PRINT_ALL(v);
    }
}

MAIN(test_vec_assign_mixed)
