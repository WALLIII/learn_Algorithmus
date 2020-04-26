#include <vector>
#include <iostream>
#include <stack>
#include <queue>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

TreeNode *CreateBinaryTreeNode(int value)
{
    TreeNode *pNode = new TreeNode(value);
    pNode->val = value;
    pNode->left = nullptr;
    pNode->right = nullptr;

    return pNode;
}

void ConnectTreeNodes(TreeNode *pParent, TreeNode *pLeft, TreeNode *pRight)
{
    if (pParent != nullptr)
    {
        pParent->left = pLeft;
        pParent->right = pRight;
    }
}

void DestroyTree(TreeNode *pRoot)
{
    if (pRoot != nullptr)
    {
        TreeNode *pLeft = pRoot->left;
        TreeNode *pRight = pRoot->right;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}
// void preorderTraversal(TreeNode *root, std::vector<int> &preOrder)
// {
//     if (!root)
//         return;
//     preOrder.push_back(root->val);
//     preorderTraversal(root->left, preOrder);
//     preorderTraversal(root->right, preOrder);
// }
// std::vector<int> preorderTraversal(TreeNode *root)
// {
//     std::vector<int> preOrder;
//     if (!root)
//         return preOrder;
//     preorderTraversal(root, preOrder);
//     return preOrder;
// }
std::vector<int> preorderTraversal(TreeNode *root)
{
    std::vector<int> ans;
    if (root == nullptr)
        return ans;
    std::stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *tmp = st.top();
        st.pop();
        ans.push_back(tmp->val);
        if (tmp->right)
            st.push(tmp->right);
        if (tmp->left)
            st.push(tmp->left);
    }
    return ans;
}
// std::vector<int> preorderTraversal(TreeNode *root)
// {
//     std::stack<TreeNode *> nodes;
//     std::vector<int> res;
//     while (root || !nodes.empty())
//     {
//         while (root)
//         {
//             nodes.push(root->right);
//             res.push_back(root->val);
//             root = root->left;
//         }
//         root = nodes.top();
//         nodes.pop();
//     }
//     return res;
// }
// }
int main()
{
    TreeNode *pNa = CreateBinaryTreeNode(8);
    TreeNode *pNb = CreateBinaryTreeNode(6);
    TreeNode *pNc = CreateBinaryTreeNode(10);
    TreeNode *pNd = CreateBinaryTreeNode(5);
    TreeNode *pNe = CreateBinaryTreeNode(7);
    TreeNode *pNf = CreateBinaryTreeNode(9);
    TreeNode *pNg = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNa, pNb, pNc);
    ConnectTreeNodes(pNb, pNd, pNe);
    ConnectTreeNodes(pNc, pNf, pNg);

    std::vector<int> preOrder;
    preOrder = preorderTraversal(pNa);
    for (auto a : preOrder)
        std::cout << a << "   ";
    std::cout << std::endl;

    DestroyTree(pNa);
    return 0;
}