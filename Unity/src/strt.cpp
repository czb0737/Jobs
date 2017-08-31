/*************************************************************************
	> File Name: strt.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 08/29/2017 Tue 10:54:20
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <unordered_map>

#include "../include/Dictionary.h"

using namespace std;

int main(int argc, char **argv)
{
    Dictionary dict0;
    // Build dictionary with params.txt
    dict0.buildDict(string(argv[2]));
    ifstream in;
    in.open(string(argv[1]));
    string s;
    // Read from input.txt replace strings line by line
    while (getline(in, s, '\n'))
    {
        cout << dict0.replace(s) << endl;
    }
    // Close the fd for input.txt
    in.close();

    return 0;
}