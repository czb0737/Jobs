/*************************************************************************
	> File Name: combinationSum.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 09/08/2017 Fri 21:02:51
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void backTracking(vector<vector<int>> &result, vector<int> &v, vector<int> &cand, int sum, int &target, int start);

void backTracking(vector<vector<int>> &result, vector<int> &v, vector<int> &cand, int sum, int &target, int start)
{
    if (sum == target)
    {
        result.push_back(v);
        return;
    }

    for (int i = start; i < cand.size(); ++i)
    {
        if (sum + cand[i] > target) continue;
        v.push_back(cand[i]);
        backTracking(result, v, cand, sum + cand[i], target, i);
        v.pop_back();
    }
}

int main(int argc, char **argv)
{
    vector<int> cand = {2, 3, 5, 6, 7};
    int target = 7;
    vector<vector<int>> result;
    vector<int> v;
    backTracking(result, v, cand, 0, target, 0);
    for (auto &vv : result)
    {
        for (auto &i : vv)
            cout << i << " ";
        cout << endl;
    }
}