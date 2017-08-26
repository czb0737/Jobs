/*************************************************************************
	> File Name: minToNum.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 08/26/2017 Sat 12:43:20
 ************************************************************************/

#include <iostream>
#include <vector>
// #include <iomanip>

using namespace std;

/**
 * Minium number of moves to reach n from 0 using only "+1" and "*2"
 */
int minToNum(int n);

int minToNum(int n)
{
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        if ((i & 1) == 0)
            dp[i] = min(dp[i], dp[i >> 1] + 1);
        // cout << setw(2) << i << ": " << setw(3) << dp[i] << endl;
    }
    return dp.back();
}

int main(int argc, char **argv)
{
    cout << minToNum(stoi(argv[1])) << endl;
}