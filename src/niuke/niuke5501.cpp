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

int TreeDepth(TreeNode *pRoot) {
    if (!pRoot)
        return 0;
    int nLeft=TreeDepth(pRoot->left);
    int nRight=TreeDepth(pRoot->right);
    return (nLeft>nRight)?(nLeft+1):(nRight+1);
}

int main()
{
    TreeNode *pNa = CreateBinaryTreeNode(1);
    TreeNode *pNb = CreateBinaryTreeNode(2);
    TreeNode *pNc = CreateBinaryTreeNode(3);
    TreeNode *pNd = CreateBinaryTreeNode(4);
    TreeNode *pNe = CreateBinaryTreeNode(5);
    TreeNode *pNf = CreateBinaryTreeNode(6);
    TreeNode *pNg = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNa, pNb, pNc);
    ConnectTreeNodes(pNb, pNd, pNe);
    ConnectTreeNodes(pNc, nullptr, pNf);
    ConnectTreeNodes(pNe, pNg, nullptr);

    std::cout<<TreeDepth(pNa)<<std::endl;

    DestroyTree(pNa);
    return 0;
}