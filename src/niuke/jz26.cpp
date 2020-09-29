#include "../Utils/TreeTemplate.cpp"

// void helper(TreeNode *curr, TreeNode *&pre)
// {
//     if (curr==nullptr)
//         return;
//     helper(curr->left, pre);
//     curr->left = pre;
//     if (pre)
//         pre->right = curr;
//     pre = curr;
//     helper(curr->right, pre);
// }
// TreeNode *Convert(TreeNode *pRootOfTree)
// {
//     if (pRootOfTree == nullptr)
//         return nullptr;
//     TreeNode *pre = nullptr;
//     helper(pRootOfTree, pre);
//     TreeNode *res = pRootOfTree;
//     while (res->left)
//         res = res->left;
//     return res;
// }
TreeNode *Convert(TreeNode *pRootOfTree){
    if(!pRootOfTree)
        return nullptr;
    std::stack<TreeNode*> sk;
    TreeNode* curr=pRootOfTree;
    TreeNode* pre=nullptr;
    while(!sk.empty()||curr){
        while(curr){
            sk.push(curr);
            curr=curr->left;
        }
        curr=sk.top();
        sk.pop();
        curr->left=pre;
        if(pre)
            pre->right=curr;
        pre=curr;
        curr=curr->right;
    }
    curr=pRootOfTree;
    while(curr->left)
        curr=curr->left;
    return curr;
}

int main()
{
    TreeNode *pN1 = CreateBinaryTreeNode(10);
    TreeNode *pN2 = CreateBinaryTreeNode(6);
    TreeNode *pN3 = CreateBinaryTreeNode(14);
    TreeNode *pN4 = CreateBinaryTreeNode(4);
    TreeNode *pN5 = CreateBinaryTreeNode(8);
    TreeNode *pN6 = CreateBinaryTreeNode(12);
    TreeNode *pN7 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pN1, pN2, pN3);
    ConnectTreeNodes(pN2, pN4, pN5);
    ConnectTreeNodes(pN3, pN6, pN7);
    TreeNode *res = Convert(pN1);
    TreeNode *curr = res;
    while (curr->right)
    {
        std::cout << curr->val << "   ";
        curr = curr->right;
        if(curr->right==nullptr)
            std::cout << curr->val << "   ";
    }
    std::cout << std::endl;
    while (curr)
    {
        std::cout << curr->val << "   ";
        curr = curr->left;
    }
    // DestroyTree(pN1);
    return 0;
}