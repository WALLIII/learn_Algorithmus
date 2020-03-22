#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *CreateListNode(int value)
{
    ListNode *pNode = new ListNode(0);
    pNode->val = value;
    pNode->next = nullptr;

    return pNode;
}

void ConnectListNodes(ListNode *pCurrent, ListNode *pNext)
{
    if (pCurrent == nullptr)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }
    pCurrent->next = pNext;
}
void DestroyList(ListNode *pHead)
{
    ListNode *pNode = pHead;
    while (pNode != nullptr)
    {
        pHead = pHead->next;
        delete pNode;
        pNode = pHead;
    }
}
void AddToTail(ListNode **pHead, int value)
{
    ListNode *pNew = new ListNode(0);
    pNew->val = value;
    pNew->next = nullptr;
    if (*pHead == nullptr)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode *pNode = *pHead;
        while (pNode->next != nullptr)
        {
            pNode = pNode->next;
        }
        pNode->next = pNew;
    }
}

void PrintList(ListNode *pHead)
{
    printf("PrintList starts.\n");

    ListNode *pNode = pHead;
    while (pNode != nullptr)
    {
        printf("%d\t", pNode->val);
        pNode = pNode->next;
    }

    printf("\nPrintList ends.\n");
}

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
