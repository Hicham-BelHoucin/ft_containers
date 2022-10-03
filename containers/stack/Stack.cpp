/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:49:52 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/02 17:51:22 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack.hpp"
#include <stack>
#include <vector>
#include "./../../testing/Namespace.hpp"

int main(void)
{
    {
        std::deque<int> mydeque (3,100);
        NS::vector<int> myvector (2,200);

        NS::stack<int> first;
        NS::stack<int, std::deque<int> > second (mydeque);

        NS::stack<int, NS::vector<int> > third;
        NS::stack<int, NS::vector<int> > fourth (myvector);

        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of second: " << second.size() << '\n';
        std::cout << "size of third: " << third.size() << '\n';
        std::cout << "size of fourth: " << fourth.size() << '\n';
    }
    {
        NS::stack<int> mystack;
        int sum (0);

        for (int i = 1; i <= 10;i++) mystack.push(i);

        while (!mystack.empty())
        {
            sum += mystack.top();
            mystack.pop();
        }

        std::cout << "total: " << sum << '\n';
    }
    {
        NS::stack<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i = 0; i < 5; i++) myints.push(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.pop();
        std::cout << "2. size: " << myints.size() << '\n';
    }
    {
        NS::stack<int> mystack;

        mystack.push(10);
        mystack.push(20);

        mystack.top() -= 5;

        std::cout << "mystack.top() is now " << mystack.top() << '\n';
    }
    {
        NS::stack<int> mystack;

        for (int i = 0; i < 5; ++i) mystack.push(i);

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
    }
}