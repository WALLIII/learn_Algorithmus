

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

TreeNode *Convert(TreeNode *pRootOfTree)
{
    if (pRootOfTree == nullptr)
        return nullptr;
    TreeNode *pre = nullptr;

    convertHelper(pRootOfTree, pre);

    TreeNode *res = pRootOfTree;
    while (res->left)
        res = res->left;
    return res;
}

void convertHelper(TreeNode *cur, TreeNode *&pre)
{
    if (cur == nullptr)
        return;

    convertHelper(cur->left, pre);

    cur->left = pre;
    if (pre)
        pre->right = cur;
    pre = cur;

    convertHelper(cur->right, pre);
}

// TreeNode* Convert(TreeNode* pRootOfTree)
//     {
//         TreeNode *head = NULL, *pre = NULL;//head 输出，pre记录上一次出栈值
//         stack<TreeNode*> s;
//         while (pRootOfTree || !s.empty())
//         {
//             while (pRootOfTree)
//             {
//                 s.push(pRootOfTree);
//                 pRootOfTree = pRootOfTree->left;
//             }
//             if (!s.empty())
//             {
//                 pRootOfTree = s.top();
//                 s.pop();
//                 if (pre != NULL)
//                 {
//                     pre->right = pRootOfTree;
//                     pRootOfTree->left = pre;
//                 }
//                 else//pre为空，表示s第一次出栈，第一次出栈值为最左值，即输出值
//                     {
//                     head = pRootOfTree;
//                 }
//                 pre = pRootOfTree;
//                 pRootOfTree = pRootOfTree->right;
//             }
//         }
//         return head;
//     }
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

    DestroyTree(pNa);
    return 0;
}