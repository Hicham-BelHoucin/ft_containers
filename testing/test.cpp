/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 08:18:39 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/09 08:32:26 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <iostream>
#include <fstream>

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::string	ft_replace(std::string haystack, std::string needle, std::string new_word)
{
	unsigned long i;

	i = haystack.find(needle);
	while (i < haystack.length())
	{
		haystack.erase(i, needle.length());
		haystack.insert(i, new_word);
		i = haystack.find(needle);
	}
	return (haystack);
}

std::string read_file(std::string filename)
{
	int i;

	i = -1;
	std::fstream file;
	file.open(filename, std::ios::in);
	if (file.is_open())
	{
		std::string mystr;
		std::string ch; 
		while (!file.eof())
		{
			ch = file.get();
			mystr += ch;
		}
		file.close();
		while (mystr[++i + 1]);
		mystr[i] = '\0';
		return (mystr);
	}
	else
	{
		std::cout << "Unable to open file" << std::endl;
	}
	return ("");
}

void	write_to_file(std::string mystr, std::string filename)
{
	if (mystr.length() == 1)
		return ;
	filename += ".replace";
	std::ofstream myfile (filename);
	if (myfile.is_open())
	{
		myfile << mystr;
		myfile.close();
	}
	return ;
}

void    ft_replace_file()
{
    std::string av[4];
	std::string mystr;

    av[0] = "./Tests/Tests.hpp";
    av[1] = "ft";
    av[2] = "std";
	if (read_file(av[0]) != "")
	{
		mystr = read_file(av[0]);
		mystr = ft_replace(mystr, av[1], av[2]);
		write_to_file(mystr, av[0]);
	}
}


int main(void)
{

    std::string output;


    ft_replace_file();
    std::cout << output;
}