#include "../Utils/TreeTemplate.cpp"

int kthSmallest(TreeNode *root, int k)
{
    if(root==nullptr)
        return INT_MIN;
    
    std::vector<int> inOrder;
    std::stack<TreeNode*> sk;
    TreeNode* curr=root;
    while(curr||!sk.empty()){
        while(curr){
            sk.push(curr);
            curr=curr->left;
        }
        if(!sk.empty()){
            curr=sk.top();
            inOrder.push_back(curr->val);
            sk.pop();
            curr=curr->right;
        }
    }
    return inOrder[k-1];
}
int main()
{
    TreeNode *pNa = CreateBinaryTreeNode(5);
    TreeNode *pNb = CreateBinaryTreeNode(3);
    TreeNode *pNc = CreateBinaryTreeNode(6);
    TreeNode *pNd = CreateBinaryTreeNode(2);
    TreeNode *pNe = CreateBinaryTreeNode(4);
    TreeNode *pNf = CreateBinaryTreeNode(1);
    // TreeNode *pNg = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNa, pNb, pNc);
    ConnectTreeNodes(pNb, pNd, pNe);
    ConnectTreeNodes(pNd, pNf, nullptr);
    std::cout<<kthSmallest(pNa, 5)<<std::endl;
    DestroyTree(pNa);
    return 0;
}