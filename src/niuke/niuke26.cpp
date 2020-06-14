#include "../Utils/TreeTemplate.cpp"

bool subTree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    // 以tree2是否为空作为递归出口。
    if (!pRoot2)
        return true;
    if (!pRoot1)
        return false; //当1为空的时候，还没有地方返回true,说明没有找到一样的子树
    if (pRoot1->val == pRoot2->val)
    {
        //如果当前的tree1和tree2的根节点相等，继续探究他们的左右儿子。左右儿子都返回true才可以。
        return subTree(pRoot1->left, pRoot2->left) && subTree(pRoot1->right, pRoot2->right);
    }
    return false;
}

bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    // 题目里写了，空树不认为是任何树的子树
    if (!(pRoot1 && pRoot2))
        return false;
    if (pRoot1->val == pRoot2->val)
    {
        // 如果根节点一样，就判断他们的孩子是否一样
        if (subTree(pRoot1, pRoot2))
            return true;
    }
    return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}

int main()
{
    TreeNode *pN1 = CreateBinaryTreeNode(8);
    TreeNode *pN2 = CreateBinaryTreeNode(8);
    TreeNode *pN3 = CreateBinaryTreeNode(7);
    TreeNode *pN4 = CreateBinaryTreeNode(9);
    TreeNode *pN5 = CreateBinaryTreeNode(2);
    TreeNode *pN6 = CreateBinaryTreeNode(4);
    TreeNode *pN7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pN1, pN2, pN3);
    ConnectTreeNodes(pN2, pN4, pN5);
    ConnectTreeNodes(pN5, pN6, pN7);

    TreeNode *p1 = CreateBinaryTreeNode(2);
    TreeNode *p2 = CreateBinaryTreeNode(4);
    TreeNode *p3 = CreateBinaryTreeNode(7);
    ConnectTreeNodes(p1, p2, p3);

    if (HasSubtree(pN1, p1))
        std::cout << "is sub tree" << std::endl;
    else
        std::cout << "is not sub tree" << std::endl;

    DestroyTree(pN1);
    DestroyTree(p1);

    return 0;
}