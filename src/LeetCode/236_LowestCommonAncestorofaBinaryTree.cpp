#include "../Utils/TreeTemplate.cpp"

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    //如果当前节点为pq中的任意一个，就直接返回，答案就是那个相等的节点。
    if (!root || root == p || root == q)
        return root;
    //分别探索左右儿子
    TreeNode *l = lowestCommonAncestor(root->left, p, q);
    TreeNode *r = lowestCommonAncestor(root->right, p, q);
    //如果在左右儿子中都找到了的话，l和r都不会为空，那当前root就是要找的答案
    if (l && r)
        return root;
    //左右儿子至少有一个为空，返回不空的那个。如果都为空，返回任意一个，都是空
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