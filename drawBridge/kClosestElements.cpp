/*************************************************************************
	> File Name: kClosestElements.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 09/10/2017 Sun 15:38:58
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int target);

vector<int> findClosestElements(vector<int>& arr, int k, int target) 
{
    int ptr = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    ptr = ptr > k ? ptr - k : 0;
    while (ptr < arr.size() - k)
    {
        if (target - arr[ptr] <= arr[ptr + k] - target)
            break;
        ++ptr;
    }
    return vector<int>(arr.begin() + ptr, arr.begin() + ptr + k);
}

int main(int argc, char **argv)
{
    vector<int> v = {1, 2, 3, 4, 5};
    int k = 4, target = 4; //target = -1;
    auto vv = findClosestElements(v, k, target);
    for (auto &i : vv)
        cout << i << " ";
    cout << endl;
}