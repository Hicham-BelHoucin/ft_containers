/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:36:16 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/03 14:40:17 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./map.hpp"

# define NS ft

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
void    printMap(T & first)
{
    typedef typename T::iterator iterator;
    iterator begin;
    iterator end;

    begin = first.begin();
    end = first.end();
    while (begin != end)
    {
        std::cout << "key : " << begin->first << " | value : " << begin->second << std::endl;
        begin++;
    }
    std::cout << first.size() << std::endl;
    // std::cout << first.max_size() << std::endl;
    std::cout << (first.empty() ? "True" : "False") << std::endl;
    std::cout << "/***********************************/" << std::endl;
}

int main ()
{
	// testing constructors
    {
        NS::map<char ,int> first;

        first['a']=10;
        first['b']=30;
        first['c']=50;
        first['d']=70;

        NS::map<char,int> second (first.begin(),first.end());

        NS::map<char,int> third (first);

        NS::map<char,int,classcomp> fourth;                 // class as Compare

        bool(*fn_pt)(char,char) = fncomp;

        NS::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

        printMap(first);
        printMap(second);
        printMap(third);
        printMap(fourth);
        printMap(fifth);
    }
    {
        NS::map<char,int> first;
        NS::map<char,int> second;

        first['x']=8;
        first['y']=16;
        first['z']=32;

        second=first;                // second now contains 3 ints
        first=NS::map<char,int>();  // and first is now empty

        std::cout << "Size of first: " << first.size() << '\n';
        std::cout << "Size of second: " << second.size() << '\n';
    }
	// testing count
	{
		NS::map<int, int> m;

		for (int i = 0; i < 10; i++)
			m.insert(ft::make_pair(i * 2, i));

		for (int i = 0; i < 30; i++)
		{
			if (m.count(i))
				std::cout << i << " is in my map" << std::endl;
			else
				std::cout << i << " is not in my map" << std::endl;
		}
	}
	// testing swap
	{
		NS::map<int, std::string> m;
		NS::map<int, std::string> m1;

		for (int i = 0; i < 10; i++)
			m.insert(ft::make_pair(i, "HelloWorld"));
		for (int i = 0; i < 10; i++)
			m1.insert(ft::make_pair(i, "hicham"));
		printMap(m);
		printMap(m1);

		NS::swap(m, m1);

		printMap(m);
		printMap(m1);
	}

	// testing relational operators
	{
		NS::map<int, int> foo,bar;
		foo.insert(NS::make_pair(10, 10));
		bar.insert(NS::make_pair(20, 20));
		bar.insert(NS::make_pair(30, 30));
		foo.insert(NS::make_pair(40, 40));

		// foo ({10,40}) vs bar ({20,30}):
		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}

	//testing get allocator
	{
		NS::map<int, int> mymap;
		NS::map<int, int>::value_type * p;
		unsigned int i;

		// allocate an array of 5 elements using mymap's allocator:
		p= mymap.get_allocator().allocate(5);

		// assign some values to array
		for (i=0; i<5; i++) p[i] = NS::make_pair(i+1*10, 12);

		std::cout << "The allocated array contains:";
		for (i=0; i<5; i++) std::cout << ' ' << p[i].first;
		std::cout << '\n';

		mymap.get_allocator().deallocate(p,5);
	}

	// testing equal_range
	{
		NS::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['l']=30;
		mymap['k']=30;
		mymap['j']=30;

		NS::pair<NS::map<char,int>::iterator,NS::map<char,int>::iterator> ret;
		ret = mymap.equal_range('P');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}

	// testing erase
	{
		NS::map<char,int> mymap;
		NS::map<char,int>::iterator it;
		NS::map<char,int>::iterator end;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		std::cout << it->first << std::endl;
		mymap.erase (it);                   // erasing by iterator

		mymap.erase ('c');                  // erasing by key

		it=mymap.find ('e');
		// end=mymap.find ('f');
		end = mymap.end();                // erasing by key
		mymap.erase (it, end);                  // erasing by range
		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}

	// testing find
	{
		NS::map<char,int> mymap;
		NS::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;


		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);

		// print content:
		std::cout << "elements in mymap:" << '\n';
		std::cout << "a => " << mymap.find('a')->second << '\n';
		std::cout << "c => " << mymap.find('c')->second << '\n';
		std::cout << "d => " << mymap.find('d')->second << '\n';
	}

	// testing value compare
	{
		NS::map<char,int> mymap;

		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;

		std::cout << "mymap contains:\n";

		NS::pair<char,int> highest = *mymap.rbegin();          // last element

		NS::map<char,int>::iterator it = mymap.begin();
		do {
		std::cout << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
	}

	// testing iterators
	{
		{
			NS::map<char,int> mymap;

			mymap['x'] = 100;
			mymap['y'] = 200;
			mymap['z'] = 300;

			// show content:
			NS::map<char,int>::iterator rit;
			NS::map<char,int>::iterator end;
			rit = mymap.begin();
			mymap.erase(rit);
			// rit = mymap.begin();
			end = mymap.end();
			for (; rit != end; ++rit)
				std::cout << rit->first << " => " << rit->second << '\n';
		}
		{
			NS::map<char,int> mymap;

			mymap['x'] = 100;
			mymap['y'] = 200;
			mymap['z'] = 300;

			// show content:
			NS::map<char,int>::reverse_iterator rit;
			NS::map<char,int>::reverse_iterator end;
			rit = mymap.rbegin();
			end = mymap.rend();
			for (; rit != end; ++rit)
				std::cout << rit->first << " => " << rit->second << '\n';
		}
		{
			NS::map<char,int> first;

			first['x'] = 400;
			first['y'] = 500;
			first['z'] = 600;
			// for (int i = 1; i < 20; i++)
			//     first[i] = i;
			const NS::map<char,int> mymap(first);
			// // show content:
			NS::map<char,int>::const_reverse_iterator rit;
			NS::map<char,int>::const_reverse_iterator end;
			rit = mymap.rbegin();
			end = mymap.rend();
			for (;rit != end; rit++)
			{
				std::cout << rit->first << " => " << rit->second << '\n';
			}
		}
		{
			NS::map<char,int> first;

			first['x'] = 400;
			first['y'] = 500;
			first['z'] = 600;
			// for (int i = 1; i < 20; i++)
			//     first[i] = i;
			const NS::map<char,int> mymap(first);
			// // show content:
			NS::map<char,int>::const_iterator rit;
			NS::map<char,int>::const_iterator end;
			rit = mymap.begin();
			// std::cout << rit->first << " => " << rit->second << '\n';
			end = mymap.end();
			for (;rit != end; ++rit)
			{
				std::cout << rit->first << " => " << rit->second << '\n';
			}
		}
	}

	// testing lower and upper_bound
	{
		NS::map<int, int> mymap;
		NS::map<int, int>::iterator itlow,itup;

		for (int i = 1; i < 15; i++)
			if (i != 6)
				mymap[i] = i;


		itlow=mymap.lower_bound (6);  // itlow points to b
		std::cout << itlow->first << itlow ->second << std::endl;
		itlow=mymap.lower_bound (-12);  // itlow points to b
		std::cout << itlow->first << itlow ->second << std::endl;



		// retruns map::end and it should be dereferenced .

		itlow=mymap.lower_bound (454);  // itlow points to b
		std::cout << itlow->first << itlow ->second << std::endl;


		itlow=mymap.lower_bound (9);  // itlow points to b
		std::cout << itlow->first << itlow ->second << std::endl;
		itlow=mymap.lower_bound (2);  // itlow points to b
		std::cout << itlow->first << itlow ->second << std::endl;


		itup=mymap.upper_bound (6);   // itup points to e (not d!)
		std::cout << itup->first << itup ->second << std::endl;
		itup=mymap.upper_bound (-12);   // itup points to e (not d!)
		std::cout << itup->first << itup ->second << std::endl;
		itup=mymap.upper_bound (9);   // itup points to e (not d!)
		std::cout << itup->first << itup ->second << std::endl;
		itup=mymap.upper_bound (2);   // itup points to e (not d!)
		std::cout << itup->first << itup ->second << std::endl;

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		for (NS::map<int, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	}

	// testing insert
	{
		NS::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( NS::pair<char,int>('a',100) );
		mymap.insert ( NS::pair<char,int>('z',200) );

		NS::pair<NS::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( NS::pair<char,int>('z',500) );
		if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		NS::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, NS::pair<char,int>('b',300));  // max efficiency inserting
		// it++;
		std::cout << it->first << std::endl;
		mymap.insert (it, NS::pair<char,int>('c',400));  // no max efficiency inserting

		// third insert function version (range insertion):
		NS::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	}
}