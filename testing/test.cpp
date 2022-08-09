/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 08:18:39 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/09 16:06:14 by hbel-hou         ###   ########.fr       */
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
#include <string.h>

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
        while (getline(in_file, line))
        {
            start = line.find(search);
            if(start != std::string::npos)
            {
                line.replace(start, search.length(), replace);
                search = "helloworld";
            }
            text += line;
            text += "\n";
        }
        std::ofstream   out_file(filename);
        out_file << text;
        in_file.close();
        out_file.close();
    }
    else
        std::cout << "error" << std::endl;
}

char    *Generate_cmd(int index, std::string name_space)
{
    std::string     cmd;
    std::string     tests[22];
    char            *str;

    tests[0] = "../Tests/iterator_tests/iterator_tests.cpp";
    tests[1] = "../Tests/iterator_tests/rev_iterator_tests.cpp";
    tests[2] = "../Tests/vector_tests/capacity/capacity.cpp";
    tests[3] = "../Tests/vector_tests/capacity/empty.cpp";
    tests[4] = "../Tests/vector_tests/capacity/max_size.cpp";
    tests[5] = "../Tests/vector_tests/capacity/reserve.cpp";
    tests[6] = "../Tests/vector_tests/capacity/resize.cpp";
    tests[7] = "../Tests/vector_tests/capacity/size.cpp";
    tests[8] = "../Tests/vector_tests/constructor/constructor.cpp";
    tests[9] = "../Tests/vector_tests/elementAccess/main.cpp";
    tests[10] = "../Tests/vector_tests/modifiers/assign.cpp";
    tests[11] = "../Tests/vector_tests/modifiers/push_back.cpp";
    tests[12] = "../Tests/vector_tests/modifiers/pop_back.cpp";
    tests[13] = "../Tests/vector_tests/modifiers/insert.cpp";
    tests[14] = "../Tests/vector_tests/modifiers/erase.cpp";
    tests[15] = "../Tests/vector_tests/modifiers/swap.cpp";
    tests[16] = "../Tests/vector_tests/modifiers/clear.cpp";
    tests[17] = "../Tests/vector_tests/overloads/main.cpp";
    tests[18] = "../Tests/vector_tests/overloads/swap.cpp";
    tests[19] = "../Tests/vector_tests/allocator/get_allocator.cpp";
    tests[20] = "../Tests/vector_tests/equal/lexicographical_compare.cpp";
    tests[21] = "../Tests/vector_tests/equal/equal.cpp";
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
    std::string     tests[22];

    tests[0] = "iterator_tests : ";
    tests[1] = "rev_iterator_tests : ";
    tests[2] = "capacity/capacity : ";
    tests[3] = "capacity/empty : ";
    tests[4] = "capacity/max_size : ";
    tests[5] = "capacity/reserve : ";
    tests[6] = "capacity/resize : ";
    tests[7] = "capacity/size : ";
    tests[8] = "constructor : ";
    tests[9] = "elementAccess/main : ";
    tests[10] = "modifiers/assign : ";
    tests[11] = "modifiers/push_back : ";
    tests[12] = "modifiers/pop_back : ";
    tests[13] = "modifiers/insert : ";
    tests[14] = "modifiers/erase : ";
    tests[15] = "modifiers/swap : ";
    tests[16] = "modifiers/clear : ";
    tests[17] = "overloads/operators : ";
    tests[18] = "overloads/swap : ";
    tests[19] = "allocator/get_allocator : ";
    tests[20] = "lexicographical_compare : ";
    tests[21] = "equal : ";
    return tests[index];
}


int main(void)
{
    char        *cmd;
    const char  *diff;
    int         i;

    diff = "diff ft std";
    i = 0;
    while (i < 22)
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
    exec("rm -f ft std a.out");
}