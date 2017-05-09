#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>

using namespace std;

string getCharOrder(vector<string> &v)
{
    unordered_map<char, pair<int, unordered_set<char>>> mps;
    int num_edge = 0;

    for (const string &s : v)
    {
        for (int i = 0; i < s.length() - 1; ++i)
        {
            if (s[i] == s[i + 1])   continue;
            if (mps[s[i]].second.find(s[i + 1]) == mps[s[i]].second.end())    
            {
                ++num_edge;
                mps[s[i]].second.insert(s[i + 1]);
                ++mps[s[i + 1]].first;
            }
        }
    }

    for (const auto &p : mps)
        cout << p.first << " " << p.second.first << " " << p.second.second.size() << endl;

    queue<char> q;
    string result("");

    for (const pair<char, pair<int, unordered_set<char>>> &pps : mps)
        if (pps.second.first == 0)
            q.push(pps.first);

    while (!q.empty())
    {
        char c = q.front();
        q.pop();
        result.push_back(c);

        for (const char &ch : mps[c].second)
        {
            if (--mps[ch].first == 0)
                q.push(ch);
            --num_edge;
        }
    }
    cout << num_edge << endl;
    return result;
}

int main()
{
    vector<string> vs = {"abb", "cabd", "bg"};
    cout << getCharOrder(vs) << endl;
}