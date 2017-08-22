#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &n1, vector<int> &n2, int size1)
{
    int ptr1 = size1 - 1, ptr2 = n2.size() - 1, ptr = ptr1 + ptr2 + 1;
    while (ptr1 >= 0 && ptr2 >= 0)
    {
        if (n1[ptr1] > n2[ptr2])
            n1[ptr--] = n1[ptr1--];
        else
            n1[ptr--] = n2[ptr2--];
    }
    if (ptr1 < 0)
        copy(n2.begin(), n2.begin() + ptr2 + 1, n1.begin());
}

int main(int argc, char **argv)
{
    vector<int> v1 = {1, 3, 5, 7, 9};
    vector<int> v2 = {-1, 0, 0, 2, 4, 6, 8, 10};
    v1.resize(v1.size() + v2.size());
    merge(v1, v2, 5);
    for (auto &i : v1)
        cout << i << endl;
}