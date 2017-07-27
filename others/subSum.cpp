#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long subSum(vector<int> &v, unordered_map<int, int> &map)
{
    long result = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        int tmp = 0;
        for (int j = 0; j < v.size() - i; ++j)
        {
            tmp += v[i + j];
            result += tmp;
        }
    }
    return result;
}

long subSum2(vector<int> &v)
{
    long result = 0;
    int size = v.size();
    for (int i = 0; i < size; ++i)
    {
        result += (size - i) * (i + 1) * v[i];
    }
    return result;
}

int main()
{
    vector<int> v;
    for (int i = 1; i <= 50; ++i)
    {
        v.push_back(i);
    }
    unordered_map<int, int> map;
    long result = subSum(v, map);
    long result2 = subSum2(v);
    cout << result << " " << result2 << endl;
    // for (const pair<int, int> &p : map)
    //     cout << p.first << " " << p.second << endl;
    // cout << endl;
}