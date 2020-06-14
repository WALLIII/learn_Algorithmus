#include "../Utils/TreeTemplate.cpp"

// std::vector<int> PrintFromTopToBottom(TreeNode *root)
// {
//     std::vector<int> res;
//     std::queue<TreeNode *> que;
//     if (!root)
//         return res;
//     que.push(root);
//     TreeNode *curr = root;
//     while (!que.empty())
//     {
//         curr = que.front();
//         res.push_back(curr->val);

//         if (curr->left)
//             que.push(curr->left);
//         if (curr->right)
//             que.push(curr->right);

//         que.pop();
//     }
//     return res;
// }

// 分行了
std::vector<std::vector<int>> PrintFromTopToBottom(TreeNode *root){
    std::vector<int> tmp;
    std::vector<std::vector<int>> ans;
    std::queue<TreeNode*> que;
    que.push(root);
    que.push(nullptr);
    while(!que.empty()){
        while(que.front()){
            TreeNode* curr=que.front();
            tmp.push_back(curr->val);
            if(curr->left!=nullptr)
                que.push(curr->left);
            if(curr->right!=nullptr)
                que.push(curr->right);
            que.pop();
        }
        que.pop();
        if(!tmp.empty())
            ans.push_back(tmp);
        tmp.clear();
        if(que.empty())
            break;
        que.push(nullptr);
    }
    return ans;
}
int main()
{
    TreeNode *pN1 = CreateBinaryTreeNode(8);
    TreeNode *pN2 = CreateBinaryTreeNode(6);
    TreeNode *pN3 = CreateBinaryTreeNode(10);
    TreeNode *pN4 = CreateBinaryTreeNode(5);
    TreeNode *pN5 = CreateBinaryTreeNode(7);
    TreeNode *pN6 = CreateBinaryTreeNode(9);
    TreeNode *pN7 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pN1, pN2, pN3);
    ConnectTreeNodes(pN2, pN4, pN5);
    ConnectTreeNodes(pN3, pN6, pN7);
    std::vector<std::vector<int>> res = PrintFromTopToBottom(pN1);
    for (auto line : res){
        for(auto a:line){
            std::cout << a << "   ";
        }
        std::cout<<std::endl;
    }
    DestroyTree(pN1);
    return 0;
}