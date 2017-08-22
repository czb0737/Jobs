#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<string> topoSort(vector<pair<string, string>> &deps)
{
    unordered_map<string, pair<int, vector<string>>> umap;

    for (auto &p : deps)
    {
        umap[p.second].second.push_back(p.first);
        ++umap[p.first].first;
    }

    queue<string> q;
    for (auto &p : umap)
        if (p.second.first == 0)
            q.push(p.first);

    vector<string> result;
    while (!q.empty())
    {
        string s = q.front();
        q.pop();
        result.push_back(s);

        for (auto &ss : umap[s].second)
        {
            auto &p = umap[ss];
            if (--p.first == 0)
                q.push(ss);
        }
    }

    return result;
}

int main(int argc, char **argv)
{
    // vector<pair<string, string>> vp = {{"master", "ubuntu"}, {"numpy", "master"}, {"tensorflow", "numpy"}};
    // vector<pair<string, string>> vp = {{"python", "numpy"}, {"numpy", "python"}, {"tensorflow", "ubuntu"}};
    vector<pair<string, string>> vp = {{"b", "c"}, {"c", "d"}, {"a", "b"}, {"d", "e"}, {"e","c"}, {"f", "g"}};
    vector<string> vs = topoSort(vp);
    for (auto &s : vs)
        cout << s << endl;
}