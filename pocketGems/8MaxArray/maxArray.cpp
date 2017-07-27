#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct E
{
    int num;
    int index;
    E(int n, int i)
        : num(n), index(i) {}
};

vector<int> maxArray(vector<int>& nums, int k) 
{
    if (nums.empty())   return vector<int>();
    vector<int> result(nums.size());
    list<E> lt;
    
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        while (!lt.empty() && lt.front().index - i >= k)
            lt.pop_front();
        while (!lt.empty() && lt.back().num <= nums[i])
            lt.pop_back();
        lt.push_back(E(nums[i], i));
        result[i] = lt.front().num;
    }
    return result;
}

int main()
{
    vector<int> v = {1, 3, 5, 7, 3, 4, 2, 9};
    vector<int> result = maxArray(v, 3);
    for (const int &i : result)
        cout << i << " ";
    cout << endl;
}