/*************************************************************************
	> File Name: maxRowSum.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 09/10/2017 Sun 11:53:41
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int maxRowSum(vector<vector<int>> &board);
int lowerBound(vector<int> &v, int start, int end, int target);

int maxRowSum(vector<vector<int>> &board)
{
    if (board.empty() || board.front().empty()) return 0;
    int index = lowerBound(board.front(), 0, board.front().size(), 1);
    for (int i = 1; i < board.size(); ++i)
        while (index >= 0 && board[i][index] == 1)
            --index;
    return board.front().size() - index - 1;
}

int lowerBound(vector<int> &v, int start, int end, int target)
{
    int low = start, high = end;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] >= target)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main(int argc, char **argv)
{
    vector<vector<int>> vv = {
        {0, 0, 0, 0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 1, 1, 1, 1},
        {0, 0, 0, 0, 1, 1, 1, 1, 1},
    };
    cout << maxRowSum(vv) << endl;
}