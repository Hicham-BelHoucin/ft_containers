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
# define VECTOR_HPP

# include <memory.h>

namespace ft
{
	template< class T, class Allocator = std::allocator<T> > 
	class vector
	{
		public:
			vector()
			{
				this->index = 0;
				this->_size = 0;
			};
			vector(const vector & copy){};
			vector & operator=(const vector & assign){};
			~vector(){};
			T operator[]( unsigned int pos )
			{
				return this->content[pos];
			}

			void			realloc()
			{
				// copies all elements into an new memory 
				T	* temp;
				temp = new T(index);
				for (int i = 0; i < index; i++)
					temp[i] = this->content[i];
				delete [] this->content;
				this->content = new T(index + (index / 4));
				for (int i = 0; i < index; i++)
					this->content[i] = temp[i];


			}
			bool    		empty()
			{
				// check if the vector is empty
				if (this->_size)
					return false;
				return true;
			}
			unsigned int 	size()
			{
				// returns size of the vetor
				return this->index;
			}
			unsigned long 	max_size()
			{
				// returns the maximum possible number of elements 
				return this->_size;
			}
			void			reserve()
			{
				// reserves storage
			}
			unsigned int	capacity()
			{
				// returns the number of elements that can be held in currently allocated storage
				return this->_size;
			}
			void	shrink_to_fit()
			{
				// reduces memory usage by freeing unused memory
			}
			void	clear()
			{
				// Erases all elements from the container
				delete [] this->content;
				this->index = 0;
				this->content = new T(this->_size);
			}
			void push_back( const T& value )
			{
				if (this->index == 0)
				{
					this->content = new T(1);
					this->content[index++] = value;
				}
				else
				{
					this->realloc();
					this->content[index++] = value;
				}
			}
		private:
			T         *         content;
			unsigned int        _size;
			unsigned int        index;
	};
}

#endif // VECTOR_HPP