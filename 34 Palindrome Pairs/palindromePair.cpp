#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

bool palindrome(string s)
{
    int len = s.length();
    if (len == 0)    return true;
    for (int i = len / 2; i >= 0; --i)
    {
        if (s[i] != s[len - i - 1])
            return false;
    }
    return true;
}

vector<vector<int>> palindromePairs(vector<string>& words) 
{
    vector<vector<int>> result;
    unordered_map<string, int> map;
    for (int i = 0; i < words.size(); ++i)  map[words[i]] = i;
    for (int i = 0; i < words.size(); ++i)
    {
        for (int j = 0; j <= words[i].length(); ++j)
        {
            string s = words[i];
            string str1 = s.substr(0, j);
            string str2 = s.substr(j);
            if (palindrome(str1))
            {
                reverse(str2.begin(), str2.end());
                if (map.find(str2) != map.end() && map[str2] != i)
                {
                    result.push_back({map[str2], i});
                }
            }
            if (palindrome(str2))
            {
                reverse(str1.begin(), str1.end());
                if (map.find(str1) != map.end() && map[str1] != i && str2.length() != 0)
                {
                    result.push_back({i, map[str1]});
                }
            }
        }
    }
    return result;
}

int main()
{
    vector<string> v = {"abcd", "dcba", "lls", "s", "sssll"};
    vector<vector<int>> result = palindromePairs(v);
    for (const vector<int> &rs : result)
    {
        cout << "[" << rs[0] << ", " << rs[1] << "], ";
    }
    cout << endl;
}