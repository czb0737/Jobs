#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int>& nums) {
    if (nums.empty())   return 0;
    int result = nums[0];
    
    for (int i = 1, l_max = nums[0], l_min = nums[0]; i < nums.size(); ++i)
    {
        if (nums[i] < 0)
            swap(l_max, l_min);
            
        l_max = max(nums[i], nums[i] * l_max);
        l_min = min(nums[i], nums[i] * l_min);
        
        result = max(result, l_max);
    }
    return result;
}

int main()
{
    vector<int> v = { 2, 3, -2, 4 };
    cout << maxProduct(v) << endl;
}