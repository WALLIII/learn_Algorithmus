#include "../Utils/TreeTemplate.cpp"

int maxPathSum(TreeNode* root, int &maxVal){
    if(root==nullptr)
        return 0;
    int left=maxPathSum(root->left, maxVal);
    int right=maxPathSum(root->right, maxVal);
    int candidateMax=root->val+std::max(0,left)+std::max(0,right);
    int subTreeMax=root->val+std::max(0, std::max(left, right));
    maxVal=maxVal>candidateMax?maxVal:candidateMax;
    return subTreeMax;
}

int maxPathSum(TreeNode *root)
{
    int maxVal=INT_MIN;
    int ret=maxPathSum(root, maxVal);
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