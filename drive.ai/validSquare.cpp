#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

long dist(vector<int> &p1, vector<int> &p2)
{
    long dx = p1[0] - p2[0];
    long dy = p1[1] - p2[1];
    return dx * dx + dy * dy;
}

bool validSquare(vector<vector<int>> &points)
{
    unordered_set<long> uset({dist(points[0], points[1]), 
        dist(points[0], points[2]), 
        dist(points[0], points[3]), 
        dist(points[1], points[2]), 
        dist(points[1], points[3]), 
        dist(points[2], points[3])});
    return uset.find(0) == uset.end() && uset.size() == 2;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> v = {{0, 0}, {0, 3}, {3, 0}, {3, 2}};
    cout << validSquare(v) << endl;
}