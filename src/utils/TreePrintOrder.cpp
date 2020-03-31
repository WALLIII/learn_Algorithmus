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
// Preorder traversal sequence recursively
void preOrder(TreeNode *root){
    if(root){
        std::cout<<root->val<<"   ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
// Preorder traversal sequence iteratively
std::vector<int> preOrder1(TreeNode *root)
{
    std::vector<int> result;
    if (root == NULL)
    {
        return result;
    }
    std::stack<TreeNode *> nstack;
    nstack.push(root);
    while (!nstack.empty())
    {
        TreeNode *temp = nstack.top();
        result.push_back(temp->val);
        nstack.pop();
        if (temp->right)
        {
            nstack.push(temp->right);
        }
        if (temp->left)
        {
            nstack.push(temp->left);
        }
    }
    return result;
}

// Inorder traversal sequence recursively
void inOrder(TreeNode *root){
    if(root){
        inOrder(root->left);
        std::cout<<root->val<<"   ";
        inOrder(root->right);
    }
}
// Inorder traversal sequence iteratively
std::vector<int> inOrder1(TreeNode *root){
    std::stack<TreeNode *> nstack;
    std::vector<int> result;
    if(!root)
        return result;
    TreeNode *temp=root;
    while(temp||!nstack.empty()){
        if(temp){
            nstack.push(temp);
            temp=temp->left;
        }
        else{
            temp=nstack.top();
            result.push_back(temp->val);
            nstack.pop();
            temp=temp->right;
        }
    }
    return result;
}

// Post-order traversal sequence recursively
void postOrder(TreeNode *root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        std::cout<<root->val<<"   ";
    }
}

// Post-order traversal sequence iteratively
std::vector<int> posOrder1(TreeNode *root){
    std::vector<int> result;
    if(root==NULL)
        return result;
    std::stack<TreeNode *> nstack1, nstack2;
    nstack1.push(root);
    while (!nstack1.empty()){
        TreeNode *temp=nstack1.top();
        nstack1.pop();
        nstack2.push(temp);
        if(temp->left)
            nstack1.push(temp->left);
        if(temp->right)
           nstack1.push(temp->right);
    }
    while(!nstack2.empty())
    {
        std::cout<<nstack2.top()->val;
        nstack2.pop();
    }
    return result;
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

    DestroyTree(pNa);
    return 0;
}