/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:46:40 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/02 17:25:35 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

#define	NS ft

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

int main(void)
{

	// testing constructors
	{
		NS::set<int> first;                           // empty set of ints

		int myints[]= {10,20,30,40,50};
		NS::set<int> second (myints,myints+5);        // range

		NS::set<int> third (second);                  // a copy of second

		NS::set<int> fourth (second.begin(), second.end());  // iterator ctor.

		NS::set<int,classcomp> fifth;                 // class as Compare

		bool(*fn_pt)(int,int) = fncomp;
		NS::set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare

		NS::set<int>::reverse_iterator	begin = fourth.rbegin();
		while (begin != fourth.rend())
		{
			std::cout << *begin << std::endl;
			begin++;
		}
	}

	// testing insert
	{
		NS::set<int> myset;
		NS::set<int>::iterator it;
		NS::pair<NS::set<int>::iterator,bool> ret;

		// set some initial values:
		for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

		ret = myset.insert(20);               // no new element inserted

		if (ret.second==false) it=ret.first;  // "it" now points to element 20

		myset.insert (it,25);                 // max efficiency inserting
		myset.insert (it,24);                 // max efficiency inserting
		myset.insert (it,26);                 // no max efficiency inserting

		int myints[]= {5,10,15};              // 10 already in set, not inserted
		myset.insert (myints,myints+3);

		std::cout << "myset contains:";
		for (it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	// testing erase
	{
		NS::set<int> myset;
		NS::set<int>::iterator it;

		// insert some values:
		for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

		it = myset.begin();
		++it;                                         // "it" points now to 20

		myset.erase (it);

		myset.erase (40);

		it = myset.find (60);
		myset.erase (it, myset.end());

		std::cout << "myset contains:";
		for (it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	// testing swap
	{
		int myints[]={12,75,10,32,20,25};
		NS::set<int> first (myints,myints+3);     // 10,12,75
		NS::set<int> second (myints+3,myints+6);  // 20,25,32

		first.swap(second);

		std::cout << "first contains:";
		for (NS::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "second contains:";
		for (NS::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	// testing clear
	{
		NS::set<int> myset;

		myset.insert (100);
		myset.insert (200);
		myset.insert (300);

		std::cout << "myset contains:";
		for (NS::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		myset.clear();
		myset.insert (1101);
		myset.insert (2202);

		std::cout << "myset contains:";
		for (NS::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	// testing find
	{
		NS::set<int> myset;
		NS::set<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

		it = myset.find(20);
		myset.erase (it);
		myset.erase (myset.find(40));

		std::cout << "myset contains:";
		for (it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	// testing count
	{
		NS::set<int> myset;

		// set some initial values:
		for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12

		for (int i=0; i<15; ++i)
		{
			std::cout << i;
			if (myset.count(i)!=0)
				std::cout << " is an element of myset.\n";
			else
				std::cout << " is not an element of myset.\n";
		}
	}

	// testing lower bound
	{
		NS::set<int> myset;
		NS::set<int>::iterator itlow,itup;

		for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

		itlow=myset.lower_bound (30);                //       ^
		itup=myset.upper_bound (60);                 //                   ^

		myset.erase(itlow,itup);                     // 10 20 70 80 90

		std::cout << "myset contains:";
		for (NS::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	// testing upper_bound
	{
		NS::set<int> myset;
		NS::set<int>::iterator itlow,itup;

		for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

		itlow=myset.lower_bound (30);                //       ^
		itup=myset.upper_bound (60);                 //                   ^

		myset.erase(itlow,itup);                     // 10 20 70 80 90

		std::cout << "myset contains:";
		for (NS::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	// testing equal_range
	{
		NS::set<int> myset;

		for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

		NS::pair<NS::set<int>::iterator, NS::set<int>::iterator> ret;

		ret = myset.equal_range(30);

		std::cout << "the lower bound points to: " << *ret.first << '\n';
		std::cout << "the upper bound points to: " << *ret.second << '\n';
	}

	//testing get allocator
	{
		NS::set<int> myset;
		int * p;
		unsigned int i;

		// allocate an array of 5 elements using myset's allocator:
		p= myset.get_allocator().allocate(5);

		// assign some values to array
		for (i=0; i<5; i++) p[i]=(i+1)*10;

		std::cout << "The allocated array contains:";
		for (i=0; i<5; i++) std::cout << ' ' << p[i];
		std::cout << '\n';

		myset.get_allocator().deallocate(p,5);
	}

	// testing relational operators
	{
		NS::set<int> foo,bar;
		foo.insert(10);
		bar.insert(20);
		bar.insert(30);
		foo.insert(40);

		// foo ({10,40}) vs bar ({20,30}):
		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}

	// testing swap
	{
		int myints[]={12,75,10,32,20,25};
		NS::set<int> first (myints,myints+3);     // 10,12,75
		NS::set<int> second (myints+3,myints+6);  // 20,25,32

		NS::swap(first,second);

		std::cout << "first contains:";
		for (NS::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "second contains:";
		for (NS::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	// system("leaks a.out");
}