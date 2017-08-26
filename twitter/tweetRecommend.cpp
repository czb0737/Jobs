#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> tweetRecommend(vector<vector<int>> &follows, vector<vector<int>> &likes, int target_user, int threshold);

struct Comp
{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        return p1.second < p2.second;
    }
};

vector<int> tweetRecommend(vector<vector<int>> &follows, vector<vector<int>> &likes, int target_user, int threshold)
{
    vector<int> result;
    unordered_set<int> fs;
    unordered_map<int, int> tweets;

    for (vector<int> &v : follows)
        if (v[0] == target_user)
            fs.insert(v[1]);

    for (vector<int> &v : likes)
        if (fs.find(v[0]) != fs.end())
            ++tweets[v[1]];

    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
    for (auto &p : tweets)
        if (p.second >= threshold)
            pq.push(p);

    while (!pq.empty())
    {
        result.push_back(pq.top().first);
        pq.pop();
    }
    return result;
}

int main(int argc, char **argv)
{
    vector<vector<int>> follows = {{0, 1}, {0, 2}, {0, 3}, {4, 1}, {4, 2}, {4, 3}};
    vector<vector<int>> likes = {{1, 0}, {2, 0}, {1, 1}, {2, 1}, {3, 1}, {1, 2}};
    vector<int> result = tweetRecommend(follows, likes, 0, 2);
    for (auto &i : result)
        cout << i << " ";
    cout << endl;
}