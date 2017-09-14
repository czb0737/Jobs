/*************************************************************************
	> File Name: longestSubstr.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 09/13/2017 Wed 16:52:28
 ************************************************************************/

/**
 * input 一个包含0-9， a-z, A-Z的 string, 找最长的substring，要求：i. 至少包含一个大写字母，ii 不能有数字。 双指针解决
 */

#include <iostream>
#include <string>

using namespace std;

int longestSubstr(string &s);

int longestSubstr(string &s)
{
    int num_idx = -1, result = 0;
    bool upper = false;

    for (int i = 0; i < s.size(); ++i)
    {
        char ch = s[i];
        if (ch >= '0' && ch <= '9')
        {
            if (upper)
                result = max(result, i - num_idx);
            num_idx = i;
            upper = false;
        }
        else if (ch >= 'A' && ch <= 'Z')
            upper = true;
    }
    return max(result, (int)s.size() - num_idx - 1);
}

int main(int argc, char **argv)
{
    string s = string(argv[1]);
    cout << longestSubstr(s) << endl;
}