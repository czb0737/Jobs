/*************************************************************************
	> File Name: elevator.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 09/13/2017 Wed 17:21:18
 ************************************************************************/

/**
 * 电梯问题，input一个数组A[] 表示重量，B[] 表示每个人要去的楼层，人数限制X，
 * 重量限制Y，问运完这些人总共停几次，因为后面的人不能插队，所以很简单直接遍历就行了
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int elevator(vector<int> &weight, vector<int> &floor, int num_limit, int weight_limit);

int elevator(vector<int> &weight, vector<int> &floor, int num_limit, int weight_limit)
{
    int result = 1;
    unordered_set<int> uset;
    int nl = num_limit, wl = weight_limit;

    for (int i = 0; i < weight.size(); ++i)
    {
        if (--nl < 0 || wl - weight[i] < 0)
        {
            result += uset.size() + 1;
            uset.clear();
            wl = weight_limit - weight[i];
            nl = num_limit - 1;
        }
        else    wl -= weight[i];
        uset.insert(floor[i]);
    }
    return result + uset.size();
}

int main(int argc, char **argv)
{
    vector<int> weight = {3, 3, 3, 3, 3, 3, 3};
    vector<int> floor = {1, 1, 2, 2, 3, 4, 4};
    cout << elevator(weight, floor, 3, 10) << endl;
}