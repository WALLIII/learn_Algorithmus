#include "../Utils/TreeTemplate.cpp"

static int sum = 0;

// TreeNode *convertBST(TreeNode *root)
// {
//     if(root){
//         convertBST(root->right);
//         sum+=root->val;
//         root->val=sum;
//         convertBST(root->left);
//     }
//     return root;
// }
TreeNode *convertBST(TreeNode *root)
{
    if(!root)
        return root;
    int sum=0;
    TreeNode* curr=root;
    std::stack<TreeNode*> sk;
    while(!sk.empty()||curr){
        while(curr){
            sk.push(curr);
            curr=curr->right;
        }
        curr=sk.top();
        sk.pop();
        sum+=curr->val;
        curr->val=sum;
        curr=curr->left;
    }
    return root;
}
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
    TreeNode *pnew = convertBST(pN1);
    levelOrder(pnew);
    DestroyTree(pN1);
    return 0;
}