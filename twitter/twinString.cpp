#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool twinString(string &s1, string &s2);

bool twinString(string &s1, string &s2)
{
    if (s1.size() != s2.size()) return false;
    unordered_map<char, int> umap[2];

    for (int i = 0; i < s1.size(); ++i)
    {
        ++umap[i % 2][s1[i]];
        --umap[i % 2][s2[i]];
    }
    if (umap[0].size() != umap[1].size())   return false;
    for (auto &p : umap[0])
        if (p.second != 0)
            return false;
    for (auto &p : umap[1])
        if (p.second != 0)
            return false;
    return true;
}

int main(int argc, char **argv)
{
    string s1(argv[1]), s2(argv[2]);
    cout << twinString(s1, s2) << endl;
}