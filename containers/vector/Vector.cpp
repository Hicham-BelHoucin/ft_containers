/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:50:52 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/27 11:46:30 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector.hpp"

# define RESET   		"\033[0m"
# define BLACK   		"\033[30m"      		/* Black */
# define RED     		"\033[31m"      		/* Red */
# define GREEN   		"\033[32m"      		/* Green */
# define YELLOW  		"\033[33m"      		/* Yellow */
# define BLUE    		"\033[34m"      		/* Blue */
# define MAGENTA 		"\033[35m"      		/* Magenta */
# define CYAN    		"\033[36m"      		/* Cyan */
# define WHITE   		"\033[37m"      		/* White */
# define BOLDBLACK   	"\033[1m\033[30m"      	/* Bold Black */
# define BOLDRED     	"\033[1m\033[31m"      	/* Bold Red */
# define BOLDGREEN   	"\033[1m\033[32m"      	/* Bold Green */
# define BOLDYELLOW  	"\033[1m\033[33m"      	/* Bold Yellow */
# define BOLDBLUE    	"\033[1m\033[34m"      	/* Bold Blue */
# define BOLDMAGENTA 	"\033[1m\033[35m"      	/* Bold Magenta */
# define BOLDCYAN    	"\033[1m\033[36m"      	/* Bold Cyan */
# define BOLDWHITE   	"\033[1m\033[37m"      	/* Bold White */
# define TESTED_TYPE int
# define NS	ft
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
	std::cout << BOLDRED << "your vector contains :" << std::endl;
	std::cout << BOLDBLUE;
	for (const_iterator begin = obj.begin(); begin != obj.end(); begin++)
		std::cout << " " << *begin;
	std::cout << RESET << std::endl;
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
		myvector.assign(10, 100);
		Print(myvector);
		myvector.erase(myvector.begin(), myvector.end());
		Print(myvector);
		myvector.assign(myints, myints + 100);
		Print(myvector);
		myvector.erase(myvector.begin() + 12);
		Print(myvector);
		myvector.erase(myvector.begin() + 12, myvector.end());
		Print(myvector);
	}
    return 0;
}