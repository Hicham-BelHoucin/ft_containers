/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_range.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:46:46 by mleblanc          #+#    #+#             */
/*   Updated: 2022/10/01 17:39:38 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_prelude.hpp"
#include <limits>

void map_test_equal_range()
{
    SETUP_ARRAYS();

    {
        intmap m(intstr_arr, intstr_arr + intstr_size);

        m.insert(NAMESPACE::make_pair(34, "kljd9834iuhwet"));
        m.insert(NAMESPACE::make_pair(3468, "dfghe45sywu4hsr"));
        m.insert(NAMESPACE::make_pair(96533, "sdfghthrdfg5456ik"));
        m.insert(NAMESPACE::make_pair(1954894589, "jtt5454wujtjse"));
        m.insert(NAMESPACE::make_pair(7754322, "w4wt5u4wjhstrhj"));
        m.insert(NAMESPACE::make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
        m.insert(NAMESPACE::make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
        m.insert(NAMESPACE::make_pair(4, "asdfhfjgh54w3ag"));
        m.insert(NAMESPACE::make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
        m.insert(NAMESPACE::make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
        m.insert(NAMESPACE::make_pair(453834782, "juytje54yaerdrj"));
        m.insert(NAMESPACE::make_pair(19458942, "j567uysdts56y6uj5r"));
        m.insert(NAMESPACE::make_pair(1245689793, "jr67e5674574668679789ruyerdtadh"));

        NAMESPACE::pair<intmap::iterator, intmap::iterator> eq = m.equal_range(98583944);

        PRINT_EQ_RANGE(eq, m.end());

        eq = m.equal_range(209485948);

        PRINT_EQ_RANGE(eq, m.end());

        eq = m.equal_range(19458942);

        PRINT_EQ_RANGE(eq, m.end());

        eq = m.equal_range(19458941);

        PRINT_EQ_RANGE(eq, m.end());

        eq = m.equal_range(19458943);

        PRINT_EQ_RANGE(eq, m.end());

        eq = m.equal_range(-1);

        PRINT_EQ_RANGE(eq, m.end());

        eq = m.equal_range(3);

        PRINT_EQ_RANGE(eq, m.end());

        eq = m.equal_range(4);

        PRINT_EQ_RANGE(eq, m.end());

        eq = m.equal_range(5);

        PRINT_EQ_RANGE(eq, m.end());

        eq = m.equal_range(0);

        PRINT_EQ_RANGE(eq, m.end());

        eq = m.equal_range(std::numeric_limits<int>::max());

        PRINT_EQ_RANGE(eq, m.end());

    }

    {
        const intmap m;

        NAMESPACE::pair<intmap::const_iterator, intmap::const_iterator> eq =
            m.equal_range(std::numeric_limits<int>::max());

        PRINT_EQ_RANGE(eq, m.end());
    }
}

MAIN(map_test_equal_range)
