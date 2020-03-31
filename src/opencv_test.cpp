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

std::vector<int> PrintFromTopToBottom(TreeNode *root)
{
    std::vector<int> res;
    if (!root)
        return res;
    std::queue<TreeNode *> que;
    que.push(root);

    while (!que.empty())
    {
        TreeNode *tmp = que.front();

        res.push_back(tmp->val);

        que.pop();
        if (tmp->left)
        {
            que.push(tmp->left);
        }

        if (tmp->right)
        {
            que.push(tmp->right);
        }
    }
    return res;
}

std::vector<std::vector<int>> PrintFromTopToBottom_line_by_line(TreeNode *root)
{
    std::vector<int> line;
    std::vector<std::vector<int>> result;
    if (!root)
        return result;
    std::queue<TreeNode *> que;
    que.push(root);
    int flag = 0;
    int toBePrint = 1;
    while (!que.empty())
    {
        TreeNode *tmp = que.front();

        line.push_back(tmp->val);

        que.pop();
        if (tmp->left)
        {
            que.push(tmp->left);
            flag++;
        }
        if (tmp->right)
        {
            que.push(tmp->right);
            flag++;
        }
        --toBePrint;
        if (toBePrint == 0)
        {
            result.push_back(line);
            line.clear();
            toBePrint = flag;
            flag = 0;
        }
    }
    return result;
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

    std::vector<std::vector<int>> result_line;

    result_line = PrintFromTopToBottom_line_by_line(pNa);

    std::cout << "PrintFromTopToBottom_line_by_line:  " << std::endl;
    for (auto line : result_line)
    {
        for (auto a : line)
            std::cout << a << "   ";
        std::cout << std::endl;
    }

    DestroyTree(pNa);
    return 0;
}