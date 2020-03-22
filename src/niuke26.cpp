#include <vector>
#include <iostream>

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

bool isSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    if (!pRoot2)
        return true;
    if (!pRoot1)
        return false;
    if (pRoot1->val != pRoot2->val)
    {
        return false;
    }
    return isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
}
bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    if (!pRoot1 || !pRoot2)
    {
        std::cout << "!!!!nullptr" << std::endl;
        return false;
    }
    bool flag = isSubtree(pRoot1, pRoot2);
    if (!flag)
        flag = isSubtree(pRoot1->left, pRoot2);
    if (!flag)
        flag = isSubtree(pRoot1->right, pRoot2);
    return flag;
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

    TreeNode *pa = CreateBinaryTreeNode(8);
    TreeNode *pb = CreateBinaryTreeNode(9);
    TreeNode *pc = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pa, pb, pc);

    if (HasSubtree(pNa, pa))
        std::cout << "tree b is subtree of a" << std::endl;
    else
        std::cout << "tree b is not subtree of a" << std::endl;

    return 0;
}