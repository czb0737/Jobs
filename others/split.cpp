/*************************************************************************
	> File Name: split.cpp
	> Author: czb
	> Mail: czb0737@gmail.com
	> Created Time: 02/27/2017 Mon 20:13:23
 ************************************************************************/

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string s, char sep)
{
    stringstream ss(s);
    vector<string> result;
    while (!ss.eof())
    {
        string token;
        getline(ss, token, sep);
        result.push_back(token);
    }
    return result;
}

int main(int argc, char *argv[])
{
    string s = argv[1];
    vector<string> v = split(s, ',');

    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << endl;
    }
}
