#include "../Utils/LinkedTemplate.cpp"

ListNode *EntryNodeOfLoop(ListNode *pHead)
{
    if (!pHead)
        return nullptr;
    ListNode *pFast = pHead;
    ListNode *pLow = pHead;
    while (pFast && pFast->next)
    {
        pFast = pFast->next->next;
        pLow = pLow->next;
        if (pFast == pLow)
            break;
    }
    if (!pFast || !pFast->next)
        return nullptr;
    pLow = pHead;
    while (pFast != pLow)
    {
        pFast = pFast->next;
        pLow = pLow->next;
    }
    return pLow;
}

int main(int argc, char *argv[])
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);
    ListNode *pNode6 = CreateListNode(6);
    ListNode *pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode6);
    // PrintList(pNode1);
    ListNode *pFind = nullptr;
    pFind = EntryNodeOfLoop(pNode1);
    if (pFind)
    {
        std::cout << "Entry Node is:  " << pFind->val << std::endl;
    }
    else
    {
        std::cout << "No Loop Finded!" << std::endl;
    }

    DestroyList(pNode1);
    return 0;
}
