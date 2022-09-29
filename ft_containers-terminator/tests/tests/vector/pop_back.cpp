/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_back.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:55:38 by mleblanc          #+#    #+#             */
/*   Updated: 2022/09/28 13:18:51 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_prelude.hpp"

void vec_test_pop_back()
{
    SETUP_ARRAYS();

    {
        longvector v(s_long, s_long + s_size);

        v.pop_back();

        CHECK_AND_PRINT_ALL(v);

        for (int i = 0; i < 10; ++i) {
            v.pop_back();
        }

        CHECK_AND_PRINT_ALL(v);
    }
}

MAIN(vec_test_pop_back)
