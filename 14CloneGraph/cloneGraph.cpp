#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct GraphNode
{
    int label;
    vector<GraphNode *> next;
    GraphNode(int l) : label(l) {}
};

GraphNode *cloneGraph(GraphNode *root)
{
    if (root == NULL)   return NULL;
    queue<GraphNode *> q_origin;
    queue<GraphNode *> q_copy;
    q_origin.push(root);
    GraphNode *root_copy = new GraphNode(root->label);
    q_copy.push(root_copy);

    unordered_map<int, GraphNode *> map;
    map[root->label] = root_copy;

    while (!q_origin.empty())
    {
        GraphNode *node_origin = q_origin.front();
        q_origin.pop();
        GraphNode *node_copy = q_copy.front();
        q_copy.pop();

        for (int i = 0; i < node_origin->next.size(); ++i)
        {
            GraphNode *next_i = node_origin->next[i];
            GraphNode *copy_i = NULL;
            if (map.find(next_i->label) == map.end())
            {
                copy_i = new GraphNode(next_i->label);
                map[next_i->label] = copy_i;
            }
            else
                copy_i = map[next_i->label];
            node_copy->next.push_back(copy_i);
            q_origin.push(next_i);
            q_copy.push(copy_i);
        }
    }
    return map[root->label];
}

unordered_map<int, GraphNode *> n_map;

GraphNode *cloneGraphRecur(GraphNode *node)
{
    if (node == NULL)   return NULL;
    int label = node->label;
    if (n_map[label] != NULL) return n_map[label];
    GraphNode *c_node = new GraphNode(label);
    n_map[label] = c_node;

    for (int i = 0; i < node->next.size(); ++i)
    {
        c_node->next.push_back(cloneGraphRecur(node->next[i]));
    }
    return c_node;
}

void traversal(GraphNode *node)
{
    if (node == NULL)   return;
    cout << node->label << " ";
    for (GraphNode *n : node->next)
    {
        traversal(n);
    }
}

int main()
{
    GraphNode *node1 = new GraphNode(1);
    GraphNode *node2 = new GraphNode(2);
    GraphNode *node3 = new GraphNode(3);
    GraphNode *node4 = new GraphNode(4);
    GraphNode *node5 = new GraphNode(5);

    node1->next.push_back(node4);
    node1->next.push_back(node5);
    node1->next.push_back(node2);
    node5->next.push_back(node3);

    traversal(node1);
    cout << endl;
    GraphNode *copy = cloneGraph(node1);
    traversal(copy);
    cout << endl;
    GraphNode *copy_cur = cloneGraphRecur(node1);
    traversal(copy_cur);
    cout << endl;
}