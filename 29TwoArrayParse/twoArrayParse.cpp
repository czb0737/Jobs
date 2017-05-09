#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoArrayParse(vector<int> &nums, vector<int> &n)
{
    unordered_map<int, int> map;
    for (const int &n : nums)
        ++map[n];
    unordered_map<int, int> map2;
    for (const pair<int, int> &p : map)
        map2[p.second] = p.first;
    vector<int> result(n.size());
    for (int i = 0; i < n.size(); ++i)
    {
        if (map2.find(n[i]) == map2.end())
            result[i] = -1;
        else
            result[i] = map2[n[i]];
    }
    return result;
}

int main()
{
    vector<int> nums = {5,5,5,8,8,4,4,1,1,1,1,2,2,2,2,2};
    vector<int> v = {3,5,1,2,4};
    vector<int> result = twoArrayParse(nums, v);
    for (const int &n : result)
    {
        cout << n << " ";
    }
    cout << endl;
}