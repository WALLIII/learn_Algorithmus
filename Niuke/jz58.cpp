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

void PrintTreeNode(const TreeNode *pNode)
{
    if (pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->val);

        if (pNode->left != nullptr)
            printf("value of its left child is: %d.\n", pNode->left->val);
        else
            printf("left child is nullptr.\n");

        if (pNode->right != nullptr)
            printf("value of its right child is: %d.\n", pNode->right->val);
        else
            printf("right child is nullptr.\n");
    }
    else
    {
        printf("this node is nullptr.\n");
    }

    printf("\n");
}

void PrintTree(const TreeNode *pRoot)
{
    PrintTreeNode(pRoot);

    if (pRoot != nullptr)
    {
        if (pRoot->left != nullptr)
            PrintTree(pRoot->left);

        if (pRoot->right != nullptr)
            PrintTree(pRoot->right);
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

bool isSymmetric(TreeNode *pRoot)
{
    if (pRoot == NULL)
        return true;
    std::queue<TreeNode *> q1, q2;
    TreeNode *left, *right;
    q1.push(pRoot->left);
    q2.push(pRoot->right);
    while (!q1.empty() and !q2.empty()) 
    {
        left = q1.front();
        q1.pop();
        right = q2.front();
        q2.pop();
        if (NULL == left && NULL == right)
            continue;
        if (NULL == left || NULL == right)
            return false;
        if (left->val != right->val)
            return false;
        q1.push(left->left);
        q1.push(left->right);
        q2.push(right->right);
        q2.push(right->left);
    }

    return true;
}

int main()
{
    TreeNode *pNa = CreateBinaryTreeNode(8);
    TreeNode *pNb = CreateBinaryTreeNode(8);
    TreeNode *pNc = CreateBinaryTreeNode(7);
    TreeNode *pNd = CreateBinaryTreeNode(9);
    TreeNode *pNe = CreateBinaryTreeNode(2);
    TreeNode *pNf = CreateBinaryTreeNode(4);
    TreeNode *pNg = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNa, pNb, pNc);
    ConnectTreeNodes(pNb, pNd, pNe);
    ConnectTreeNodes(pNe, pNf, pNg);

    PrintTree(pNa);

    return 0;
}