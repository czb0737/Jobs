/*************************************************************************
	> File Name: strt.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 08/29/2017 Tue 10:54:20
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <unordered_map>

#include "Dictionary.h"

using namespace std;

int main(int argc, char **argv)
{
    Dictionary dict0;
    dict0.buildDict(string(argv[2]));
    dict0.displayDict();
    ifstream in;
    in.open(string(argv[1]));
    string s;
    while (getline(in, s, '\n'))
    {
        cout << dict0.replace(s) << endl;
    }
    in.close();
}