/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:45:15 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/10 08:27:08 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Tests.hpp"

// int main ()
// {
//     NAME_SPACE::vector<TESTED_TYPE>::size_type  sz;
//     NAME_SPACE::vector<TESTED_TYPE>             foo(5);

//     SetValues(foo.begin(), foo.end());
//     sz = foo.capacity();
//     std::cout << sz << std::endl;
//     foo.reserve(10);
//     sz = foo.capacity();
//     std::cout << sz << std::endl;
//     foo.reserve(50);
//     sz = foo.capacity();
//     std::cout << sz << std::endl;
//     foo.reserve(80);
//     sz = foo.capacity();
//     std::cout << sz << std::endl;
//     foo.reserve(100);
//     sz = foo.capacity();
//     std::cout << sz << std::endl;
//     return 0;
// }

int main ()
{
  vector::size_type sz;

  vector foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  vector bar;
  sz = bar.capacity();
  bar.reserve(100);   // this is the only difference with foo above
  std::cout << "making bar grow:\n";
  for (int i=0; i<100; ++i) {
    bar.push_back(i);
    if (sz!=bar.capacity()) {
      sz = bar.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }
  return 0;
}