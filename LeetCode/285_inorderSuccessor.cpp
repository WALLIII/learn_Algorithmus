#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include "../Utils/TreeTemplate.cpp"
using namespace std;

TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
{
    if (!root || !p)
        return nullptr;
    stack<TreeNode *> sk;
    TreeNode *curr = root;
    bool findEqual=false;
    while (curr || !sk.empty())
    {
        while(curr){
            sk.push(curr);
            curr=curr->left;
        }
        curr=sk.top();sk.pop();
        if(findEqual==true)
            return curr;
        // inorder.push_back(curr->val);
        if(curr->val == p->val){
            findEqual=true;
        }
        curr=curr->right;
       
    }
    return nullptr;
}
int main()
{
    TreeNode *pNa = CreateBinaryTreeNode(5);
    TreeNode *pNb = CreateBinaryTreeNode(3);
    TreeNode *pNc = CreateBinaryTreeNode(6);
    TreeNode *pNd = CreateBinaryTreeNode(2);
    TreeNode *pNe = CreateBinaryTreeNode(4);
    TreeNode *pNf = CreateBinaryTreeNode(1);

    TreeNode *test = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNa, pNb, pNc);
    ConnectTreeNodes(pNb, pNd, pNe);
    ConnectTreeNodes(pNd, pNf, nullptr);
    TreeNode *res = inorderSuccessor(pNa, test);
    if (res)
        cout << res->val << endl;
    else
        cout << "null" << endl;
    DestroyTree(pNa);
    return 0;
}