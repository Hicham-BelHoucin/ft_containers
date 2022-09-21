/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:49:52 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/21 10:53:51 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Stack.hpp"
#define NAME_SPACE ft
int main(void)
{
    {
        std::deque<int> mydeque (3,100);
        NAME_SPACE::vector<int> myvector (2,200);       

        NAME_SPACE::stack<int> first;                   
        NAME_SPACE::stack<int, std::deque<int> > second (mydeque);     

        NAME_SPACE::stack<int, NAME_SPACE::vector<int> > third; 
        NAME_SPACE::stack<int, NAME_SPACE::vector<int> > fourth (myvector);

        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of second: " << second.size() << '\n';
        std::cout << "size of third: " << third.size() << '\n';
        std::cout << "size of fourth: " << fourth.size() << '\n';
    }
    {
        NAME_SPACE::stack<int> mystack;
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
        NAME_SPACE::stack<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i = 0; i < 5; i++) myints.push(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.pop();
        std::cout << "2. size: " << myints.size() << '\n';
    }
    {
        NAME_SPACE::stack<int> mystack;

        mystack.push(10);
        mystack.push(20);

        mystack.top() -= 5;

        std::cout << "mystack.top() is now " << mystack.top() << '\n';
    }
    {
        NAME_SPACE::stack<int> mystack;

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