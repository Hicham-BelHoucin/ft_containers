/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:28:47 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/06/20 10:28:51 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory.h>
#include <algorithm>
#include "Iterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		protected:
			typedef T value_type;
			typedef size_t size_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename allocator_type::difference_type difference_type;
			typedef typename ft::Iterator<T>			iterator;
		private:
			T 	*		content;
			Alloc 		allocator;
			size_type 	_size;
			size_type 	index;
		public:

			/* //////////////////////////[ Constructor ]/////////////////////////////// */

			explicit vector(const allocator_type &alloc = allocator_type())
			{
				// Constructs an empty container, with no elements.
				this->_size = 0;
				this->index = 0;
				this->allocator = alloc;
				this->content = nullptr;
			};
			explicit vector(unsigned int n, const value_type &val = value_type(),
							const allocator_type &alloc = allocator_type())
			{
				/*
					Constructs a container with n elements. Each element is a copy of val.
				*/
				this->allocator = alloc;
				this->_size = n;
				this->index = n;
				this->content = new T(n);
				for (int i = 0; i < n; i++)
					this->content[i] = val;
			};
			// template <class InputIterator>
			// vector (InputIterator first, InputIterator last,
			// 		const allocator_type& alloc = allocator_type())
			// {
			// 	/*
			// 		Constructs a container with as many elements as the range [first,last)
			// 		with each element constructed from its corresponding element in that range, in the same order.
			// 	*/
			// 	this->allocator = alloc;
			// 	this->index = 0;
			// 	this->_size = 0;
			// 	for (;first != last; first++)
			// 	{
			// 		T &temp = first;
			// 		this->push_back(temp);
			// 	}
			// };
			vector(const vector &x)
			{
				// Constructs a container with a copy of each of the elements in x, in the same order
				this->allocator = x.allocator;
				// this->content = new T(x._size);
				this->content = this->allocator.allocate(5);
				this->_size = x._size;
				this->index = x.index;
				this->allocator = x.allocator;
				for (int i = 0; i < x.size(); i++)
					this->content[i] = x[i];
			};

			/* //////////////////////////[ Destructors ]/////////////////////////////// */

			~vector()
			{
				if (this->content != nullptr)
					delete[] this->content;
			};

			/* //////////////////////////[ Operators ]/////////////////////////////// */

			vector &operator=(const vector &assign)
			{
				// Constructs a container with a copy of each of the elements in x, in the same order
				this->index = assign.index;
				this->_size = assign._size;
				this->content = assign.content;
				return *this;
			};

			/* //////////////////////////[ Iterators  ]/////////////////////////////// */

			iterator begin()
			{
				return (this->content + 0);
			};
			iterator end()
			{
				return (this->content + index);
			};
			// const_iterator begin() const
			// {

			// };

			/* //////////////////////////[ Capacity  ]/////////////////////////////// */

			void realloc(unsigned int new_cap)
			{
				// copies all elements into an new memory
				T *temp;
				this->index = this->index > new_cap ? new_cap : this->index;
				temp = this->allocator.allocate(index);
				for (int i = 0; i < index; i++)
					temp[i] = this->content[i];
				delete[] this->content;
				this->_size = new_cap;
				this->content = this->allocator.allocate(new_cap);
				for (int i = 0; i < index; i++)
					this->content[i] = temp[i];
			}
			bool empty() const
			{
				// check if the vector is empty
				if (this->size())
					return false;
				return true;
			}
			size_type size() const
			{
				// returns size of the vetor
				return this->index;
			}
			unsigned long max_size() const
			{
				// returns the maximum possible number of elements
				// return std::numeric_limits<difference_type>::max();
				return this->allocator.max_size();
			}
			void resize(size_type n, value_type val = value_type())
			{
				size_type old_size = this->_size;
				if (n == this->size())
					return;
				if (n < this->size())
					realloc(n);
				if (n > this->size())
				{
					realloc(n);
					for (; this->index < n; this->index++)
						this->content[this->index] = val;
				}
				this->_size = old_size;
			}
			void reserve(size_type new_cap)
			{
				// reserves storage
				if (new_cap < this->_size)
					return;
				realloc(new_cap);
			}
			size_type capacity() const
			{
				// returns the number of elements that can be held in currently allocated storage
				return this->_size;
			}
			void shrink_to_fit()
			{
				// reduces memory usage by freeing unused memory
				realloc(index);
			}

			/* //////////////////////////[ Element access  ]/////////////////////////////// */

			reference operator[](unsigned int pos)
			{
				// Returns a reference to the element at specified location pos. No bounds checking is performed.
				return this->content[pos];
			}
			const_reference operator[](unsigned int pos) const
			{
				// Returns a reference to the element at specified location pos. No bounds checking is performed.
				return this->content[pos];
			}
			reference at(unsigned int pos)
			{
				// Returns a reference to the element at specified location pos, with bounds checking.
				// If pos is not within the range of the container, an exception of type std::out_of_range is thrown.
				if (pos < 0 && pos > this->size())
					throw std::out_of_range("out of range !");
				return this->content[pos];
			}
			const_reference at(unsigned int pos) const
			{
				// Returns a reference to the element at specified location pos, with bounds checking.
				// If pos is not within the range of the container, an exception of type std::out_of_range is thrown.
				if (pos < 0 && pos > this->size())
					throw std::out_of_range("out of range  !");
				return this->content[pos];
			}
			reference front()
			{
				// Returns a reference to the first element in the container.
				// Calling front on an empty container is undefined.
				return std::begin(this->content);
			}
			const_reference front() const
			{
				// Returns a reference to the first element in the container.
				// Calling front on an empty container is undefined.
				return std::begin(this->content);
			}
			reference back()
			{
				// Returns a reference to the last element in the container.
				// Calling back on an empty container causes undefined behavior.
				return std::prev(std::end(this->content));
			}
			const_reference back() const
			{
				// Returns a reference to the last element in the container.
				// Calling back on an empty container causes undefined behavior.
				return std::prev(std::end(this->content));
			}

			/* //////////////////////////[ Element access  ]/////////////////////////////// */

			// template <class InputIterator>
			// void assign (InputIterator first, InputIterator last)
			// {
			// 	/*
			// 		the new contents are elements constructed from each of the elements in the range between first and last,
			// 		in the same order.
			// 	*/
			// 	for (;first != last; first++)
			// 	{
			// 		// T &temp = *first;
			// 		this->push_back(0);
			// 	}
			// 	return ;
			// }

			/* //////////////////////////[ Modifiers  ]/////////////////////////////// */

			void assign(size_type n, const value_type &val)
			{
				/*
					the new contents are n elements, each initialized to a copy of val.
				*/
				this->resize(n, val);
				for (int i = 0; i < this->size(); i++)
					this->content[i] = val;
			}
			void push_back(const value_type &value)
			{
				// add a new element to the vector
				if (this->index == 0)
				{
					// if (this->content != nullptr)
					// 	delete [] this->content;
					this->content = this->allocator.allocate(1);
					this->content[index++] = value;
				}
				else
				{
					this->realloc(this->index + (this->index / 4));
					this->content[index++] = value;
				}
			}
			void pop_back()
			{
				this->content[this->index--] = 0;
			}
			/*
			iterator insert (iterator position, const value_type& val)
			{

			}
			void insert (iterator position, size_type n, const value_type& val)
			{

			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last)
			{

			}
			*/
			/*
			iterator erase (iterator position)
			{

			}
			iterator erase (iterator first, iterator last)
			{

			}
			*/
			void swap(vector &x)
			{
				/*
					Exchanges the content of the container by the content of x
					which is another vector object of the same type. Sizes may differ.
				*/
				vector temp;

				temp.content = x.content;
				temp.index = x.index;
				temp._size = x._size;
				x.content = this->content;
				x.index = this->index;
				x._size = this->_size;
				this->content = temp.content;
				this->index = temp.index;
				this->_size = temp._size;
				temp.content = temp.allocator.allocate(1);
				return;
			}
			void clear()
			{
				// Erases all elements from the container
				delete[] this->content;
				this->index = 0;
				this->content = this->allocator.allocate(this->_size);
			}
			allocator_type get_allocator() const
			{
				/*
					Returns a copy of the allocator object associated with the vector.
				*/
				return this->allocator;
			}

			/* //////////////////////////[ Modifiers  ]/////////////////////////////// */

			friend bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
			{
				int capacity;

				if (lhs.size() == rhs.size())
				{
					capacity = lhs.size() > rhs.size() ? lhs.size() : rhs.size();
					for (int i = 0; i < capacity; i++)
						if (lhs.content[i] != rhs.content[i])
							return (false);
					return (true);
				}
				return (false);
			}
			friend bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
			{
				return !(lhs == rhs);
			}
			friend bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
			{
				return !(rhs < lhs);
			}
			friend bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
			{
				return !(lhs < rhs);
			}
			friend bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
			{
				int capacity;

				if (lhs.size() < rhs.size())
					return (true);
				else if (lhs.size() > rhs.size() && lhs != rhs)
					return (false);
				capacity = lhs.size() > rhs.size() ? lhs.size() : rhs.size();
				for (int i = 0; i < capacity; i++)
				{
					if (lhs.content[i] < rhs.content[i])
						return (true);
					else if (lhs.content[i] > rhs.content[i] && lhs != rhs)
						return (false);
				}
				return (false);
			}
			friend bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
			{
				return 	!(lhs < rhs);
			}
			friend void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
			{
				x.swap(y);
			}
	};
}

#endif // VECTOR_HPP