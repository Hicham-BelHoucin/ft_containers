/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:53:34 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/09/10 14:28:36 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./containers/map.hpp"
#include <sys/time.h>
#define NS ft

long int	get_time(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

int	spent_time(long int time)
{
	long int	c_time;

	c_time = get_time();
	c_time -= time;
	return (c_time);
}

int main(void)
{
    ft::map<int, int>               mymap;
    ft::map<int, int>::iterator     begin, end;
    long                            time;
    
    time = get_time();
    std::cout << spent_time(time) << std::endl;
    for (int i = 0; i < 250; i++)
        mymap[i] = i;
    begin = mymap.begin();
    end = mymap.end();
    for (;begin != end; begin++)
        std::cout << begin->first << std::endl;
    std::cout << spent_time(time) << std::endl;
    return 0;
}