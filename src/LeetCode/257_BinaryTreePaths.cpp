#include "../Utils/TreeTemplate.cpp"

std::vector<std::string> binaryTreePaths(TreeNode *root)
{
    std::vector<std::string> ans;
    std::string str = "";
    if (root == nullptr)
        return ans;
    std::stack<std::pair<TreeNode *, std::string>> sk;
    TreeNode *curr = root;
    while (curr || !sk.empty())
    {
        while (curr)
        {
            if (curr == root)
            {
                str = str+std::to_string(curr->val);
            }
            else
            {
                str = str + "->" + std::to_string(curr->val);
            }
            sk.push(std::pair<TreeNode*, std::string>(curr, str));
            curr=curr->left;
        }
        curr=sk.top().first;
        str=sk.top().second;
        sk.pop();
        if(curr->left==nullptr && curr->right==nullptr){
   
            ans.push_back(str);
        }
        curr=curr->right;
    }
    
    return ans;
}
int main()
{
    TreeNode *pNa = CreateBinaryTreeNode(3);
    TreeNode *pNb = CreateBinaryTreeNode(5);
    TreeNode *pNc = CreateBinaryTreeNode(1);
    TreeNode *pNd = CreateBinaryTreeNode(6);
    TreeNode *pNe = CreateBinaryTreeNode(2);
    TreeNode *pNf = CreateBinaryTreeNode(7);
    TreeNode *pNg = CreateBinaryTreeNode(4);
    TreeNode *pNh = CreateBinaryTreeNode(0);
    TreeNode *pNi = CreateBinaryTreeNode(8);
    ConnectTreeNodes(pNa, pNb, pNc);
    ConnectTreeNodes(pNb, pNd, pNe);
    ConnectTreeNodes(pNc, pNh, pNi);
    ConnectTreeNodes(pNe, pNf, pNg);
    std::vector<std::string> ans;
    ans = binaryTreePaths(pNa);
   
    for (auto s : ans)
    {
        std::cout << s << std::endl;
    }
    DestroyTree(pNa);
    return 0;
}