#include <iostream>
#include <vector>

using namespace std;

vector<int> findDup(vector<int> &v)
{
    vector<int> dup;
    for (int i = 0; i < v.size(); ++i)
    {
        int num = abs(v[i]);
        if (v[num] < 0) dup.push_back(num);
        else    v[num] = -v[num];
    }
    return dup;
}

int main()
{
    vector<int> v = {1,2,5,6,3,4,9,7,8,6,2};
    vector<int> result = findDup(v);
    for (const int &r : result)
    {
        cout << r << " ";
    }
    cout << endl;
}