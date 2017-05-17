#include <iostream>
#include <vector>

using namespace std;

void sortColor(vector<int> &v)
{
    int ptr1 = 0, ptr2 = v.size() - 1;
    int cur = 0;

    while (cur <= ptr2)
    {
        if (v[cur] == 0 && cur != ptr1)
            swap(v[cur], v[ptr1++]);
        else if (v[cur] == 2 && cur != ptr2)
            swap(v[cur], v[ptr2--]);
        else
            ++cur;
    }
}

int main()
{
    vector<int> v = {0,1,1,0,1,1,0,0,2,0,0};
    sortColor(v);
    for (const int &i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}