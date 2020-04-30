#include <vector>
#include <iostream>
#include <stack>
#include <queue>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

TreeNode *CreateBinaryTreeNode(int value)
{
    TreeNode *pNode = new TreeNode(value);
    pNode->val = value;
    pNode->left = nullptr;
    pNode->right = nullptr;

    return pNode;
}

void ConnectTreeNodes(TreeNode *pParent, TreeNode *pLeft, TreeNode *pRight)
{
    if (pParent != nullptr)
    {
        pParent->left = pLeft;
        pParent->right = pRight;
    }
}

void DestroyTree(TreeNode *pRoot)
{
    if (pRoot != nullptr)
    {
        TreeNode *pLeft = pRoot->left;
        TreeNode *pRight = pRoot->right;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

// void postorderTraversal(TreeNode *root, std::vector<int> &PostOrder)
// {
//     if (!root)
//         return;
//     postorderTraversal(root->left, PostOrder);
//     postorderTraversal(root->right, PostOrder);
//     PostOrder.push_back(root->val);
// }
// std::vector<int> postorderTraversal(TreeNode *root)
// {
//     std::vector<int> PostOrder;
//     if (!root)
//         return PostOrder;
//     postorderTraversal(root, PostOrder);
//     return PostOrder;
// }

std::vector<int> postorderTraversal(TreeNode *root)
{
    std::vector<int> v;
    if(root==nullptr)
        return v;
    std::stack<TreeNode*> s;
    TreeNode *cur=root;
    TreeNode *pre=nullptr; 
    while(cur || !s.empty()){
        while(cur){
            s.push(cur);
            cur=cur->left;
        }
        cur=s.top();
        if(cur->right==nullptr || cur->right==pre){
            v.push_back(cur->val);
            s.pop();
            pre=cur;
            cur=nullptr;
        }
        else
            cur=cur->right;
    }
    return v;
}
int main()
{
    TreeNode *pNa = CreateBinaryTreeNode(8);
    TreeNode *pNb = CreateBinaryTreeNode(6);
    TreeNode *pNc = CreateBinaryTreeNode(10);
    TreeNode *pNd = CreateBinaryTreeNode(5);
    TreeNode *pNe = CreateBinaryTreeNode(7);
    TreeNode *pNf = CreateBinaryTreeNode(9);
    TreeNode *pNg = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNa, pNb, pNc);
    ConnectTreeNodes(pNb, pNd, pNe);
    ConnectTreeNodes(pNc, pNf, pNg);

    std::vector<int> preOrder;
    preOrder = postorderTraversal(pNa);
    for (auto a : preOrder)
        std::cout << a << "   ";
    std::cout << std::endl;

    DestroyTree(pNa);
    return 0;
}