#include <vector>
#include <iostream>
#include <stack>
#include <queue>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *next;
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};

TreeNode *CreateBinaryTreeNode(int value)
{
    TreeNode *pNode = new TreeNode(value);
    pNode->val = value;
    pNode->left = nullptr;
    pNode->right = nullptr;
    pNode->next = nullptr;

    return pNode;
}

void ConnectTreeNodes(TreeNode *pParent, TreeNode *pLeft, TreeNode *pRight)
{
    if (pParent != nullptr)
    {
        pParent->left = pLeft;
        pParent->right = pRight;

        if (pLeft != nullptr)
            pLeft->next = pParent;
        if (pRight != nullptr)
            pRight->next = pParent;
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

// bool dfs(TreeNode *root1, TreeNode *root2)
// {
//     if (!root1 && !root2)
//         return true;
//     if (!root1 || !root2)
//         return false;
//     if (root1->val != root2->val)
//         return false;
//     return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
// }
// bool isSymmetric(TreeNode *root)
// {
//     if (!root)
//     {
//         return false;
//     }
//     return dfs(root->left, root->right);
// }

// BFS
bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    std::queue<TreeNode *> que;
    TreeNode *curr = root;
    std::vector<int> tmp;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        std::vector<int> tmp;
        for (int i = 0; i < size; ++i)
        {
            curr = que.front();
            que.pop();
            if (curr)
            {
                que.push(curr->left);
                que.push(curr->right);
            }
            if (curr)
                tmp.push_back(curr->val);
            else
                tmp.push_back(INT_MIN);
        }
        for (int i = 0; i < size / 2; ++i)
        {
            if (tmp[i] != tmp[size - i - 1])
                return false;
        }
    }
    return true;
}

int main()
{
    TreeNode *pN1 = CreateBinaryTreeNode(1);
    TreeNode *pN2 = CreateBinaryTreeNode(2);
    TreeNode *pN3 = CreateBinaryTreeNode(2);
    TreeNode *pN4 = CreateBinaryTreeNode(3);
    TreeNode *pN5 = CreateBinaryTreeNode(4);
    TreeNode *pN6 = CreateBinaryTreeNode(4);
    TreeNode *pN7 = CreateBinaryTreeNode(3);

    ConnectTreeNodes(pN1, pN2, pN3);
    ConnectTreeNodes(pN2, pN4, pN5);
    ConnectTreeNodes(pN3, pN6, pN7);
    if (isSymmetric(pN1))
        std::cout << "symmeric" << std::endl;
    else
        std::cout << "asymmeric" << std::endl;

    DestroyTree(pN1);
    return 0;
}