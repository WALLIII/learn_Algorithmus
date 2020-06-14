#include "../Utils/TreeTemplate.cpp"

void DFSFindPath(TreeNode *root, int rest, std::vector<std::vector<int>> &path, std::vector<int> &res)
{
    rest = rest - (root->val);
    res.push_back(root->val);
    for (auto a : res)
    {
        std::cout << a << "  ";
    }
    std::cout << std::endl;
    if (root->left == nullptr && root->right == nullptr)
    {
        if (rest == 0)
        {
            path.push_back(res);
        }
    }
    if (root->left != nullptr)
    {
        DFSFindPath(root->left, rest, path, res);
    }
    if (root->right != nullptr)
    {
        DFSFindPath(root->right, rest, path, res);
    }

    res.pop_back();
}

std::vector<std::vector<int>> FindPath(TreeNode *root, int expectNumber)
{
    std::vector<std::vector<int>> path;
    std::vector<int> res;
    if (root)
    {
        DFSFindPath(root, expectNumber, path, res);
    }
    return path;
}


// vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
//     stack<TreeNode*> s;
//     vector<int> v;
//     vector<vector<int> > res;
//     while (root || !s.empty()){
//         while (root){
//             s.push(root); v.push_back(root->val); expectNumber -= root->val;
//             //能左就左，否则向右
//             root = root->left ? root->left : root->right;
//         }
//         root = s.top();
//         if (expectNumber == 0 && root->left == NULL && root->right == NULL)
//             res.push_back(v);
//         s.pop(); v.pop_back(); expectNumber += root->val;
//         //右子数没遍历就遍历，如果遍历就强迫出栈
//         if (!s.empty() && s.top()->left == root)
//             root = s.top()->right;
//         else
//             root = NULL;//强迫出栈
//     }
//     return res;
// }

int main()
{
    TreeNode *pNa = CreateBinaryTreeNode(1);
    TreeNode *pNb = CreateBinaryTreeNode(-2);
    TreeNode *pNc = CreateBinaryTreeNode(-3);
    TreeNode *pNd = CreateBinaryTreeNode(1);
    TreeNode *pNe = CreateBinaryTreeNode(3);
    TreeNode *pNf = CreateBinaryTreeNode(-2);
    TreeNode *pNg = CreateBinaryTreeNode(-1);

    ConnectTreeNodes(pNa, pNb, pNc);
    ConnectTreeNodes(pNb, pNd, pNe);
    ConnectTreeNodes(pNc, pNf, nullptr);
    ConnectTreeNodes(pNd, pNg, nullptr);
    std::vector<std::vector<int>> path;
    path = FindPath(pNa, -1);
    if (path.size() > 0)
    {
        for (auto res : path)
        {
            for (auto a : res)
            {
                std::cout << a << "  ";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "no path finded!!" << std::endl;
    }
    DestroyTree(pNa);
    return 0;
}