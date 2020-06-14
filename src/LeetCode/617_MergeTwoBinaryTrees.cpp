#include "../Utils/TreeTemplate.cpp"

void inorderTraversal(TreeNode *root)
{
    std::vector<int> ans;
    if (root == nullptr)
        return;
    std::stack<TreeNode *> st;
    // st.push(root);
    TreeNode *curr = root;
    while (!st.empty() || curr)
    {
        // curr=st.top();
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        ans.push_back(curr->val);
        st.pop();
        curr = curr->right;
    }
    for (auto a : ans)
        std::cout << a << "  ";
    std::cout << std::endl;
}
// TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
// {

//     if (!t1 && !t2)
//         return nullptr;
//     if (!t1)
//         return t2;
//     if (!t2)
//         return t1;
//     else
//     {
//         t1->val += t2->val;
//         t1->left = mergeTrees(t1->left, t2->left);
//         t1->right = mergeTrees(t1->right, t2->right);

//         return t1;
//     }
// }
TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
{
    if (!t1)
        return t2;
    if (!t2)
        return t1;
    std::stack<std::pair<TreeNode *, TreeNode *>> node_stack;
    node_stack.push(std::make_pair(t1, t2));
    while (!node_stack.empty())
    {
        TreeNode *t_1 = node_stack.top().first;
        TreeNode *t_2 = node_stack.top().second;
        node_stack.pop();
        t_1->val += t_2->val;
        //判断左子树是否存在
        if (t_1->left && t_2->left)
            node_stack.push(std::make_pair(t_1->left, t_2->left));
        if (!t_1->left)
            t_1->left = t_2->left;
        //判断右子树是否存在
        if (t_1->right && t_2->right)
            node_stack.push(std::make_pair(t_1->right, t_2->right));
        if (!t_1->right)
            t_1->right = t_2->right;
    }
    return t1;
}
int main()
{
    TreeNode *pN11 = CreateBinaryTreeNode(1);
    TreeNode *pN12 = CreateBinaryTreeNode(3);
    TreeNode *pN13 = CreateBinaryTreeNode(2);
    TreeNode *pN14 = CreateBinaryTreeNode(5);

    TreeNode *pN21 = CreateBinaryTreeNode(2);
    TreeNode *pN22 = CreateBinaryTreeNode(1);
    TreeNode *pN23 = CreateBinaryTreeNode(3);
    TreeNode *pN24 = CreateBinaryTreeNode(4);
    TreeNode *pN25 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pN11, pN12, pN13);
    ConnectTreeNodes(pN12, pN14, nullptr);

    ConnectTreeNodes(pN21, pN22, pN23);
    ConnectTreeNodes(pN22, nullptr, pN24);
    ConnectTreeNodes(pN23, nullptr, pN25);
    // inorderTraversal(pN11);
    // inorderTraversal(pN21);

    pN11 = mergeTrees(pN11, pN22);
    inorderTraversal(pN11);

    // DestroyTree(pN11);
    return 0;
}