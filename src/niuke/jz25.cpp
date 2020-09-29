#include "../Utils/RandomLinked.cpp"
#include <unordered_map>

RandomListNode *Clone(RandomListNode *pHead){
    if(pHead==nullptr)
        return nullptr;
    // key为链表的原节点，value为新创建的深拷贝节点
    std::unordered_map<RandomListNode*, RandomListNode*> mp;
    RandomListNode* curr=pHead;
    // 先遍历一遍链表，把原节点和深拷贝节点一一对应。
    while(curr){
        mp[curr]=new RandomListNode(curr->label);
        curr=curr->next;
    }
    // 再遍历一遍链表（利用哈希表）把深拷贝节点连接上
    curr=pHead;
    while(curr){
        if(curr->next){
            mp[curr]->next=mp[curr->next];
        }
        if(curr->random){
            mp[curr]->random=mp[curr->random];
        }
        curr=curr->next;
    }
    return mp[pHead];
}
// RandomListNode *Clone(RandomListNode *pHead)
// {
//     if (!pHead)
//         return nullptr;
//     RandomListNode *curr = pHead;
//     // 拷贝节点，并把拷贝的节点插入链表。
//     while (curr)
//     {
//         RandomListNode *pNew = new RandomListNode(curr->label);
//         pNew->next = curr->next;
//         curr->next = pNew;
//         curr = pNew->next;
//     }
//     curr = pHead;
//     // 给新拷贝节点补上random节点的信息
//     while (curr)
//     {
//         RandomListNode *copy = curr->next;
//         if (curr->random)
//         {
//             copy->random = curr->random->next;
//         }
//         curr = copy->next;
//     }
//     // 现在要断开链表，把原链表和拷贝链表分开.
//     RandomListNode *pCopyHead = pHead->next;
//     curr = pHead;
//     RandomListNode *tmp;
//     while (curr->next)
//     {
//         tmp = curr->next;
//         curr->next = tmp->next;
//         curr = tmp;
//     }
//     return pCopyHead;
// }
int main(int argc, char *argv[])
{
    RandomListNode *pNode1 = CreateListNode(1);
    RandomListNode *pNode2 = CreateListNode(2);
    RandomListNode *pNode3 = CreateListNode(3);
    RandomListNode *pNode4 = CreateListNode(4);
    RandomListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2, pNode3);
    ConnectListNodes(pNode2, pNode3, pNode5);
    ConnectListNodes(pNode3, pNode4, nullptr);
    ConnectListNodes(pNode4, pNode5, pNode2);
    std::cout << "print original list: " << std::endl;
    PrintList(pNode1);
    std::cout << std::endl;

    RandomListNode *pNewHead;
    pNewHead = Clone(pNode1);
    std::cout << "print duplicated list: " << std::endl;
    PrintList(pNewHead);
    std::cout << std::endl;

    DestroyList(pNode1);
    return 0;
}