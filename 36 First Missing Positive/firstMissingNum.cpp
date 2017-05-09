#include <iostream>
#include <vector>

using namespace std;

int findMissingNum(vector<int> &v)
{
    int len = v.size();
    for (int i = 0; i < len; ++i)
    {
        int index = v[i] - 1;
        while (index >= 0 && index < len && index + 1 != v[index])
        {
            swap(v[i], v[index]);
            index = v[i] - 1;
        }
    }

    for (int i = 0; i < len; ++i)
    {
        if (v[i] != i + 1)
            return i + 1; 
    }
    return len + 1;
}

int main()
{
    vector<int> v = {-1, 2, 1, 4, 3, 6, -7, 0, -2};
    for (const int &n : v)
        cout << n << " ";
    cout << endl;
    cout << findMissingNum(v) << endl;
}