#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v, TreeNode *l = NULL, TreeNode *r = NULL)
        : val(v), left(l), right(r) {}
};

vector<int> morrisTraversal(TreeNode *root)
{
    vector<int> result;
    TreeNode *cur = root, *pre = NULL;
    while (cur != NULL)
    {
        if (cur->left != NULL)
        {
            pre = cur->left;
            while (pre->right != NULL && pre->right != cur)
                pre = pre->right;
            if (pre->right == NULL)
            {
                pre->right = cur;
                cur = cur->left;
            }
            else
            {
                result.push_back(cur->val);
                pre->right = NULL;
                cur = cur->right;
            }
        }
        else
        {
            result.push_back(cur->val);
            cur = cur->right;
        }
    }
    return result;
}

void inOrder(TreeNode *root)
{
    if (root == NULL)   return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main(int args, char *argv[])
{
    TreeNode *tn1 = new TreeNode(1);
    TreeNode *tn2 = new TreeNode(2);
    TreeNode *tn3 = new TreeNode(3);
    TreeNode *tn4 = new TreeNode(4);
    TreeNode *tn5 = new TreeNode(5, tn1, tn2);
    TreeNode *tn6 = new TreeNode(6, tn3, tn4);
    TreeNode *tn7 = new TreeNode(7, tn5, tn6);
    vector<int> result = morrisTraversal(tn7);
    for (int &i : result)
        cout << i << " ";
    // inOrder(tn7);
    cout << endl;
}