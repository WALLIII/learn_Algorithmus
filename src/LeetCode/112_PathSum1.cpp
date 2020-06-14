#include "../Utils/TreeTemplate.cpp"

bool hasPathSum(TreeNode *root, int sum)
{
    if (!root)
        return false;
    if (root->val == sum && !root->left && !root->right)
        return true;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

int main()
{
    TreeNode *pNa = CreateBinaryTreeNode(1);
    TreeNode *pNb = CreateBinaryTreeNode(-2);
    TreeNode *pNc = CreateBinaryTreeNode(-3);
    TreeNode *pNd = CreateBinaryTreeNode(1);
    TreeNode *pNe = CreateBinaryTreeNode(3);
    TreeNode *pNf = CreateBinaryTreeNode(-2);
    TreeNode *pNg = CreateBinaryTreeNode(-1);

    ConnectTreeNodes(pNa, pNb, pNc);
    ConnectTreeNodes(pNb, pNd, pNe);
    ConnectTreeNodes(pNc, pNf, nullptr);
    ConnectTreeNodes(pNd, pNg, nullptr);

    if (hasPathSum(pNa, -1))
    {
        std::cout << "has....." << std::endl;
    }
    else
    {
        std::cout << "has not..." << std::endl;
    }
    DestroyTree(pNa);
    return 0;
}