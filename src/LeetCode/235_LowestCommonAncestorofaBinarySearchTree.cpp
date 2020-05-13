#include "../Utils/TreeTemplate.cpp"

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root==nullptr)
        return nullptr;
    if(p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    if(p->val > root->val && q->val>root->val)
        return lowestCommonAncestor(root->right, p, q);
    return root;
}
int main()
{
    TreeNode *pNa = CreateBinaryTreeNode(6);
    TreeNode *pNb = CreateBinaryTreeNode(2);
    TreeNode *pNc = CreateBinaryTreeNode(8);
    TreeNode *pNd = CreateBinaryTreeNode(0);
    TreeNode *pNe = CreateBinaryTreeNode(4);
    TreeNode *pNf = CreateBinaryTreeNode(3);
    TreeNode *pNg = CreateBinaryTreeNode(5);
    TreeNode *pNh = CreateBinaryTreeNode(7);
    TreeNode *pNi = CreateBinaryTreeNode(9);
    ConnectTreeNodes(pNa, pNb, pNc);
    ConnectTreeNodes(pNb, pNd, pNe);
    ConnectTreeNodes(pNc, pNh, pNi);
    ConnectTreeNodes(pNe, pNf, pNg);

    std::cout<<lowestCommonAncestor(pNa,pNd,pNe)->val<<std::endl;
    DestroyTree(pNa);
    return 0;
}