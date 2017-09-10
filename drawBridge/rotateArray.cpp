/*************************************************************************
	> File Name: maxRowSum.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 09/10/2017 Sun 13:30:42
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotateArray(vector<int> &v, int k);

void rotateArray(vector<int> &v, int k)
{
    if (v.empty())  return;
    int n = v.size();
    auto it = v.begin();
    k %= n;

    reverse(it, it + n - k);
    reverse(it + n - k, v.end());
    reverse(it, v.end());
}

int main(int argc, char **argv)
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    int k = stoi(string(argv[1]));
    rotateArray(v, k);
    for (auto &i : v)
        cout << i << " ";
    cout << endl;
}