/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparisons_eq.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:34:56 by mleblanc          #+#    #+#             */
/*   Updated: 2022/09/28 16:21:43 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_prelude.hpp"

void vec_test_comparisons_eq()
{
    {
        NAMESPACE::vector<long> v1;
        NAMESPACE::vector<long> v2;

        if (v1 == v2) {
            PRINT_MSG("Equal");
        }
    }

    {
        NAMESPACE::vector<long> v1(5, 64);
        NAMESPACE::vector<long> v2;

        if (v1 == v2) {
            PRINT_MSG("Equal.");
        }
    }

    {
        NAMESPACE::vector<long> v1;
        NAMESPACE::vector<long> v2(5, 32);

        if (v1 == v2) {
            PRINT_MSG("Equal..");
        }
    }

    {
        NAMESPACE::vector<long> v1(5, 64);
        NAMESPACE::vector<long> v2(5, 48);

        if (v1 == v2) {
            PRINT_MSG("Equal...");
        }
    }

    {
        NAMESPACE::vector<long> v1(5, 64);
        NAMESPACE::vector<long> v2(5, 64);

        if (v1 == v2) {
            PRINT_MSG("Equal...");
        }
    }

    {
        NAMESPACE::vector<long> v1(5, 64);
        NAMESPACE::vector<long> v2(4, 64);

        if (v1 == v2) {
            PRINT_MSG("Equal....");
        }
    }

    {
        NAMESPACE::vector<long> v1(4);
        NAMESPACE::vector<long> v2(5);

        if (v1 == v2) {
            PRINT_MSG("Equal.....");
        }
    }
}

MAIN(vec_test_comparisons_eq)
