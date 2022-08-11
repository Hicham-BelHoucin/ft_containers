/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 08:18:39 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/11 08:38:31 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cstdio>
# include <iostream>
# include <memory>
# include <stdexcept>
# include <string>
# include <array>
# include <iostream>
# include <fstream>
# include <string.h>
# define MAX 22

std::string tests[MAX];
std::string names[MAX];

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

void    SetCmd(void)
{
    std::string     line;
    int             i;

    i = 0;
    exec("find ../Tests/*/*/*.cpp ../Tests/*/*.cpp > OutPut");
    std::ifstream   in_file("OutPut");
    while (getline(in_file, line, '\n'))
    {
        tests[i] = line;
        i++;
    }
}

void    SetName(void)
{
    std::string     line;
    int             i;

    exec("cat OutPut | xargs basename > OutPut1");
    std::ifstream   in_file("OutPut1");
    i = 0;
    while (getline(in_file, line, '\n'))
    {
        names[i] = line;
        i++;
    }
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


int main(void)
{
    char        *cmd;
    const char  *diff;
    int         i;


    SetCmd();
    SetName();
    diff = "diff ft std";
    i = 0;
    while (i < MAX)
    {
        cmd = Generate_cmd(i, "ft");
        exec(cmd);
        delete [] cmd;
        fileEdit("./../Tests/Tests.hpp", "ft", "std");
        cmd = Generate_cmd(i, "std");
        exec(cmd);
        fileEdit("./../Tests/Tests.hpp", "std", "ft");
        if (exec(diff) == "")
            std::cout << Generate_name(i) << "\e[0;32m[OK]" << "\033[0m" << std::endl;
        else
            std::cout << Generate_name(i) << "\033[0;31m[KO]" << "\033[0m" << std::endl;
        delete [] cmd;
        i++;
    }
    exec("rm -f ft std a.out OutPut OutPut1");
}