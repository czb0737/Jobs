/*************************************************************************
	> File Name: countString.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 09/06/2017 Sat 17:35:21
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int countString(string &s)
{
    int left = 0, right = 0;
    int result = 0;
    int index1 = -1;
    while ((int)string::npos != (index1 = s.find('/', index1 + 1)))
    {
        int index2 = s.find('\\', index1);
        cout << index1 << " " << index2 << endl;
        if (index2 == (int)string::npos)    break;
        int tmp1 = index1, tmp2 = index2;
        for (int i = tmp1 + 1; i < tmp2; ++i)
            if (s[i] < 'a' || s[i] > 'z')
                continue;
        while (tmp1-- > 0)
        {
            if (s[tmp1] >= 'a' && s[tmp1] <= 'z')   ++left;
            if (s[tmp1] == '/' || s[tmp1] == '\\')  break;
        }
        while (tmp2++ < s.size() - 1)
        {
            if (isdigit(s[tmp2]) || (s[tmp2] >= 'a' && s[tmp2] <= 'z')) ++right;
            else    break;
        }
        result += left * right;
        cout << left << " " << right << " " << result << endl;
        left = right = 0;
    }
    return result;
}

int main(int argc, char **argv)
{
    string s = string(argv[1]);
    cout << countString(s) << endl;
}