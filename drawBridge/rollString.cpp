#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void rollString(string &s, vector<int> &num);

void rollString(string &s, vector<int> &nums)
{
    vector<int> v(s.size() + 1, 0);
    priority_queue<int> pq;
    for (int &i : nums)
    {
        if (v[i] == 0)
            pq.push(i);
        ++v[i];
    }

    int count = 0, tmp = 0;
    while (!pq.empty())
    {
        tmp = pq.top();
        count = (count + v[tmp]) % 26;
        pq.pop();
        if (count == 26 || pq.empty())    continue;
        for (int i = pq.top(); i < tmp; ++i)
            s[i] = (s[i] - 'a' + count) % 26 + 'a';
    }
    for (int i = 0; i < tmp; ++i)
        s[i] = (s[i] - 'a' + count) % 26 + 'a';
}

int main(int argc, char **argv)
{
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    cout << s.size() << endl;
    vector<int> v = {5, 3 , 6, 1, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
    rollString(s, v);
    cout << s << endl;
}