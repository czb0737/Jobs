#include <iostream>
#include <vector>

using namespace std;

int numHole(int n);

int main()
{
    cout << numHole(812345678) << endl;
}

int numHole(int num)
{
    vector<int> v = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
    int count = 0;
    while (num)
    {
        count += v[num % 10];
        num /= 10;
    }
    return count;
}