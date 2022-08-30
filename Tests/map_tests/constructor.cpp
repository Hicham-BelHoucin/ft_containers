/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:27:42 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/30 16:42:48 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tests.hpp"

bool fncomp (char lhs, char rhs) 
{
    return lhs<rhs;
}

struct classcomp 
{
    bool operator() (const char& lhs, const char& rhs) const
    {
        return lhs<rhs;
    }
};

template <class T>
void    printMap(T first)
{
    typedef typename T::iterator iterator;
    iterator begin;
    iterator end;

    begin = first.begin();
    end = first.end();
    while (begin != end)
    {
        std::cout << begin->first << std::endl;
        begin++;
    }
    std::cout << first.size() << std::endl;
    std::cout << first.max_size() << std::endl;
    std::cout << (first.empty() ? "True" : "False") << std::endl;
    std::cout << "/***********************************/" << std::endl;
}

int main ()
{
    {

        // Default Constructor : 
        NAME_SPACE::map<char ,int> first;

        first['a']=10;
        first['b']=30;
        first['c']=50;
        first['d']=70;

        NAME_SPACE::map<char,int> second (first.begin(),first.end());

        NAME_SPACE::map<char,int> third (first);

        NAME_SPACE::map<char,int,classcomp> fourth;                 // class as Compare

        bool(*fn_pt)(char,char) = fncomp;
        NAME_SPACE::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

        printMap(first);
        printMap(second);
        printMap(third);
        printMap(fourth);
        printMap(fifth);
    }
    {
        NAME_SPACE::map<char,int> first;
        NAME_SPACE::map<char,int> second;

        first['x']=8;
        first['y']=16;
        first['z']=32;

        second=first;                // second now contains 3 ints
        first=NAME_SPACE::map<char,int>();  // and first is now empty

        std::cout << "Size of first: " << first.size() << '\n';
        std::cout << "Size of second: " << second.size() << '\n';
    }
    return 0;
}

// #include <iostream>
// #include <string>
// #include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	// namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
// 	#include <vector.hpp>
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->_c = rhs._c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->_c.begin(); }
// 	iterator end() { return this->_c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	// MutantStack<char> iterable_stack;
// 	// for (char letter = 'a'; letter <= 'z'; letter++)
// 	// 	iterable_stack.push(letter);
// 	// for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	// {
// 	// 	std::cout << *it;
// 	// }
// 	// std::cout << std::endl;
// 	return (0);
// }
