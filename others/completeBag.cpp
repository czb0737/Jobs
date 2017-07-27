#include <iostream>
#include <vector>

using namespace std;

int completeBag(vector<int> &values, vector<int> &volumes, int capacity)
{
    int num = values.size();
    vector<int> dp(capacity + 1, 0);
    
    for (int i = 0; i < num; ++i)
        for (int j = volumes[i]; j <= capacity; ++j)
            dp[j] = max(dp[j], dp[j - volumes[i]] + values[i]);
    return dp.back();
}

int change(vector<int> &changes, int total)
{
    vector<int> dp;
    for (int i = 0; i <= total; ++i)    dp.push_back(i);

    for (int i = 0; i < changes.size(); ++i)
        for (int j = changes[i]; j <= total; ++j)
            dp[j] = min(dp[j], dp[j - changes[i]] + 1);
    return dp.back();
}

int main()
{
    vector<int> values = {6, 5, 10, 2, 16, 8};
    vector<int> volumes = {3, 2, 5, 1, 6, 4};
    int capacity = 10;
    cout << completeBag(values, volumes, capacity) << endl; 

    vector<int> changes = {2, 5, 6, 11};
    int total = 10;
    cout << change(changes, total) << endl;
}