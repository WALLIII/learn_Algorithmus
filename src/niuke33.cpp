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

// recursively
bool VerifySquenceOfBST(std::vector<int> sequence)
{
    if (sequence.size() <= 0)
    {
        return false;
    }
    int length = sequence.size();
    std::vector<int> leftTree;
    std::vector<int> rightTree;
    int i = 0;
    for (i = 0; i < length - 1; ++i)
    {
        if (sequence[i] < sequence[length - 1])
        {
            leftTree.push_back(sequence[i]);
        }
        else
            break;
    }
    int j = i;
    for (j = i; j < length - 1; ++j)
    {
        if (sequence[j] > sequence[length - 1])
        {
            rightTree.push_back(sequence[j]);
        }
        else
            return false;
    }
    bool left = true;
    bool right = true;
    if (!leftTree.empty())
        left = VerifySquenceOfBST(leftTree);
    if (!rightTree.empty())
    {
        right = VerifySquenceOfBST(rightTree);
    }
    return left && right;
}

// non recursively
bool VerifySquenceOfBST2(std::vector<int> sequence)
{
    int size = sequence.size();
    if (0 == size)
        return false;

    int i = 0;
    while (--size)
    {
        while (sequence[i++] < sequence[size])
            ;
        while (sequence[i++] > sequence[size])
            ;

        if (i < size)
            return false;
        i = 0;
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
    std::vector<int> postOrderSerice = {7, 4, 6, 5};
    bool result = VerifySquenceOfBST(postOrderSerice);
    std::cout << "result: " << result << std::endl;

    DestroyTree(pNa);
    return 0;
}