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

ListNode *ReverseList(ListNode *pHead)
{
    if (!pHead)
        return nullptr;
    ListNode *pNewHead = nullptr;
    ListNode *pPrev = nullptr;
    ListNode *pNode = pHead;
    while (pNode)
    {
        ListNode *pNext = pNode->next;
        if (!pNext)
            pNewHead = pNode;
        pNode->next = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    return pNewHead;
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
    PrintList(pNode1);
    ListNode *pNewHead = nullptr;
    pNewHead = ReverseList(pNode1);
    if (pNewHead)
    {
        std::cout << "reversed list is: " << std::endl;
        PrintList(pNewHead);
    }
    else
    {
        std::cout << "error" << std::endl;
    }

    // DestroyList(pNode1);
    DestroyList(pNewHead);
    return 0;
}
