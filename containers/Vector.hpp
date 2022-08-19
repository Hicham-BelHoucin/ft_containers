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
# include "../utils/Iterator.hpp"
# include "../utils/reverse_iterator.hpp"
# include "../utils/is_integral.hpp"
# include "../utils/enable_if.hpp"
# include "../utils/equal.hpp"
# include "../utils/lexicographical_compare.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T 											value_type;
			typedef Alloc 										allocator_type;
			typedef typename allocator_type::reference 			reference;
			typedef typename allocator_type::size_type 			size_type;
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

			explicit vector(const allocator_type &alloc = allocator_type()) : allocator(alloc)
			{
				this->_size = 0;
				this->index = 0;
				this->content = nullptr;
			};
			explicit vector(size_type n, const value_type &val = value_type(),
							const allocator_type &alloc = allocator_type()) : allocator(alloc)
			{
				try
				{
					this->_size = n;
					this->index = n;
					this->content = this->allocator.allocate(n);
					for (int i = 0; i < n; i++)
						this->content[i] = val;
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			};
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = nullptr) : allocator(alloc)
			{
				try
				{
					this->content = this->allocator.allocate((last - first));
					this->index = 0;
					for (; first < last; first++)
					{
						this->content[this->index] = *first;
						this->index++;
					}
					this->_size = this->index;
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
					this->content = this->allocator.allocate((x.size()));
					this->_size = x._size;
					this->index = x.index;
					for (int i = 0; i < x.index; i++)
						this->content[i] = x.content[i];
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			};

			/* //////////////////////////[ Destructors ]/////////////////////////////// */

			~vector()
			{
				if (this->content != nullptr)
					this->allocator.deallocate(content, _size);
			};

			/* //////////////////////////[ Operators ]/////////////////////////////// */

			vector &operator=(const vector &assign)
			{
				try
				{
					this->allocator = assign.allocator;
					this->content = this->allocator.allocate((assign.size()));
					this->_size = assign._size;
					this->index = assign.index;
					for (int i = 0; i < assign.index; i++)
						this->content[i] = assign.content[i];
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
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
				return const_reverse_iterator(begin());
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
			unsigned long max_size() const
			{
				return this->allocator.max_size();
			}
			void resize(size_type n, value_type val = value_type())
			{
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
				if (pos < 0 && pos > this->size())
					throw std::out_of_range("out of range !");
				return this->content[pos];
			}
			const_reference at(unsigned int pos) const
			{
				if (pos < 0 && pos > this->size())
					throw std::out_of_range("out of range  !");
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
				this->resize(n, val);
				for (int i = 0; i < this->size(); i++)
					this->content[i] = val;
			}
			
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
						typename ft::enable_if<!std::is_integral<InputIterator>::value>::type * = nullptr)
			{
				this->resize((last - first), 0);
				for (int i = 0;first < last; first++)
				{
					this->content[i] = *first;
					i++;
				}
				return ;
			}

			/* //////////////////////////[ Modifiers  ]/////////////////////////////// */

			void push_back(const value_type &value)
			{
				if (this->index == 0)
				{
					this->content = this->allocator.allocate(1);
					this->content[index++] = value;
					if (!_size)
						_size = 1;
				}
				else
				{
					if (index >= _size)
						this->realloc(this->index * 2);
					this->content[index++] = value;
				}
			}
			void pop_back()
			{
				this->content[this->index--] = 0;
			}
			
			iterator insert (iterator position, const value_type& val)
			{
				int			pos;

				if (position > end())
				{
					resize(position - begin() + 1);
					*(end() - 1) = val;
					pos = position - begin();
				}
				else
				{
					vector	temp(position, end());
					iterator	__begin;

					pos = position - begin();
					resize(capacity() + 1);
					*position = val;
					__begin = temp.begin();
					while (__begin < temp.end() && position < end())
					{
						++position;
						*position = *__begin;
						__begin++; 
					}
				}
				return (iterator(&content[pos]));
			}
			void insert (iterator position, size_type n, const value_type& val)
			{
				int		pos;

				if (position > end())
				{
					pos = position - begin();
					resize((position - begin()) + n);
					position = iterator(&content[pos]);
					while (n--)
					{
						*position = val;
						position++;
					}
				}
				else
				{
					vector	temp(position, end());
					iterator	__begin;

					pos = position - begin();
					resize(capacity() + n);
					position = iterator(&content[pos]);
					while (n--)
					{
						*position = val;
						position++;
					}
					__begin = temp.begin();
					while (__begin < temp.end() && position < end())
					{
						*position = *__begin;
						++position;
						__begin++;
					}
				}
			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
						typename ft::enable_if<!std::is_integral<InputIterator>::value>::type * = nullptr)
			{
				int		size;
				int		pos;

				if (position > end())
				{
					pos = position - begin();
					size = (last - first);
					resize((position - begin()) + size);
					position = iterator(&content[pos]);
					while (first < last)
					{
						*position = *first;
						position++;
						first++;
					}
				}
				else
				{
					vector	temp(position, end());
					iterator	__begin;

					size = (last - first);
					pos = position - begin();
					resize(capacity() + size);
					position = iterator(&content[pos]);
					while (first < last)
					{
						*position = *first;
						position ++;
						first ++;
					}
					__begin = temp.begin();
					while (__begin < temp.end())
					{
						*position = *__begin;
						position ++;
						__begin++;
					}
				}
			}
			iterator erase (iterator position)
			{
				iterator start = position;
				iterator next(position + 1);

				if (position < end())
				{
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
				delete [] this->content;
				this->index = 0;
				this->content = this->allocator.allocate(this->_size);
			}
			allocator_type get_allocator() const
			{
				return std::allocator<T>(allocator);
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