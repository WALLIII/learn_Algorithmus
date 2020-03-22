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

ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
{
    if (!pHead1)
    {
        std::cout << "linked 1 is empty, return linked 2" << std::endl;
        return pHead2;
    }
    if (!pHead2)
    {
        std::cout << "linked 2 is empty, return linked 1" << std::endl;
        return pHead1;
    }
    ListNode *pNewHead = nullptr;
    if (pHead1->val < pHead2->val)
    {
        pNewHead = pHead1;
        pHead1 = pHead1->next;
    }
    else
    {
        pNewHead = pHead2;
        pHead2 = pHead2->next;
    }
    ListNode *pNewNode = pNewHead;
    while (pHead1 && pHead2)
    {
        if(pHead1->val<pHead2->val){
            pNewNode->next=pHead1;
            pHead1=pHead1->next;
            pNewNode=pNewNode->next;
        }
        else{
            pNewNode->next=pHead2;
            pHead2=pHead2->next;
            pNewNode=pNewNode->next;
        }

    }
    if(!pHead1){
        pNewNode->next=pHead2;
    }
    if(!pHead2){
        pNewNode->next=pHead1;
    }
    return pNewHead;
}

int main(int argc, char *argv[])
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(3);
    ListNode *pNode3 = CreateListNode(5);
    ListNode *pNode4 = CreateListNode(8);

    ListNode *pN1 = CreateListNode(2);
    ListNode *pN2 = CreateListNode(4);
    ListNode *pN3 = CreateListNode(6);
    ListNode *pN4 = CreateListNode(7);




    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pN1, pN2);
    ConnectListNodes(pN2, pN3);
    ConnectListNodes(pN3, pN4);
  

    PrintList(pNode1);
    PrintList(pN1);

    ListNode *pNew = nullptr;
    pNew = Merge(nullptr, pN1);

    PrintList(pNew);

    DestroyList(pNew);
    return 0;
}
