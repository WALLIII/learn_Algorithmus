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



// int main()
// {
    // TreeNode *pN1 = CreateBinaryTreeNode(8);
    // TreeNode *pN2 = CreateBinaryTreeNode(6);
    // TreeNode *pN3 = CreateBinaryTreeNode(10);
    // TreeNode *pN4 = CreateBinaryTreeNode(5);
    // TreeNode *pN5 = CreateBinaryTreeNode(7);
    // TreeNode *pN6 = CreateBinaryTreeNode(9);
    // TreeNode *pN7 = CreateBinaryTreeNode(11);

    // ConnectTreeNodes(pN1, pN2, pN3);
    // ConnectTreeNodes(pN2, pN4, pN5);
    // ConnectTreeNodes(pNc, pNf, pNg);

//     DestroyTree(pNa);
//     return 0;
// }