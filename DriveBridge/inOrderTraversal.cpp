/*************************************************************************
	> File Name: inOrderTraversal.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 09/08/2017 Fri 11:38:21
 ************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v, TreeNode *l = nullptr, TreeNode *r = nullptr)
        : val(v), left(l), right(r) {}
};

void inOrderTraversalR(TreeNode *root);
void inOrderTraversalI(TreeNode *root);

void inOrderTraversalR(TreeNode *root)
{
    if (root == nullptr)    return;
    inOrderTraversalR(root->left);
    cout << root->val << " ";
    inOrderTraversalR(root->right);
}

void inOrderTraversalI(TreeNode *root)
{
    stack<TreeNode *> stk;
    TreeNode *trav = root;

    while (!stk.empty() || trav != nullptr)
    {
        if (trav != nullptr)
        {
            stk.push(trav);
            trav = trav->left;
        }
        else
        {
            trav = stk.top();
            cout << trav->val << " ";
            stk.pop();
            trav = trav->right;
        }
    }
}

int main(int argc, char **argv)
{
    TreeNode *tn1 = new TreeNode(1);
    TreeNode *tn2 = new TreeNode(2);
    TreeNode *tn3 = new TreeNode(3);
    TreeNode *tn4 = new TreeNode(4);
    TreeNode *tn5 = new TreeNode(5, tn1, tn2);
    TreeNode *tn6 = new TreeNode(6, tn3, tn4);
    TreeNode *tn7 = new TreeNode(7, tn5, tn6);

    inOrderTraversalR(tn7);
    cout << endl;
    
    inOrderTraversalI(tn7);
    cout << endl;
}