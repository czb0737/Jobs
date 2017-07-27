#include <vector>
#include <iostream>

using namespace std;

int lowerBound(vector<int> &v, int num)
{
    int low = 0, high = v.size();

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] < num)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main()
{
    vector<int> v = {1,2,3,5,5,6};
    int r1 = lowerBound(v, 3);
    int r2 = (int) (lower_bound(v.begin(), v.end(), 3) - v.begin());
    cout << r1 << " " << r2 << endl;
}