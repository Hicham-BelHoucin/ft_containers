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

# include <memory.h>
# include <algorithm>
# include <iostream>
# include "../../utils/Iterator.hpp"
# include "../../utils/reverse_iterator.hpp"
# include "../../utils/is_integral.hpp"
# include "../../utils/enable_if.hpp"
# include "../../utils/equal.hpp"
# include "../../utils/lexicographical_compare.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T 											value_type;
			typedef Alloc 										allocator_type;
			typedef typename allocator_type::size_type 			size_type;
			typedef typename allocator_type::reference 			reference;
			typedef typename allocator_type::const_reference 	const_reference;
			typedef typename allocator_type::pointer 			pointer;
			typedef typename allocator_type::const_pointer 		const_pointer;
			typedef typename allocator_type::difference_type 	difference_type;
		private:
			pointer		content;
			Alloc 		allocator;
			size_type 	_size;
			size_type 	index;
		public:
			typedef typename ft::Iterator<pointer>						iterator;
			typedef typename ft::Iterator<const_pointer>				const_iterator;
			typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			/* //////////////////////////[ Constructor ]/////////////////////////////// */

			explicit vector(const allocator_type &alloc = allocator_type()) : content(nullptr), allocator(alloc), _size(0), index(0)
			{
			};

			explicit vector(size_type n, const value_type &val = value_type(),
							const allocator_type &alloc = allocator_type()) : allocator(alloc)
			{
				if (n > max_size())
					throw std::length_error("");
				else
				{
					this->_size = n;
					this->index = n;
					this->content = this->allocator.allocate(n);
					for (size_type i = 0; i < n; i++)
						allocator.construct(content + i, val);
				}
			};
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = nullptr) : content(nullptr) , allocator(alloc), _size(0), index(0)
			{
				try
				{
					for (; first != last; first++)
						push_back(*first);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			}
			vector(const vector &x)
			{
				try
				{
					this->allocator = x.allocator;
					this->content = this->allocator.allocate((x.capacity()));
					this->_size = x._size;
					this->index = x.index;
					for (size_type i = 0; i < x.index; i++)
						allocator.construct(content + i, x.content[i]);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			};

			/* //////////////////////////[ Destructors ]/////////////////////////////// */

			~vector()
			{
				clear();
				if (this->content != nullptr)
					this->allocator.deallocate(content, _size);
			};

			/* //////////////////////////[ Operators ]/////////////////////////////// */

			vector &operator=(const vector &assign)
			{
				clear();
				if (content)
					allocator.deallocate(content, _size);
				allocator = assign.allocator;
				content = allocator.allocate((assign.capacity()));
				_size = assign._size;
				index = assign.index;
				for (size_type i = 0; i < index; i++)
					allocator.construct(content + i, assign.content[i]);
				return *this;
			};

			/* //////////////////////////[ Iterators  ]/////////////////////////////// */

			iterator begin()
			{
				return (iterator(&this->content[0]));
			};
			iterator end()
			{
				return (iterator(&this->content[index]));
			};

			const_iterator begin() const
			{
				return const_iterator(&this->content[0]);
			};
			const_iterator end() const
			{
				return const_iterator(&this->content[index]);
			};

			reverse_iterator rbegin()
			{
				return reverse_iterator(end());
			}

			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(end());
			}

			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			}

			/* //////////////////////////[ Capacity  ]/////////////////////////////// */

			void realloc(unsigned int new_cap)
			{
				try
				{
					T *temp = nullptr;
					// this->index = this->index > new_cap ? new_cap : this->index;
					temp = this->allocator.allocate(index);
					for (size_type i = 0; i < index; i++)
						temp[i] = this->content[i];
					if (content != nullptr && _size > 0)
					{
						for (size_type i = 0; i < this->index; i++)
							allocator.destroy(content + i);
						allocator.deallocate(content, _size);
					}
					this->_size = new_cap;
					this->content = this->allocator.allocate(new_cap);
					for (size_type i = 0; i < index; i++)
						allocator.construct(content + i, temp[i]);
					this->allocator.deallocate(temp, index);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			}
			bool empty() const
			{
				if (this->size())
					return false;
				return true;
			}
			size_type size() const
			{
				return this->index;
			}
			size_type max_size() const
			{
				return this->allocator.max_size();
			}
			void resize(size_type n, value_type val = value_type())
			{
				if (n > max_size())
					throw std::length_error("");
				else if (n == this->size())
					return;
				else if (n < size())
				{
					while (index > n)
					{
						--index;
						allocator.destroy(content + index);
					}
				}
				else if (n > capacity())
				{
					realloc(n);
					for (; this->index < capacity(); this->index++)
						allocator.construct(content + index, val);
				}
				else if (n > size())
				{
					for (; this->index < capacity(); this->index++)
						allocator.construct(content + index, val);
				}
			}
			void reserve(size_type new_cap)
			{
				if (new_cap < this->_size)
					return;
				realloc(new_cap);
			}
			size_type capacity() const
			{
				return this->_size;
			}

			/* //////////////////////////[ Element access  ]/////////////////////////////// */

			reference operator[](unsigned int pos)
			{
				return this->content[pos];
			}
			const_reference operator[](unsigned int pos) const
			{
				return this->content[pos];
			}
			reference at(unsigned int pos)
			{
				if (pos < 0 || pos >= index)
					throw std::out_of_range("");
				return this->content[pos];
			}
			const_reference at(unsigned int pos) const
			{
				if (pos < 0 || pos >= index)
					throw std::out_of_range("");
				return this->content[pos];
			}
			reference front()
			{
				return this->content[0];
			}
			const_reference front() const
			{
				return this->content[0];
			}
			reference back()
			{
				return this->content[index - 1];
			}
			const_reference back() const
			{
				return this->content[index - 1];
			}

			/* //////////////////////////[ Element access  ]/////////////////////////////// */

			void assign(size_type n, const value_type &val)
			{
				clear();
				if (n > 0)
				{
					if (n <= capacity())
					{
						for (;index < n; index++)
							allocator.construct(content + index, val);
					}
					else if (n > capacity())
					{
						realloc(n);
						for (;index < n; index++)
							allocator.construct(content + index, val);
					}
				}
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
						typename ft::enable_if<!std::is_integral<InputIterator>::value>::type * = nullptr)
			{
				clear();
				index = 0;
				if (_size > 0)
				{
					while (index < _size && first != last)
					{
						allocator.construct(content + index, *first);
						index++;
						first++;
					}
				}
				else
				{
					while (first != last)
					{
						push_back(*first);
						first++;
					}
				}
			}

			/* //////////////////////////[ Modifiers  ]/////////////////////////////// */

			void push_back(const value_type &value)
			{
				if (index == 0)
				{
					content = allocator.allocate(1);
					allocator.construct(content + index, value);
					index++;
					if (!_size)
						_size = 1;
				}
				else
				{
					if (index >= _size)
						realloc(this->_size * 2);
					allocator.construct(content + index, value);
					index++;
				}
			}

			void pop_back()
			{
				if (index >= 0 && index <= size())
				{
					allocator.destroy(content + (index - 1));
					index--;
				}
			}

			iterator insert (iterator position, const value_type& val)
			{
				int			pos = 0;

				pos = &(*position) - content;
				if (position == end())
					push_back(val);
				else if (position == begin())
				{
					vector temp(*this);

					clear();
					push_back(val);
					iterator start = temp.begin();
					while (start != temp.end())
					{
						push_back(*start);
						start++;
					}
				}
				return (iterator(&content[pos]));
			}
			void insert (iterator position, size_type n, const value_type& val)
			{
				value_type myints[n];

				for (size_type i = 0; i < n; i++)
					myints[i] = val;
				insert(position, &myints[0], &myints[n]);
			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
						typename ft::enable_if<!std::is_integral<InputIterator>::value>::type * = nullptr)
			{
				pointer temp;
				size_type __size;
				size_type __pos;
				size_type i;

				__size = (size_type(last - first) + size_type(position - begin()));
				i = 0;
				if (!(__size > capacity()))
					__size = (size_type(last - first) + size_type(end() - begin()));
				temp = allocator.allocate(__size);
				__pos = size_type(position - begin());
				_size = (size_type(last - first) + size_type(end() - begin()));
				while (i < __pos)
				{
					temp[i] = content[i];
					i++;
				}
				while (first != last)
				{
					temp[i] = *first;
					first++;
					i++;
				}
				while (i < __size)
				{
					temp[i] = content[__pos];
					i++;
					__pos++;
				}
				this->allocator.deallocate(content, _size);
				content = temp;
				index = __size;
			}
			iterator erase (iterator position)
			{
				iterator start = position;
				iterator next(position + 1);

				if (position < end())
				{
					allocator.destroy(&(*position));
					while (position < end())
					{
						*position = *next;
						position++;
						next++;
					}
					realloc(size() - 1);
				}
				return start;
			}

			iterator erase (iterator first, iterator last)
			{
				iterator start;

				start = first;
				if (last >= end())
					realloc(size() - (end() - first));
				else
				{
					while (first < end() && last < end())
					{
						*first = *last;
						first++;
						last++;
					}
					realloc(size() - (last - first));
				}
				return start;
			}

			void swap(vector &x)
			{
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
				if (content && size() != 0)
				{
					for (size_type i = 0; i < index; i++)
						allocator.destroy(content + i);
					this->index = 0;
				}
			}
			allocator_type get_allocator() const
			{
				return allocator;
			}
			template <class _T, class _Alloc>
			friend bool operator== (const vector<_T, _Alloc>& lhs, const vector<_T, _Alloc>& rhs);
			template <class _T, class _Alloc>
			friend bool operator!= (const vector<_T, _Alloc>& lhs, const vector<_T, _Alloc>& rhs);
			template <class _T, class _Alloc>
			friend bool operator<  (const vector<_T, _Alloc>& lhs, const vector<_T, _Alloc>& rhs);
			template <class _T, class _Alloc>
			friend bool operator<= (const vector<_T, _Alloc>& lhs, const vector<_T, _Alloc>& rhs);
			template <class _T, class _Alloc>
			friend bool operator>  (const vector<_T, _Alloc>& lhs, const vector<_T, _Alloc>& rhs);
			template <class _T, class _Alloc>
			friend bool operator>= (const vector<_T, _Alloc>& lhs, const vector<_T, _Alloc>& rhs);
	};

	/* //////////////////////////[ Non-member function overloads  ]/////////////////////////////// */
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}
	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return rhs < lhs;
	}
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return 	!(lhs < rhs);
	}
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}
}

#endif // VECTOR_HPP