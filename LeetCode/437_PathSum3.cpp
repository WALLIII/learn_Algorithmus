#include "../Utils/TreeTemplate.cpp"

// int helper(TreeNode *root, int sum)
// {
//     if (root== NULL)
//         return 0;
//     sum -= root->val;
//     return (sum == 0 ? 1 : 0) + helper(root->left, sum) + helper(root->right, sum);
// }

// int pathSum(TreeNode *root, int sum)
// {
//     if (root== NULL)
//         return 0;
//     return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
// }


// int helper(TreeNode *root, int sum, std::vector<int> &path)
// {
//     if(!root)
//         return 0;
//     path.push_back(root->val);
//     int res=0, currSum=0;
//     for(int i=path.size()-1;i>=0;--i){
//         currSum+=path[i];
//         if(currSum==sum)
//             res++;
//     }
//     res+=helper(root->left, sum, path)+helper(root->right, sum, path);
//     path.pop_back();
//     return res;
// }
// int pathSum(TreeNode *root, int sum)
// {
//     std::vector<int> path;
//     return helper(root, sum, path);
// }
int pathSum(TreeNode *root, int sum){
    if(!root)
        return 0;
    std::pair<TreeNode*, std::vector<int>> temp;
    std::stack<std::pair<TreeNode*, std::vector<int>>> sk;
    std::vector<int> path;
    path.push_back(root->val);
    sk.push(make_pair(root, path));
    TreeNode* right, *left;
    int res=0;
    int currSum=0;
    while(!sk.empty()){
        temp=sk.top();
        sk.pop();
        currSum=0;
        for(int i=temp.second.size()-1;i>=0;--i){
            currSum+=temp.second[i];
            if(currSum==sum)
                res++;
        }
        left=temp.first->left;
        right=temp.first->right;
        if(left!=nullptr){
            temp.second.push_back(left->val);
            sk.push(std::make_pair(left, temp.second));
            temp.second.pop_back();
        }
        if(right!=nullptr){
            temp.second.push_back(right->val);
            sk.push(std::make_pair(right, temp.second));
            temp.second.pop_back();
        }
    }
    return res;
}

int main()
{
    TreeNode *pNa = CreateBinaryTreeNode(10);
    TreeNode *pNb = CreateBinaryTreeNode(5);
    TreeNode *pNc = CreateBinaryTreeNode(-3);
    TreeNode *pNd = CreateBinaryTreeNode(3);
    TreeNode *pNe = CreateBinaryTreeNode(2);
    TreeNode *pNf = CreateBinaryTreeNode(11);
    TreeNode *pNg = CreateBinaryTreeNode(3);
    TreeNode *pNh = CreateBinaryTreeNode(-2);
    TreeNode *pNi = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNa, pNb, pNc);
    ConnectTreeNodes(pNb, pNd, pNe);
    ConnectTreeNodes(pNc, nullptr, pNf);
    ConnectTreeNodes(pNd, pNg, pNh);
    ConnectTreeNodes(pNe, nullptr, pNi);
    std::cout << pathSum(pNa, 8) << std::endl;
    DestroyTree(pNa);
    return 0;
}