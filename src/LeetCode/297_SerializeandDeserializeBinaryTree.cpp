#include "../Utils/TreeTemplate.cpp"

// Encodes a tree to a single string.
std::string serialize(TreeNode *root)
{
    std::string ans = "";
    if (root == nullptr)
        return ans;
    std::queue<TreeNode *> que;
    TreeNode *curr = root;
    que.push(root);
    while (!que.empty())
    {
        curr = que.front();
        que.pop();
        if (curr)
        {
            ans += std::to_string(curr->val);
            ans += ",";
            que.push(curr->left);
            que.push(curr->right);
        }
        else
        {
            ans += "null,";
        }
    }
    return ans;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(std::string data)
{
    if (data.empty())
        return nullptr;
    int i = 0;
    std::string sub = "";
    int number = 0;
    std::queue<TreeNode *> que;
    TreeNode *root = new TreeNode(0);
    // 先把第一个数字取出来,遇到逗号停止，跳出循环时i指向逗号
    for (i = 0; (data[i] >= '0' && data[i] <= '9') || data[i] == '-'; ++i)
    {
    };
    // 如果是负数的话
    if (data[0] == '-')
    {
        sub = data.substr(1, i - 1);
        number = std::stoi(sub);
        data.erase(0, i + 1);
        root->val = -number;
    }
    else
    {
        sub = data.substr(0, i);
        number = std::stoi(sub);
        data.erase(0, i + 1);
        root->val = number;
    }
    que.push(root);
    while (!data.empty())
    {
        TreeNode *left = new TreeNode(0);
        TreeNode *right = new TreeNode(0);
        // 先处理左节点，方法跟根节点一样，但是需要考虑是否是null
        if (data[0] == 'n')
        {
            left = nullptr;
            data.erase(0, 5);
        }
        else
        {
            i = 0;
            for (i = 0; (data[i] >= '0' && data[i] <= '9') || data[i] == '-'; ++i)
            {
            };
            if (data[0] == '-')
            {
                sub = data.substr(1, i - 1);
                number = std::stoi(sub);
                data.erase(0, i + 1);
                left->val = -number;
                que.push(left);
            }
            else
            {
                sub = data.substr(0, i);
                number = std::stoi(sub);
                data.erase(0, i + 1);
                left->val = number;
                que.push(left);
            }
        }
        // 现在处理右节点
        if (data[0] == 'n')
        {
            right = nullptr;
            data.erase(0, 5);
        }
        else
        {
            i = 0;
            for (i = 0; (data[i] >= '0' && data[i] <= '9') || data[i] == '-'; ++i)
            {
            };
            if (data[0] == '-')
            {
                sub = data.substr(1, i - 1);
                number = std::stoi(sub);
                data.erase(0, i + 1);
                right->val = -number;
                que.push(right);
            }
            else
            {
                sub = data.substr(0, i);
                number = std::stoi(sub);
                data.erase(0, i + 1);
                right->val = number;
                que.push(right);
            }
        }
        TreeNode* temp=que.front();
        temp->left=left;
        temp->right=right;
        que.pop();
    }
    return root;
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
    std::string res = serialize(pN1);
    std::cout << res << std::endl;

    TreeNode *newHead = deserialize(res);
    levelOrder(newHead);
  
    DestroyTree(pN1);
    return 0;
}