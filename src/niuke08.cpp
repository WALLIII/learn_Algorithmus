#include <vector>
#include <iostream>

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};

TreeLinkNode* CreateBinaryTreeNode(int value)
{
    TreeLinkNode* pNode = new TreeLinkNode(value);
    pNode->val = value;
    pNode->left = nullptr;
    pNode->right = nullptr;
    pNode->next = nullptr;

    return pNode;
}

void ConnectTreeNodes(TreeLinkNode* pParent, TreeLinkNode* pLeft, TreeLinkNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->left = pLeft;
        pParent->right = pRight;

        if(pLeft != nullptr)
            pLeft->next = pParent;
        if(pRight != nullptr)
            pRight->next = pParent;
    }
}

TreeLinkNode *GetNext(TreeLinkNode *pNode)
{
    if (pNode == nullptr)
    {
        return nullptr;
    }
    TreeLinkNode *pNext = nullptr;
    if (pNode->right != nullptr)
    {
        TreeLinkNode *pNext = pNode->right;
        while (pNext->left != nullptr)
        {
            pNext = pNext->left;
        }
        return pNext;
    }
    while (pNode->next != nullptr)
    {
        TreeLinkNode *pParent = pNode->next;
        if (pParent->left == pNode)
        {
            return pParent;
        }
        pNode=pNode->next;
    }
    return nullptr;
}



int main(){
    TreeLinkNode* pNode8 = CreateBinaryTreeNode(8);
    TreeLinkNode* pNode6 = CreateBinaryTreeNode(6);
    TreeLinkNode* pNode10 = CreateBinaryTreeNode(10);
    TreeLinkNode* pNode5 = CreateBinaryTreeNode(5);
    TreeLinkNode* pNode7 = CreateBinaryTreeNode(7);
    TreeLinkNode* pNode9 = CreateBinaryTreeNode(9);
    TreeLinkNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    TreeLinkNode *pTestNode=GetNext(pNode8);
    std::cout<<"--->next node of node8 is: "<<pTestNode->val<<std::endl;
    return 0;

}