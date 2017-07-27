#include <iostream>
#include <vector>

using namespace std;

vector<int> findDup(vector<int> &v)
{
    vector<int> result;
    vector<int> dup(1000, 0);

    for (const int &n : v)
    {
        int index = n / 32;
        int bit = n % 32;
        if ((dup[index] & (1 << bit)) != 0) result.push_back(n);
        dup[index] = dup[index] | (1 << bit);
    }
    return result;
}

int main()
{
    vector<int> v = {200,100,4,5,100,5,9};
    vector<int> result = findDup(v);
    for (const int &n : result)
        cout << n << " ";
    cout << endl;
}