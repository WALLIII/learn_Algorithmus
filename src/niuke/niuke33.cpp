#include "../Utils/TreeTemplate.cpp"

// bool VerifySquenceOfBST(std::vector<int> sequence)
// {
//     if(sequence.empty())
//         return false;
//     int size=sequence.size();
//     std::vector<int> LeftTree;
//     std::vector<int> RightTree;
//     int i=0;
//     for(i=0;i<size-1;++i){
//         if(sequence[i]<sequence[size-1])
//             LeftTree.push_back(sequence[i]);
//         else
//             break;
//     }
//     for(int j=i;j<size-1;++j){
//         if(sequence[j]>sequence[size-1])
//             RightTree.push_back(sequence[j]);
//         else
//             return false;
//     }
//     bool left=true;
//     if(!LeftTree.empty())
//         left=VerifySquenceOfBST(LeftTree);
//     bool right=true;
//     if(!RightTree.empty())
//         right=VerifySquenceOfBST(RightTree);
//     return (left&&right);
// }

bool VerifySquenceOfBST(std::vector<int> sequence){
    int size=sequence.size()-1;
    if(size<=-1)
        return false;
    int i=0;
    while(size){
        while(sequence[i]<sequence[size])
            ++i;
        while(sequence[i]>sequence[size])
            ++i;
        if(i<size)
            return false;
        i=0;
        --size;
    }
    return true;
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
    std::vector<int> postOrder = {5, 7, 6, 9, 11, 10, 8};
    // std::vector<int> postOrder = {7,4,6,5};
    if (VerifySquenceOfBST(postOrder))
        std::cout << "true.." << std::endl;
    else
        std::cout << "false.." << std::endl;

    DestroyTree(pN1);
    return 0;
}