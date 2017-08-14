#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int rangeAdd(vector<pair<int, int>> &ranges);

int main()
{
    vector<pair<int, int>> ranges = {{2, 3}, {5, 9}, {7, 4}};
    cout << rangeAdd(ranges) << endl;
}

int rangeAdd(vector<pair<int, int>> &ranges)
{
    if (ranges.empty()) return 0;
    int row = INT_MAX, col = INT_MAX;
    for (auto &p : ranges)
    {
        row = min(row, p.first);
        col = min(col, p.second);
    }
    return row * col;
}