
int TreeDepth(TreeNode *pRoot)
{
    if (!pRoot)
        return 0;
    int nLeft = TreeDepth(pRoot->left);
    int nRight = TreeDepth(pRoot->right);
    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

// bool IsBalanced_Solution(TreeNode *pRoot)
// {
//     if (!pRoot)
//         return true;
//     int nLeft = TreeDepth(pRoot->left);#include "../Utils/TreeTemplate.cpp"

// 用求左右子树深度的方法来判断是否为平衡二叉树
// int TreeDepth(TreeNode *pRoot)
// {
//     if (!pRoot)
//         return 0;
//     int nLeft = TreeDepth(pRoot->left);
//     int nRight = TreeDepth(pRoot->right);
//     return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
// }

// bool IsBalanced_Solution(TreeNode *pRoot)
// {
//     if (!pRoot)
//         return true;
//     int nLeft = TreeDepth(pRoot->left);
//     int nRight = TreeDepth(pRoot->right);

//     if (nLeft - nRight > 1 || nLeft - nRight < -1)
//         return false;
//     return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
// }

bool IsBalanced(TreeNode *root, int &dep)
{
    if (root == NULL)
    {
        return true;
    }
    int left = 0;
    int right = 0;
    if (IsBalanced(root->left, left) && IsBalanced(root->right, right))
    {
        int dif = left - right;
        if (dif < -1 || dif > 1)
            return false;
        dep = (left > right ? left : right) + 1;
        return true;
    }
    return false;
}
bool IsBalanced_Solution(TreeNode *pRoot)
{
    int dep = 0;
    return IsBalanced(pRoot, dep);
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
    // ConnectTreeNodes(pNc, nullptr, pNf);
    ConnectTreeNodes(pNe, pNg, nullptr);
    if (IsBalanced_Solution(pNa))
        std::cout << "balanced" << std::endl;
    else
        std::cout << "unbalanced" << std::endl;

    DestroyTree(pNa);
    return 0;
}
//     int nRight = TreeDepth(pRoot->right);

//     if (nLeft - nRight > 1 || nLeft - nRight < -1)
//         return false;
//     return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
// }

bool IsBalanced(TreeNode *root, int &dep)
{
    if (root == NULL)
    {
        return true;
    }
    int left = 0;
    int right = 0;
    if (IsBalanced(root->left, left) && IsBalanced(root->right, right))
    {
        int dif = left - right;
        if (dif < -1 || dif > 1)
            return false;
        dep = (left > right ? left : right) + 1;
        return true;
    }
    return false;
}
bool IsBalanced_Solution(TreeNode *pRoot)
{
    int dep = 0;
    return IsBalanced(pRoot, dep);
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
    // ConnectTreeNodes(pNc, nullptr, pNf);
    ConnectTreeNodes(pNe, pNg, nullptr);
    if (IsBalanced_Solution(pNa))
        std::cout << "balanced" << std::endl;
    else
        std::cout << "unbalanced" << std::endl;

    DestroyTree(pNa);
    return 0;
}