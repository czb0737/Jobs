/*************************************************************************
	> File Name: mostFreChar.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 09/10/2017 Sun 15:07:01
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<char> mostFreChar(string &s);

vector<char> mostFreChar(string &s)
{
    int ptr = 0, cur_fre = 0;
    vector<char> result;
    while (ptr < s.size())
    {
        char ch = s[ptr];
        int tmp = ptr;
        while (ptr < s.size() && s[ptr] == ch)    ++ptr;
        if (ptr - tmp > cur_fre)
        {
            result.clear();
            result.push_back(ch);
            cur_fre = ptr - tmp;
        }
        else if (ptr - tmp == cur_fre)
            result.push_back(ch);
    }
    return result;
}

int main(int argc, char **argv)
{
    string s = string(argv[1]);
    auto v = mostFreChar(s);
    for (auto &ch : v)
        cout << ch << " ";
    cout << endl;
}