#include "../Utils/TreeTemplate.cpp"

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root || root == p || root == q)
        return root;
    TreeNode *l = lowestCommonAncestor(root->left, p, q);
    TreeNode *r = lowestCommonAncestor(root->right, p, q);
    if (l && r)
        return root;
    return l ? l : r;
}
int main()
{
    TreeNode *pNa = CreateBinaryTreeNode(3);
    TreeNode *pNb = CreateBinaryTreeNode(5);
    TreeNode *pNc = CreateBinaryTreeNode(1);
    TreeNode *pNd = CreateBinaryTreeNode(6);
    TreeNode *pNe = CreateBinaryTreeNode(2);
    TreeNode *pNf = CreateBinaryTreeNode(7);
    TreeNode *pNg = CreateBinaryTreeNode(4);
    TreeNode *pNh = CreateBinaryTreeNode(0);
    TreeNode *pNi = CreateBinaryTreeNode(8);
    ConnectTreeNodes(pNa, pNb, pNc);
    ConnectTreeNodes(pNb, pNd, pNe);
    ConnectTreeNodes(pNc, pNh, pNi);
    ConnectTreeNodes(pNe, pNf, pNg);

    std::cout << lowestCommonAncestor(pNa, pNd, pNe)->val << std::endl;
    DestroyTree(pNa);
    return 0;
}