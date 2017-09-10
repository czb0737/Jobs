#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int upperBound(vector<int> &v, int num)
{
    int low = 0, high = v.size();

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] <= num)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main()
{
    vector<int> v = {1,2,3,5,5,6};
    int r1 = upperBound(v, 7);
    int r2 = (int) (upper_bound(v.begin(), v.end(), 7) - v.begin());
    cout << r1 << " " << r2 << endl;
}