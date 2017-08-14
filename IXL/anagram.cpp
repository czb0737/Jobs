#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> countAnag(vector<string> &vs1, vector<string> &vs2);
int countDiff(string &s1, string &s2);

int main()
{
    vector<string> vs1 = {"abcdefa", "abcd", "aabdftt"};
    vector<string> vs2 = {"fedcbab", "abc", "badfayr"};
    vector<int> v = countAnag(vs1, vs2);
    for (int &i : v)
        cout << i << " ";
    cout << endl;
}

vector<int> countAnag(vector<string> &vs1, vector<string> &vs2)
{
    vector<int> result;
    for (int i = 0; i < vs1.size(); ++i)
        result.push_back(countDiff(vs1[i], vs2[i]));
    return result;
}

int countDiff(string &s1, string &s2)
{
    if (s1.size() != s2.size()) return -1;
    unordered_map<char, int> umap;
    for (int i = 0; i < s1.size(); ++i)
    {
        ++umap[s1[i]];
        --umap[s2[i]];
    }
    int count = 0;
    for (auto &p : umap)
        count += abs(p.second);
        
    return count / 2;
}