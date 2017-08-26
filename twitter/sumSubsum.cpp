#include <iostream>
#include <vector>

using namespace std;

int sumSubsum(vector<int> &nums);

int sumSubsum(vector<int> &nums)
{
    int sum = 0, size = nums.size();

    for (int i = 0; i < size; ++i)
    {
        sum += nums[i] * (size - i) * (i + 1);
    }
    return sum;
}

int main(int argc, char **argv)
{
    vector<int> v = {1, 2, 3};
    cout << sumSubsum(v) << endl;
}