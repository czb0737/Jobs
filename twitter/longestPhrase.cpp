#include <iostream>
#include <vector>

using namespace std;

int longestPhrase(vector<int> &nums, int k);

int longestPhrase(vector<int> &nums, int k)
{
    int ptr = 0, sum = 0, result = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        if (sum <= k)   result = max(result, i - ptr + 1);
        while (sum > k)    sum -= nums[ptr++];
    }
    return result;
}

int main(int argc, char **argv)
{
    vector<int> v = {4, 1, 2, 3, 4, 1, 1, 1, 4, 4};
    cout << longestPhrase(v, 10) << endl;
}