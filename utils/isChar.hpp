/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isChar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:27:15 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/03 11:36:01 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	IS_CHAR_HPP
#define	IS_CHAR_HPP

namespace ft
{
	template <typename _Tp>
	struct isChar
	{
		static const bool value = false;
	};

	template <>
	struct isChar<char>
	{
		static const bool value = true;
	};

	template <>
	struct isChar<unsigned char>
	{
		static const bool value = true;
	};

	template <>
	struct isChar<signed char>
	{
		static const bool value = true;
	};


}

#endif	//IS_CHAR_HPP