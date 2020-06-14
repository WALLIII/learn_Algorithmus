#include "../Utils/TreeTemplate.cpp"

// void Mirror(TreeNode *pRoot){
//     if(!pRoot)
//         return ;
//     if(!pRoot->left && !pRoot->right)
//         return;
//     TreeNode* tmp = pRoot->left;
//     pRoot->left=pRoot->right;
//     pRoot->right=tmp;
//     if(pRoot->left)
//         Mirror(pRoot->left);
//     if(pRoot->right)
//         Mirror(pRoot->right);
// }
void Mirror(TreeNode *pRoot){
    if(!pRoot)
        return;
    std::stack<TreeNode*> sk;
    sk.push(pRoot);
    while(!sk.empty()){
        TreeNode* curr=sk.top();
        sk.pop();
        if(curr->left||curr->right){
            TreeNode* tmp=curr->left;
            curr->left=curr->right;
            curr->right=tmp;
        }
        if(curr->left)
            sk.push(curr->left);
        if(curr->right)
            sk.push(curr->right);
    }

}
int main()
{
    TreeNode *pN1 = CreateBinaryTreeNode(8);
    TreeNode *pN2 = CreateBinaryTreeNode(8);
    TreeNode *pN3 = CreateBinaryTreeNode(7);
    TreeNode *pN4 = CreateBinaryTreeNode(9);
    TreeNode *pN5 = CreateBinaryTreeNode(2);
    TreeNode *pN6 = CreateBinaryTreeNode(4);
    TreeNode *pN7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pN1, pN2, pN3);
    ConnectTreeNodes(pN2, pN4, pN5);
    ConnectTreeNodes(pN5, pN6, pN7);

    levelOrder(pN1);
    Mirror(pN1);
    levelOrder(pN1);
    return 0;
}