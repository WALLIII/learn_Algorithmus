#include <iostream>
#include <vector>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *reConstructBinaryTree(std::vector<int> pre, std::vector<int> vin)
{
    int inLength = vin.size();
    int preLength = pre.size();
    if (inLength == 0 || preLength == 0)
    {
        return nullptr;
    }
    std::vector<int> pre_left, in_left, pre_right, in_right;
    TreeNode *root = new TreeNode(pre[0]);
    int InRootIndex = 0;
    for (int i = 0; i < vin.size(); ++i)
    {
        if (vin[i] == pre[0])
        {
            InRootIndex = i;
            std::cout<<"root index: "<<InRootIndex<<"   ";
            std::cout<<"root value: "<<pre[0]<<"   "<<std::endl;

            break;
        }
    }
    for(int i =0;i<InRootIndex;++i){
        pre_left.push_back(pre[i+1]);
        in_left.push_back(vin[i]);
    }
    for(int i=InRootIndex+1;i<inLength;++i){
        pre_right.push_back(pre[i]);
        in_right.push_back(vin[i]);
    }
    std::cout<<"pre_left:  ";
    for (auto a :pre_left){
        std::cout<<a<<"  ";
    }
    std::cout<<std::endl;
    std::cout<<"in_left:  ";
    for (auto a :in_left){
        std::cout<<a<<"  ";
    }
    std::cout<<std::endl;
    std::cout<<"pre_right:  ";
    for (auto a :pre_right){
        std::cout<<a<<"  ";
    }
    std::cout<<std::endl;
    std::cout<<"in_right:  ";
    for (auto a :in_right){
        std::cout<<a<<"  ";
    }
    std::cout<<std::endl;
    root->left=reConstructBinaryTree(pre_left, in_left);
    root->right=reConstructBinaryTree(pre_right, in_right);
    return root;
}

int main()
{
    std::vector<int> preOrder = {1, 2, 4, 7, 3, 5, 6, 8};
    std::vector<int> inOrder = {4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode *pHead = nullptr;
    pHead = reConstructBinaryTree(preOrder, inOrder);
    return 0;
}