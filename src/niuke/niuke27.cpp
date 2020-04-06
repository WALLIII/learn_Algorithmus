#include <vector>
#include <iostream>
#include <stack>
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

void Mirror_recursively(TreeNode *pRoot)
{
    if (!pRoot)
        return;
    if (!pRoot->left && !pRoot->right)
        return;
    TreeNode *ptemp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = ptemp;
    if (pRoot->left)
        Mirror_recursively(pRoot->left);
    if (pRoot->right)
        Mirror_recursively(pRoot->right);
}

void Mirror_iteratively(TreeNode *pRoot)
{

    if (pRoot == NULL)
        return;
    std::stack<TreeNode *> stackNode;
    stackNode.push(pRoot);
    while (stackNode.size())
    {
        TreeNode *tree = stackNode.top();
        stackNode.pop();
        if (tree->left != NULL || tree->right != NULL)
        {
            TreeNode *ptemp = tree->left;
            tree->left = tree->right;
            tree->right = ptemp;
        }
        if (tree->left)
            stackNode.push(tree->left);
        if (tree->right)
            stackNode.push(tree->right);
    }
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
    // PrintTree(pNa);
    Mirror_recursively(pNa);
    PrintTree(pNa);
    // TreeNode *pa = CreateBinaryTreeNode(8);
    // TreeNode *pb = CreateBinaryTreeNode(9);
    // TreeNode *pc = CreateBinaryTreeNode(2);

    // ConnectTreeNodes(pa, pb, pc);

    return 0;
}