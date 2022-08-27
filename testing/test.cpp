/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 08:18:39 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/27 13:12:18 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cstdio>
# include <iostream>
# include <memory>
# include <stdexcept>
# include <string>
# include <array>
# include <vector>
# include <iostream>
# include <fstream>
# include <string.h>
# include <sys/time.h>

# define RESET   "\033[0m"
# define BLACK   "\033[30m"      /* Black */
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */
# define MAGENTA "\033[35m"      /* Magenta */
# define CYAN    "\033[36m"      /* Cyan */
# define WHITE   "\033[37m"      /* White */
# define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
# define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
# define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
# define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
# define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
# define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
# define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
# define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

std::vector<std::string> tests;
std::vector<std::string> names;

void fileEdit(std::string filename, std::string search, std::string replace)
{
    std::ifstream   in_file(filename);
    std::string     text;
    std::string     line;
    size_t          start;

    start = 0;
    if (in_file.is_open())
    {
        while (getline(in_file, line, '\0'))
        {
            start = line.find(search);
            if(start != std::string::npos)
            {
                line.replace(start, search.length(), replace);
                search = "helloworld";
            }
            text += line;
        }
        std::ofstream   out_file(filename);
        out_file << text;
        in_file.close();
        out_file.close();
    }
    else
        std::cout << "error" << std::endl;
}

std::string readFile(std::string name)
{
    std::ifstream   in_file(name);
    std::string     text;
    std::string     line;

    if (in_file.is_open())
    {
        while (getline(in_file, line, '\0'))
            text += line;
    }
    else
        std::cout << "error" << std::endl;
    return text;
}

void    SetCmd(void)
{
    std::string     line;
    // system("find ../Tests/*/*/*.cpp ../Tests/*/*.cpp > OutPut");
    system("find ../Tests/map_tests/reverse_iter.cpp > OutPut");
    std::ifstream   in_file("OutPut");
    while (getline(in_file, line, '\n'))
        tests.push_back(line);
    in_file.close();
}

void    SetName(void)
{
    std::string     line;

    system("cat OutPut | xargs basename > OutPut1");
    std::ifstream   in_file("OutPut1");
    while (getline(in_file, line, '\n'))
        names.push_back(line);
    in_file.close();
}

char    *Generate_cmd(int index, std::string name_space)
{
    std::string     cmd;
    char            *str;

    cmd = "c++ ";
    cmd += tests[index];
    cmd += " && ./a.out";
    cmd += " > ";
    cmd += name_space;
    str = new char[cmd.size() + 1];
    std::copy(cmd.begin(), cmd.end(), str);
    str[cmd.size()] = '\0';
    return str;
}

std::string Generate_name(int index)
{
    int         i;

    i = names[index].find(".cpp");
    return  names[index].replace(i, 4, " : ");
}

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
    char        *cmd;
    long        std_time;
    long        ft_time;
    int         i;
    std::string output;


    SetCmd();
    SetName();
    i = 0;
    while (i < tests.size())
    {
        cmd = Generate_cmd(i, "ft");
        ft_time = get_time();
        system(cmd);
        ft_time = spent_time(ft_time);
        delete [] cmd;
        fileEdit("./../Tests/Namespace.hpp", "ft", "std");
        cmd = Generate_cmd(i, "std");
        std_time = get_time();
        system(cmd);
        std_time = spent_time(std_time);
        fileEdit("./../Tests/Namespace.hpp", "std", "ft");
        system("diff ft std > diff");
        output = readFile("./diff");
        if (output == "")
            std::cout << Generate_name(i) << "\e[0;32m[OK]" << "\033[0m" << std::endl;
        else
            std::cout << Generate_name(i) << "\033[0;31m[KO]" << "\033[0m" << std::endl;
        std::cout << "\033[1m\033[34mtiming : " << "\033[0m";
        if (ft_time < std_time)
            std::cout << "\e[0;32m[OK] " << "\033[0m" << "ft_timing : " << ft_time << " std_timing : " << std_time << std::endl;
        else
            std::cout << "\033[0;31m[KO] " << "\033[0m" << "ft_timing : " << ft_time << " std_timing : " << std_time << std::endl;
        delete [] cmd;
        system("rm -f ft std a.out OutPut OutPut1 diff");
        i++;
    }
    system("rm -f a.out");
}