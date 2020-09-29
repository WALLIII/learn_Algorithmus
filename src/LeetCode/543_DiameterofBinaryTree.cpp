#include "../Utils/TreeTemplate.cpp"

static int ans = 0;
int depth(TreeNode *root)
{
    if (!root)
        return 0;
    int L = depth(root->left);
    int R = depth(root->right);
    ans = std::max(ans, L + R + 1);
    return std::max(L, R) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;
    else
        depth(root);
    return ans - 1;
}
// 搬了一下二叉树最大路径和的套路
// int diameterOfBinaryTree(TreeNode *root, int &ans)
// {
//     if (!root)
//         return 0;
//     int l = diameterOfBinaryTree(root->left, ans);
//     int r = diameterOfBinaryTree(root->right, ans);
//     int candidate = 1 + l + r;
//     ans = ans > candidate ? ans : candidate;
//     int subtree = 1 + max(l, r);
//     return subtree;
// }
// int diameterOfBinaryTree(TreeNode *root)
// {
//     if (!root)
//         return 0;
//     int ans = 0;
//     int res = diameterOfBinaryTree(root, ans);
//     return ans - 1;
// }
int main()
{
    TreeNode *pN1 = CreateBinaryTreeNode(8);
    TreeNode *pN2 = CreateBinaryTreeNode(6);
    TreeNode *pN3 = CreateBinaryTreeNode(10);
    TreeNode *pN4 = CreateBinaryTreeNode(5);
    TreeNode *pN5 = CreateBinaryTreeNode(7);
    TreeNode *pN6 = CreateBinaryTreeNode(9);
    TreeNode *pN7 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pN1, pN2, pN3);
    // ConnectTreeNodes(pN2, pN4, pN5);
    // ConnectTreeNodes(pN3, pN6, pN7);
    std::cout << diameterOfBinaryTree(pN1) << std::endl;
    DestroyTree(pN1);
    return 0;
}
