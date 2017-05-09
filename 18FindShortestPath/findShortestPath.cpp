#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    int r;
    int c;
    Node *parent;
    unordered_set<char> keys;
    
    Node(int nr, int nc, Node *np = NULL, unordered_set<char> nk = unordered_set<char>())
        : r(nr), c(nc), parent(np), keys(nk) {}

    bool operator==(const Node &n) const
    {
        return r == n.r && c == n.c && keys == n.keys;
    }

    string toString()
    {
        string result = "[" + to_string(r) + ", " + to_string(c) + "] with keys [";
        for (const char &key : keys)
        {
            result += key + ", ";
        }
        return result + "]";
    }
};

namespace std
{
    template<>
    struct hash<Node>
    {
        size_t operator()(const Node &n) const
        {
            return hash<int>()(n.r + n.c + n.keys.size());
        }
    };
}

Node *findShortestPath(vector<string> &map, Node start)
{
    queue<Node *> q;
    q.push(&start);
    unordered_set<Node> visited;

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (map[node->r][node->c] == '3') return node;
        vector<int> direct = {-1, 0, 1, 0, -1};

        for (int i = 1; i < direct.size(); ++i)
        {
            int r = node->r + direct[i - 1];
            int c = node->c + direct[i];
            if ((r < 0 || r >= map.size()) || (c < 0 || c >= map[0].length()))  continue;

            char lttr = map[r][c];
            if (lttr == '0')    continue;
            if (lttr >= 'A' && lttr <= 'Z' && node->keys.find(lttr - 'A' + 'a') == node->keys.end()) 
                continue;

            Node *next = new Node(r, c, node, node->keys);
            if (lttr >= 'A' && lttr <='Z')
                next->keys.erase(lttr - 'A' + 'a');
            if (lttr >= 'a' && lttr <= 'z')
                next->keys.insert(lttr);
            if (visited.find(*next) != visited.end())
                continue;
            q.push(next);
            visited.insert(*next);
            // cout << "Next: " << next->toString() << "\t" << lttr << endl;
        }
    }
    return NULL;
}

int main()
{
    vector<string> map = {
        "1a100",
        "10100",
        "10100",
        "10100",
        "211A3"
    };
    Node start(4, 0);
    Node *end = findShortestPath(map, start);

    if (end == NULL)    cout << "No path!" << endl;
    else
    {
        Node *traversal = end;
        while (traversal != NULL)
        {
            cout << traversal->toString() << endl;
            traversal = traversal->parent;
        }
    }
}