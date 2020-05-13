#include "../Utils/TreeTemplate.cpp"

// DFS+recursively
// int maxDepth(TreeNode *root)
// {
//     if(root==nullptr)
//         return 0;
//     int l=1+maxDepth(root->left);
//     int r=1+maxDepth(root->right);
//     return l>r?l:r;
// }
// DFS: iteratively
// int maxDepth(TreeNode *root)
// {
//     std::stack<pair<TreeNode *, int>> sk;
//     int max = 0;
//     int deep = 0 if (root == nullptr) return max;
//     TreeNode *curr = root;
//     //若栈非空，则说明还有一些节点的右子树尚未探索；若p非空，意味着还有一些节点的左子树尚未探索
//     while (curr || !sk.empty())
//     {
//         while (curr)//优先往左边走
//         {
//             sk.push(pair<TreeNode*, int>(curr, ++deep);
//             curr=curr->left;
//         }
//         curr = sk.top().first;//若左边无路，就预备右拐。右拐之前，记录右拐点的基本信息
//         deep = sk.top().second;
//         max = max > deep ? max : deep;//预备右拐时，比较当前节点深度和之前存储的最大深度
//         sk.pop();//将右拐点出栈；此时栈顶为右拐点的前一个结点。在右拐点的右子树全被遍历完后，会预备在这个节点右拐
//         curr = curr->right;
//     }
// }
// BFS
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    std::deque<TreeNode *> q;
    q.push_back(root);
    int deep = 0;
    while (!q.empty())
    {
        deep++;
        int num = q.size();
        for (int i = 1; i <= num; i++)
        {
            TreeNode *p = q.front();
            q.pop_front();
            if (p->left)
                q.push_back(p->left);
            if (p->right)
                q.push_back(p->right);
        }
    }
    return deep;
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
    std::cout << maxDepth(pNa) << std::endl;
    DestroyTree(pNa);
    return 0;
}