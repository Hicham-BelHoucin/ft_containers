/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 08:18:39 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/10/03 13:39:46 by hbel-hou         ###   ########.fr       */
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

void    SetCmd(const char *path)
{
    std::string     line;
    system(path);
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

char    *Generate_cmd(int index)
{
    std::string     cmd;
    char            *str;

    cmd = "c++ ";
    cmd += tests[index];
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

int compileAndExecute(const char *compile, const char *execute)
{
    int time;

    system(compile);
    time = get_time();
    system(execute);
    time = spent_time(time);
    delete [] compile;
    return time;
}

void    compareOutputAndTiming(int ft_time, int std_time, int i)
{
    std::string output;

    system("diff ft std > diff");
    output = readFile("./diff");
    std::cout << "          "<< BOLDWHITE << Generate_name(i) << std::endl;
    std::cout << "              " << YELLOW << "Output : " << RESET;
    if (output == "")
        std::cout << BOLDGREEN << "[OK]" << RESET << std::endl;
    else
    {
        std::cout << BOLDRED << "[KO]" << RESET << std::endl;
        // exit(1);
    }
    std::cout << "              \033[1m\033[34mTiming : " << RESET;
    if (ft_time < (std_time * 20))
        std::cout << BOLDGREEN << "[OK] " << RESET << "You Program's timing : " << ft_time << " | expected timing : " << std_time * 20 << std::endl;
    else
        std::cout << BOLDRED << "[KO] " << RESET << "You Program's timing : " << ft_time << " | expected timing : " << std_time * 20 << std::endl;
}

void TestContainer()
{
    long        std_time;
    long        ft_time;
    int         i;

    i = 0;
    while (i < tests.size())
    {
        ft_time = compileAndExecute(Generate_cmd(i), "./a.out > ft");
        fileEdit("./Namespace.hpp", "ft", "std");
        std_time = compileAndExecute(Generate_cmd(i), "./a.out > std");
        fileEdit("./Namespace.hpp", "std", "ft");
        compareOutputAndTiming(ft_time, std_time, i);
        system("rm -rf ft std a.out OutPut OutPut1 *.dSYM");
        i++;
    }
    names.clear();
    tests.clear();
}

int main(int ac, char **av)
{
    const char      *path[4];
    std::string     Container[4];
    int             i;
	int				end;

	if (ac == 2)
	{
		if (!strcmp(av[1], "map"))
		{
			i = 0;
			end = 1;
		}
		else if (!strcmp(av[1], "vector"))
		{
			i = 1;
			end = 2;
		}
		else if (!strcmp(av[1], "stack"))
		{
			i = 2;
			end = 3;
		}
		else if (!strcmp(av[1], "set"))
		{
			i = 3;
			end = 4;
		}
		else
		{
			i = 0;
			end = 4;
		}
	}
	else
	{
		i = 0;
		end = 4;
	}

    path[0] = "find ../containers/map/*.cpp > OutPut";
    path[1] = "find ../containers/vector/*.cpp > OutPut";
    path[2] = "find ../containers/stack/*.cpp > OutPut";
    path[3] = "find ../containers/set/*.cpp > OutPut";
    Container[0] = "Map : ";
    Container[1] = "Vactor : ";
    Container[2] = "Stack : ";
    Container[3] = "set : ";
    while (i < end)
    {
        SetCmd(path[i]);
        SetName();
        std::cout << BOLDMAGENTA << Container[i] << std::endl;
        TestContainer();
        i++;
    }
    system("rm -rf ft std a.out OutPut OutPut1 *.dSYM");
}