#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v, TreeNode *l = NULL, TreeNode *r = NULL) 
        : val(v), left(l), right(r) {}
};

TreeNode *inorderSuccessor(TreeNode *root, TreeNode *node)
{
    TreeNode *result = NULL, *cur = root;

    while (cur != NULL)
    {
        if (cur->val <= node->val)
            cur = cur->right;
        else
        {
            result = cur;
            cur = cur->left;
        }
    }
    return result;
}

void inorderTraversal(TreeNode *root)
{
    TreeNode *cur = root;
    stack<TreeNode *> stk;

    while (!stk.empty() || cur != NULL)
    {
        if (cur != NULL)
        {
            stk.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = stk.top();
            stk.pop();
            cout << cur->val << " ";
            cur = cur->right;
        }
    }
    cout << endl;
}

int main()
{
    TreeNode *tn1 = new TreeNode(1);
    TreeNode *tn3 = new TreeNode(3);
    TreeNode *tn2 = new TreeNode(2, tn1, tn3);
    TreeNode *tn5 = new TreeNode(5);
    TreeNode *tn7 = new TreeNode(7);
    TreeNode *tn6 = new TreeNode(6, tn5, tn7);
    TreeNode *tn4 = new TreeNode(4, tn2, tn6);

    inorderTraversal(tn4);
    cout << inorderSuccessor(tn4, tn3)->val << endl;
}