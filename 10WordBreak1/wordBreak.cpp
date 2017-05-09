#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool wordBreak(vector<string> &dict, string s)
{
    int length = s.length();
    vector<bool> vb(length, false);
    unordered_set<string> set(dict.begin(), dict.end());

    for (int i = 0; i < length; ++i)
    {
        if (set.find(s.substr(0, i + 1)) != set.end())
        {
            vb[i] = true;
            continue;
        }
        for (int j = 0; j < i; ++j)
        {
            int len = i - j;
            if (vb[j] == true && set.find(s.substr(j + 1, len)) != set.end())
            {
                vb[i] = true;
            }
        }
    }
    return vb.back();
}

int main()
{
    vector<string> v = {"leet", "code"};
    cout << (int) wordBreak(v, "leetcodf") << endl;
}