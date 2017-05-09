#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool longestConsecSeq(vector<int> &v, int k)
{
    unordered_map<int, int> map;
    for (const int &n : v)
    {
        int left = map[n - 1];
        int right = map[n + 1];
        right = right == -1 ? 1 : right;

        int len = 1 - left + right;
        if (len >= k)   return true;
        
        map[n] = 1;
        map[n + left] = len;
        map[n + right] = -len;
    
    }
    return false;
}

int main()
{
    vector<int> v = {100, 4, 200, 3, 10, 2, 5, 1};
    cout << longestConsecSeq(v, 5) << endl;
}