/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:50:52 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/03 13:42:14 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector.hpp"
#include <vector>
#include "./../../testing/Namespace.hpp"
# define TESTED_TYPE int
# define Vector NS::vector<TESTED_TYPE>
# define constVector const NS::vector<TESTED_TYPE>
# define Iterator NS::vector<TESTED_TYPE>::iterator
# define size_type	NS::vector<TESTED_TYPE>::size_type
# define constIterator NS::vector<TESTED_TYPE>::const_iterator
# define reverseIterator NS::vector<TESTED_TYPE>::reverse_iterator
# define constReverseIterator NS::vector<TESTED_TYPE>::const_reverse_iterator

template <typename Container>
void	Print(const Container & obj)
{
	typedef	typename	Container::const_iterator		const_iterator;
	std::cout << "your vector contains :" << std::endl;
	for (const_iterator begin = obj.begin(); begin != obj.end(); begin++)
		std::cout << " " << *begin;
	std::cout << std::endl;
}

int main(void)
{
	// construct vector
	Vector		myvector;
	for (int i = 0; i < 100; ++i)
		myvector.push_back(i);
	constVector		myvector1(myvector);

	// print values using [] operator
	for (size_type i = 0; i < myvector.size(); i++)
		std::cout << " " << myvector[i];
	std::cout << std::endl;
	// print values using iterator
	for (Iterator begin = myvector.begin(); begin != myvector.end(); begin++)
		std::cout << " " << *begin;
	std::cout << std::endl;

	// print values using const_iterator
	for (constIterator begin = myvector1.begin(); begin != myvector1.end(); begin++)
	{
		// *begin = 42; // this causes a compile error cuz object is const and you can't modify it
		std::cout << " " << *begin;
	}
	std::cout << std::endl;

	// print values using reverse_iterator
	for (reverseIterator begin = myvector.rbegin(); begin != myvector.rend(); begin++)
	{
		// *begin = 42; // this causes a compile error cuz object is const and you can't modify it
		std::cout << " " << *begin;
	}
	std::cout << std::endl;

	// print values using const_reverse_iterator
	for (constReverseIterator begin = myvector1.rbegin(); begin != myvector1.rend(); begin++)
	{
		// *begin = 42; // this causes a compile error cuz object is const and you can't modify it
		std::cout << " " << *begin;
	}
	std::cout << std::endl;

	// testing capacity member functions
	{
		Vector	myvector;
		Vector	myvector1(5, 100);

		std::cout << "myvector : " << std::endl;
		std::cout << "	capacity : " << myvector.capacity() << std::endl;
		std::cout << "	empty : " << (myvector.empty() ? "True" : "False") << std::endl;
		std::cout << "	max_size : " << myvector.max_size() << std::endl;
		std::cout << "	size : " << myvector.size() << std::endl;
		std::cout << "myvector1 : " << std::endl;
		std::cout << "	empty : " << (myvector1.empty() ? "True" : "False") << std::endl;
		std::cout << "	max_size : " << myvector1.max_size() << std::endl;
		std::cout << "	size : " << myvector1.size() << std::endl;

		std::cout << "myvector : " << std::endl;
		// testing reserve :
		// if new cpacity is less then size => do nothing
		myvector.reserve(3);
		std::cout << "	capacity : " << myvector.capacity() << std::endl;
		std::cout << "	size : " << myvector.size() << std::endl;
		// if new cpacity is begger then size => reserve
		myvector.reserve(10);
		std::cout << "	capacity : " << myvector.capacity() << std::endl;
		std::cout << "	size : " << myvector.size() << std::endl;

	}

	// testing modifiers
	{
		Vector	myvector;
		int	myints[100];

		for (int i = 0; i < 100; i++)
			myints[i] = std::rand() % 100 + 1;
		myvector.erase(myvector.begin(), myvector.end());
		Print(myvector);
		myvector.assign(myints, myints + 100);
		Print(myvector);
		myvector.erase(myvector.begin() + 12);
		Print(myvector);
		myvector.erase(myvector.begin() + 12, myvector.end());
		Print(myvector);
		myvector.assign(10, 100);
		Print(myvector);
	}

	// testing get allocator
	{
		Vector myvector;
		int * p;
		unsigned int i;

		// allocate an array with space for 5 elements using vector's allocator:
		p = myvector.get_allocator().allocate(5);

		// construct values in-place on the array:
		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

		std::cout << "\nThe allocated array contains:";
		for (i=0; i<5; i++) std::cout << ' ' << p[i];
		std::cout << '\n';

		// destroy and deallocate:
		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p,5);
	}

	// testing capacity
	{
		Vector myvector(15);

		SetValues(myvector.begin(), myvector.end());

		std::cout << myvector.capacity() << std::endl;

		myvector.reserve(820000);

		std::cout << myvector.capacity() << std::endl;
	}

	// testing empty
	{
		Vector                      myvector;
		Iterator                   begin, end;


		std::cout << (myvector.empty() ? "true" : "false") << std::endl;

		myvector.push_back(1);

		std::cout << (myvector.empty() ? "true" : "false") << std::endl;

		begin = myvector.begin();
		end = myvector.end();
		PrintVectorValues(begin, end);
	}

	// testing size , cpacity and max_size
	{
		Vector myvector;

		for (int i = 0; i < 10000000; i++) myvector.push_back(i);

		std::cout << "size: " << myvector.size() << "\n";
		std::cout << "capacity: " << myvector.capacity() << "\n";
		std::cout << "max_size: " << myvector.max_size() << "\n";
	}

	// going crazy
	{
		NS::vector<std::string> myvector;
		NS::vector<std::string> myvector1;

		for (int i = 0; i < 10; i++)
			myvector.push_back("helloWorld");

		for (int i = 0; i < 12; i++)
		{
			myvector1.push_back("hicham");
		}

		PrintVectorValues(myvector.begin(), myvector.end(), "myvector : ");
		PrintVectorValues(myvector1.begin(), myvector1.end(), "myvector1 : ");

		NS::swap(myvector1, myvector);

		PrintVectorValues(myvector.begin(), myvector.end(), "myvector : ");
		PrintVectorValues(myvector1.begin(), myvector1.end(), "myvector1 : ");

		myvector.erase(myvector.begin() + 5, myvector.end());
		PrintVectorValues(myvector.begin(), myvector.end(), "myvector : ");

		myvector.clear();
		std::cout << "size : " << myvector.size() << std::endl;
		std::cout << "capacity : " << myvector.capacity() << std::endl;
		PrintVectorValues(myvector.begin(), myvector.end(), "myvector : ");

		for (int i = 0; i < 12; i++)
		{
			myvector.push_back("hicham");
		}
		myvector1 = myvector;
		PrintVectorValues(myvector1.begin(), myvector1.end(), "myvector1 : ");

		myvector.insert(myvector.end() - 2, "testing insert_pos ");

		NS::vector<std::string > v(5, "testing insert_range");

		myvector.insert(myvector.begin() + 2,v.begin(), v.end());

		PrintVectorValues(myvector.begin(), myvector.end(), "myvector : ");

	}

	// testing max_size
	{
		std::cout << "max_size of char : " << NS::vector<char>().max_size() << std::endl;
		std::cout << "max_size of signed char : " << NS::vector<signed char>().max_size() << std::endl;
		std::cout << "max_size of unsigned char : " << NS::vector<unsigned char>().max_size() << std::endl;
		std::cout << "max_size of int : " << NS::vector<int>().max_size() << std::endl;
		std::cout << "max_size of unsigned int : " << NS::vector<unsigned int>().max_size() << std::endl;
		std::cout << "max_size of long : " << NS::vector<long>().max_size() << std::endl;
		std::cout << "max_size of long int : " << NS::vector<long int>().max_size() << std::endl;
		std::cout << "max_size of short int : " << NS::vector<short int>().max_size() << std::endl;
		std::cout << "max_size of long long : " << NS::vector<long long>().max_size() << std::endl;
	}
    return 0;
}