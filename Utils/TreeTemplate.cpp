#include <vector>
#include <iostream>
#include <stack>
#include <queue>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *next;
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};

TreeNode *CreateBinaryTreeNode(int value)
{
    TreeNode *pNode = new TreeNode(value);
    pNode->val = value;
    pNode->left = nullptr;
    pNode->right = nullptr;
    pNode->next = nullptr;

    return pNode;
}

void ConnectTreeNodes(TreeNode *pParent, TreeNode *pLeft, TreeNode *pRight)
{
    if (pParent != nullptr)
    {
        pParent->left = pLeft;
        pParent->right = pRight;

        if (pLeft != nullptr)
            pLeft->next = pParent;
        if (pRight != nullptr)
            pRight->next = pParent;
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

void levelOrder(TreeNode *root)
{
    std::vector<int> tmp;
    TreeNode* pointer = root;
    if(!root)
        return;
    std::queue<TreeNode *> que;
    que.push(root);
    que.push(nullptr);
    while(!que.empty()){
        while(que.front()){
            pointer=que.front();
            if(pointer->left)
                que.push(pointer->left);
            if(pointer->right)
                que.push(pointer->right);
            que.pop();
            tmp.push_back(pointer->val);
        }
        que.pop();  //delete nullptr
        if(!tmp.empty()){
            for(auto a:tmp)
                std::cout<<a<<"  ";
        }
        std::cout<<std::endl;            
        tmp.clear();
        if(que.empty())
            break;
        que.push(nullptr);
    }
}

// int main()
// {
//     TreeNode *pN1 = CreateBinaryTreeNode(8);
//     TreeNode *pN2 = CreateBinaryTreeNode(6);
//     TreeNode *pN3 = CreateBinaryTreeNode(10);
//     TreeNode *pN4 = CreateBinaryTreeNode(5);
//     TreeNode *pN5 = CreateBinaryTreeNode(7);
//     TreeNode *pN6 = CreateBinaryTreeNode(9);
//     TreeNode *pN7 = CreateBinaryTreeNode(11);

//     ConnectTreeNodes(pN1, pN2, pN3);
//     ConnectTreeNodes(pN2, pN4, pN5);
//     ConnectTreeNodes(pN3, pN6, pN7);

//     DestroyTree(pN1);
//     return 0;
// }