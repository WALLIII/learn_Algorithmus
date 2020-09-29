#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include "../Utils/TreeTemplate.cpp"
using namespace std;

bool verifyPreorder(vector<int> pre, int s, int e)
{
    if(s>=e)
        return true;
    // 从后向前找到第一个小于start位置的元素
    int i=e;
    while(i>=s&&pre[i]>pre[s])
        --i;
    //现在i指向了从后往前第一个小于pre[s]的元素,如果没有左儿子，i=s
    //要判断s~i之间的元素是不是都有大于pre[s]的，如果有就不对了
    for(int j=s;j<=i;++j){
        if(pre[j]>pre[s])
            return false;
    }
    return verifyPreorder(pre, s+1, i) && verifyPreorder(pre, i+1, e);    
}

bool verifyPreorder(vector<int> &preorder)
{
    if (preorder.empty())
        return true;
    return verifyPreorder(preorder, 0, preorder.size()-1);
}

int main()
{
    TreeNode *pNa = CreateBinaryTreeNode(5);
    TreeNode *pNb = CreateBinaryTreeNode(2);
    TreeNode *pNc = CreateBinaryTreeNode(6);
    TreeNode *pNd = CreateBinaryTreeNode(1);
    TreeNode *pNe = CreateBinaryTreeNode(3);

    ConnectTreeNodes(pNa, pNb, pNc);
    ConnectTreeNodes(pNb, pNd, pNe);

    std::vector<int> preOrder = {1,3,2};
    cout << verifyPreorder(preOrder) << endl;

    DestroyTree(pNa);
    return 0;
}