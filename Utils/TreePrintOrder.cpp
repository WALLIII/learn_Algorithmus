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
void preOrder(TreeNode *root)
{
    if (root)
    {
        std::cout << root->val << "   ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
// Preorder traversal sequence iteratively
std::vector<int> preOrder1(TreeNode *root)
{
    std::stack<TreeNode *> nodes;
    std::vector<int> res;
    TreeNode *curr = root;
    while (curr || !nodes.empty())
    {
        while (curr)
        {
            nodes.push(curr->right);
            res.push_back(curr->val);
            curr = curr->left;
        }
        curr = nodes.top();
        nodes.pop();
    }
    return res;
}

// Inorder traversal sequence recursively
void inOrder(TreeNode *root)
{
    if (root)
    {
        inOrder(root->left);
        std::cout << root->val << "   ";
        inOrder(root->right);
    }
}
// Inorder traversal sequence iteratively
std::vector<int> inOrder1(TreeNode *root)
{
    std::stack<TreeNode *> sk;
    std::vector<int> result;
    if (!root)
        return result;
    TreeNode *curr = root;
    while (curr || !sk.empty())
    {
        if (curr)
        {
            sk.push(curr);
            curr = curr->left;
        }

        curr = sk.top();
        result.push_back(curr->val);
        sk.pop();
        curr = curr->right;
    }
    return result;
}

// Post-order traversal sequence recursively
void postOrder(TreeNode *root)
{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        std::cout << root->val << "   ";
    }
}

// Post-order traversal sequence iteratively
std::vector<int> postOrder(TreeNode *root)
{
    std::vector<int> v;
    if (root == nullptr)
        return v;
    std::stack<TreeNode *> sk;
    TreeNode *curr = root;
    TreeNode *pre = nullptr;
    while (curr || !sk.empty())
    {
        while (curr)
        {
            sk.push(curr);
            curr = curr->left;
        }
        curr = sk.top();
        // 如果没有右儿子或者右儿子已经被访问过了，这个时候可以放心的把当前节点打印出来
        if (curr->right == nullptr || curr->right == pre)
        {
            v.push_back(curr->val);
            sk.pop();
            // 然后把带那当前节点标记为pre，即已经访问过了
            pre = curr;
            curr = nullptr;
        }
        // 不然就访问它的右儿子
        else
            curr = curr->right;
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

    DestroyTree(pNa);
    return 0;
}