#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

bool containDuplicate(vector<int>& nums, int k, int t) 
{
    if (nums.size() < 2 || t < 0 || k < 0)    return false;
    set<long> s;
    queue<long> q;
    q.push(nums.front());
    s.insert(nums.front());
    
    for (int i = 1; i < nums.size(); ++i)
    {
        long n = nums[i];
        if (q.size() > k)
        {
            s.erase(q.front());
            q.pop();
        }
        set<long>::iterator low = s.upper_bound(n - t - 1);
        set<long>::iterator high = s.upper_bound(n + t);
        // cout << n << " " << t << " " << distance(low, high) << " " << distance(low, s.end()) << endl;
        if (distance(low, high) > 0)   
            return true;
        q.push(n);
        s.insert(n);
    }
    return false;
}

int main()
{
    vector<int> v = {1,4,9,5,3,6,11};
    cout << containDuplicate(v, 1, 2) << endl;
}