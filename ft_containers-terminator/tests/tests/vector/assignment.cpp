/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:32:09 by mleblanc          #+#    #+#             */
/*   Updated: 2022/09/28 15:56:19 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_prelude.hpp"

void vec_test_assignment()
{
    SETUP_ARRAYS();

    {
        strvector v1;
        strvector v2;

        v1 = v2;

        CHECK_AND_PRINT_ALL(v1);

        v2 = strvector(b_string, b_string + b_size);

        CHECK_AND_PRINT_ALL(v2);

        v1 = v2;

        CHECK_AND_PRINT_ALL(v1);

        v2 = strvector(s_string, s_string + s_size);

        CHECK_AND_PRINT_ALL(v2);

        v1 = v2;

        CHECK_AND_PRINT_ALL(v1);
    }
}

MAIN(vec_test_assignment)
