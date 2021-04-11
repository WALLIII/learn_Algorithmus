#include <vector>
#include <iostream>
#include <stack>
#include "../Utils/TreeTemplate.cpp"

using namespace std;
bool isSameTree(TreeNode *s, TreeNode *t)
{
    if (s == nullptr && t == nullptr)
        return true;
    if (s == nullptr || t == nullptr)
        return false;#include <vector>
#include <iostream>
#include <stack>
#include "../Utils/TreeTemplate.cpp"

using namespace std;
bool isSameTree(TreeNode *s, TreeNode *t)
{
    if (s == nullptr && t == nullptr)
        return true;
    if (s == nullptr || t == nullptr)
        return false;
    if (s->val != t->val)
        return false;
    return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}
bool isSubtree(TreeNode *s, TreeNode *t)
{
    if (s == nullptr && t == nullptr)
        return true;
    if (s == nullptr || t == nullptr)
        return false;
    return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}
int main()
{
    TreeNode *pN1 = CreateBinaryTreeNode(3);
    TreeNode *pN2 = CreateBinaryTreeNode(4);
    TreeNode *pN3 = CreateBinaryTreeNode(5);
    TreeNode *pN4 = CreateBinaryTreeNode(1);
    TreeNode *pN5 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pN1, pN2, pN3);
    ConnectTreeNodes(pN2, pN4, pN5);

    TreeNode *pN11 = CreateBinaryTreeNode(5);
    TreeNode *pN12 = CreateBinaryTreeNode(1);
    TreeNode *pN13 = CreateBinaryTreeNode(2);
    ConnectTreeNodes(pN11, pN12, pN13);

    cout << isSubtree(pN1, pN11) << endl;
    DestroyTree(pN1);
    return 0;
}
    if (s->val != t->val)
        return false;
    return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}
bool isSubtree(TreeNode *s, TreeNode *t)
{
    if (s == nullptr && t == nullptr)
        return true;
    if (s == nullptr || t == nullptr)
        return false;
    return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}
int main()
{
    TreeNode *pN1 = CreateBinaryTreeNode(3);
    TreeNode *pN2 = CreateBinaryTreeNode(4);
    TreeNode *pN3 = CreateBinaryTreeNode(5);
    TreeNode *pN4 = CreateBinaryTreeNode(1);
    TreeNode *pN5 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pN1, pN2, pN3);
    ConnectTreeNodes(pN2, pN4, pN5);

    TreeNode *pN11 = CreateBinaryTreeNode(5);
    TreeNode *pN12 = CreateBinaryTreeNode(1);
    TreeNode *pN13 = CreateBinaryTreeNode(2);
    ConnectTreeNodes(pN11, pN12, pN13);

    cout << isSubtree(pN1, pN11) << endl;
    DestroyTree(pN1);
    return 0;
}