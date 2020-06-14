#include "../Utils/TreeTemplate.cpp"

// TreeNode *invertTree(TreeNode *root)
// { //先序优先遍历
//     if (root == NULL)
//         return root;
//     TreeNode *temp = root->left;
//     root->left = root->right;
//     root->right = temp;
//     invertTree(root->left);
//     invertTree(root->right);
//     return root;
// }

// TreeNode *invertTree(TreeNode *root)
// { //后序优先遍历
//     if (root == NULL)
//         return root;
//     invertTree(root->left);
//     invertTree(root->right);
//     TreeNode *temp = root->left;
//     root->left = root->right;
//     root->right = temp;
//     return root;
// }

// TreeNode *invertTree(TreeNode *root)
// { //中序优先遍历
//     if (root == NULL)
//         return root;
//     invertTree(root->left);
//     TreeNode *temp = root->left;
//     root->left = root->right;
//     root->right = temp;
//     invertTree(root->left);
//     return root;
// }

void swapChild(TreeNode *current)
{
    //先把根节点的左右翻转
    TreeNode *temp = current->left;
    current->left = current->right;
    current->right = temp;
}
TreeNode *invertTree(TreeNode *root)
{
    TreeNode *current = root;
    //利用栈来保存其还没翻转的子树
    std::stack<TreeNode *> stack;
    while (current || stack.size())
    {
        //利用栈的中序遍历
        while (current)
        {
            stack.push(current);
            current = current->left;
        }
        current = stack.top();
        stack.pop();
        swapChild(current);
        current = current->left; //传统的中序遍历这里应该是right，但是其实前面交换过左右孩子结点，所以这里应该是left
    }
    return root;
}
int main()
{
    TreeNode *pN1 = CreateBinaryTreeNode(4);
    TreeNode *pN2 = CreateBinaryTreeNode(2);
    TreeNode *pN3 = CreateBinaryTreeNode(7);
    TreeNode *pN4 = CreateBinaryTreeNode(1);
    TreeNode *pN5 = CreateBinaryTreeNode(3);
    TreeNode *pN6 = CreateBinaryTreeNode(6);
    TreeNode *pN7 = CreateBinaryTreeNode(9);

    ConnectTreeNodes(pN1, pN2, pN3);
    ConnectTreeNodes(pN2, pN4, pN5);
    ConnectTreeNodes(pN3, pN6, pN7);

    DestroyTree(pN1);
    return 0;
}