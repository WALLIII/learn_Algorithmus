#include "../Utils/TreeTemplate.cpp"

int maxPathSum(TreeNode *root, int &maxVal)
{
    if (root == nullptr)
        return 0;
    int left = maxPathSum(root->left, maxVal);
    int right = maxPathSum(root->right, maxVal);
    //candidate是maxVal的候选值，是取两个子树的最优路径和，因为路径可以不是从根节点到也节点
    int candidate = root->val + max(0, left) + max(0, right);
    maxVal = maxVal > candidate ? maxVal : candidate;
    //当前root作为根节点的最优的一条路径，在左右儿子的最优解中只能选其一跟自己相加，给更大的子问题提供答案
    int subTreeMax = root->val + max(0, max(left, right));
    return subTreeMax;
}

int maxPathSum(TreeNode *root)
{
    int maxVal = INT_MIN;
    int ret = maxPathSum(root, maxVal);
    return maxVal;
}
int main()
{
    TreeNode *pN1 = CreateBinaryTreeNode(-10);
    TreeNode *pN2 = CreateBinaryTreeNode(9);
    TreeNode *pN3 = CreateBinaryTreeNode(20);
    TreeNode *pN4 = CreateBinaryTreeNode(15);
    TreeNode *pN5 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pN1, pN2, pN3);
    ConnectTreeNodes(pN3, pN4, pN5);
    std::cout << maxPathSum(pN1) << std::endl;
    DestroyTree(pN1);
    return 0;
}