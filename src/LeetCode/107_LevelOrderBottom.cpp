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

std::vector<std::vector<int>> levelOrderBottom(TreeNode *root)
{
    std::vector<std::vector<int> > ans;
    std::vector<int> tmp;
    TreeNode* pointer = root;
    if(!root)
        return ans;
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
        if(!tmp.empty())
            ans.push_back(tmp);
        tmp.clear();
        if(que.empty())
            break;
        que.push(nullptr);
    }
    std::reverse(ans.begin(), ans.end());

    return ans;
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
    std::vector<std::vector<int>> level;
    level = levelOrderBottom(pNa);
    for (auto vec : level)
    {
        for (auto a : vec)
        {
            std::cout << a << "   ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    DestroyTree(pNa);
    return 0;
}