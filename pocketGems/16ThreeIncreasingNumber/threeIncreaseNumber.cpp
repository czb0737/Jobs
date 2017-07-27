#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool threeIncreaseNumber(vector<int> &v)
{
    int first = INT_MAX, second = INT_MAX;
    for (const int &n : v)
    {
        if (n <= first)
            first = n;
        else if (n <= second)
            second = n;
        else
            return true;
    }
    return false;
}

int main()
{
    vector<int> v = {7,8,6,4,5,3,6};
    cout << threeIncreaseNumber(v) << endl;
}