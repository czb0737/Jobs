#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

struct T
{
    char ch;
    int idx;
    T(char c, int i) : ch(c), idx(i) {}
};

int characterReplacement(string s, int k) 
{
    queue<T> qt;
    unordered_set<char> sc;
    vector<char> vc;
    int count = 0;
    int result = 0;
    
    for (char c : s)
        if (sc.find(c) == sc.end())
            sc.insert(c);
    
    for (char c : sc)
    {
        char tmp = c;
        count = 0;
        for (int j = 0; j < s.length(); ++j)
        {
            qt.push(T(s[j], j));
            if (s[j] != tmp)    ++count;
            while (count > k)
            {
                if (qt.front().ch != tmp)
                    --count;
                qt.pop();
            }
            if (qt.size() > result) result = qt.size();
        }
        qt = queue<T>();
    }
    return result;
}

int main()
{
    string s = "AABABBA";
    cout << characterReplacement(s, 1) << endl;
}