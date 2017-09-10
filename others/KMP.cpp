/*************************************************************************
	> File Name: KMP.cpp
	> Author: czb
	> Mail: czb0737@gmail.com
	> Created Time: 05/01/2017 Mon 15:25:30
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class KMP
{
private:
    vector<int> next;
    string match;
public:
    KMP(string s) : match(s), next(vector<int>(s.length() + 1)) {}

    void calNext()
    {
        int j = 0;
        next[0] = next[1] = 0;

        for (int i = 1; i < next.size(); ++i)
        {
            while (j > 0 && match[i] != match[next[j]]) j = next[j];
            if (match[i] == match[j])   ++j;
            next[i + 1] = j;
        }
    }

    int withIn(string s)
    {
        if (match.length() == 0)    return 0;
        int index = 0;

        for(int i = 0; i < s.length(); ++i)
        {
            if (s[i] != match[index])
            {
                index = next[index];
            }
            else    ++index;
            if (index == match.length()) return i - index + 1;
        }
        return -1;
    }
};

int main()
{
    KMP kmp("abc");
    cout << kmp.withIn("ab") << endl;
}