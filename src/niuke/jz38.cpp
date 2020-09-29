#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include "../Utils/TreeTemplate.cpp"

int TreeDepth(TreeNode *pRoot) {
    if (!pRoot)
        return 0;
    int nLeft=TreeDepth(pRoot->left);
    int nRight=TreeDepth(pRoot->right);
    return (nLeft>nRight)?(nLeft+1):(nRight+1);
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
    ConnectTreeNodes(pNc, nullptr, pNf);
    ConnectTreeNodes(pNe, pNg, nullptr);

    std::cout<<TreeDepth(pNa)<<std::endl;

    DestroyTree(pNa);
    return 0;
}