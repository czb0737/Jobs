#include <iostream>
#include <vector>

using namespace std;

int longestIncreaseSeq(vector<int> &nums)
{
    vector<int> result;
    for (int &n : nums)
    {
        int index = lower_bound(result.begin(), result.end(), n) - result.begin();
        if (index < result.size())
            result[index] = n;
        else    result.push_back(n);
    }
    return result.size();
}

int main(int argc, char **argv)
{
    vector<int> v = {4, 5, 3, 8, 2, 6, 7};
    cout << longestIncreaseSeq(v) << endl;
}