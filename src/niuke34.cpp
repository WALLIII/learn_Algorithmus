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
void DFSFindPath(TreeNode *root, 
                int rest, 
                std::vector<std::vector<int>> &path, 
                std::vector<int> &res)
{
    rest-=root->val;
    res.push_back(root->val);
    if(root->left==nullptr && root->right==nullptr){
        if(rest==0){
            path.push_back(res);
        }
    }
    // if(rest!=0&&!root->left) ---> worry, why?
    if(rest!=0&&root->left!=nullptr){
        DFSFindPath(root->left, rest, path, res);

    }
    if(rest!=0&&root->right!=nullptr){
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
    TreeNode *pNa = CreateBinaryTreeNode(10);
    TreeNode *pNb = CreateBinaryTreeNode(5);
    TreeNode *pNc = CreateBinaryTreeNode(12);
    TreeNode *pNd = CreateBinaryTreeNode(4);
    TreeNode *pNe = CreateBinaryTreeNode(7);
    // TreeNode *pNf = CreateBinaryTreeNode(9);
    // TreeNode *pNg = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNa, pNb, pNc);
    ConnectTreeNodes(pNb, pNd, pNe);
    // ConnectTreeNodes(pNc, pNf, pNg);
    std::vector<std::vector<int>> path;
    path = FindPath(pNa, 22);
    if(path.size()>0){
        for(auto res: path){
            for(auto a: res){
                std::cout<<a<<"  ";
            }
            std::cout<<std::endl;
        }
    }
    else{
        std::cout<<"no path finded!!"<<std::endl;
    }
    DestroyTree(pNa);
    return 0;
}