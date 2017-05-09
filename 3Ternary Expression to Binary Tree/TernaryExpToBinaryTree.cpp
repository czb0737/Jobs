#include <string>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char c, TreeNode *l = NULL, TreeNode *r = NULL) : val(c), left(l), right(r) {}
};

class Ternary
{
private:
public:
    TreeNode *ternaryToBinaryTree(string s)
    {
        if (s.empty())  return NULL;
        stack<TreeNode *> st;

        for (int i = s.length() - 1; i >= 0; --i)
        {
            char c = s[i];
            if (!st.empty() && st.top()->val == '?')
            {
                // pop '?'
                delete st.top(), st.pop();
                TreeNode *n1 = st.top(); st.pop();
                // pop ':'
                delete st.top(), st.pop();
                TreeNode *n2 = st.top(); st.pop();

                st.push(new TreeNode(c, n1, n2));
            }
            else    st.push(new TreeNode(c));
        }
        return st.top();
    }

    void inOrderTraversal(TreeNode *root)
    {
        if(root == NULL)    return;
        inOrderTraversal(root->left);
        cout << root->val << endl;
        inOrderTraversal(root->right);
    }
};

int main()
{
    Ternary ternary;
    TreeNode *root = ternary.ternaryToBinaryTree("T?T?F:5:3");
    ternary.inOrderTraversal(root);
}