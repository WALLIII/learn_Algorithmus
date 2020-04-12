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

void PrintListNode(ListNode *pNode)
{
    if (pNode == nullptr)
    {
        printf("The node is nullptr\n");
    }
    else
    {
        printf("The key in node is %d.\n", pNode->val);
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
ListNode *walkStep(ListNode *pHead, int diffLength)
{
    for (int i = 0; i < diffLength; ++i)
    {
        pHead = pHead->next;
    }
    return pHead;
}
ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
    int len1 = 0, len2 = 0;
    ListNode *p1 = pHead1;
    ListNode *p2 = pHead2;

    while (p1)
    {
        ++len1;
        p1 = p1->next;
    }
    while (p2)
    {
        ++len2;
        p2 = p2->next;
    }
    if (len1 > len2)
        pHead1 = walkStep(pHead1, len1 - len2);
    else if (len2 > len1)
        pHead2 = walkStep(pHead2, len2 - len1);
    p1 = pHead1;
    p2 = pHead2;
    while (pHead1)
    {
        if(p1==p2){
            return p1;
        }
        p1=p1->next;
        p2=p2->next;
    }

    return nullptr;
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
    ConnectListNodes(pNode3, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);

    // List1: pNode1, List2: pNode4

    PrintList(pNode1);
    PrintList(pNode4);
    ListNode *pFund = nullptr;
    pFund = FindFirstCommonNode(pNode1, pNode4);
    if(pFund)
        std::cout<<"funded node: "<<pFund->val<<std::endl;
    else
        std::cout<<"not funded"<<std::endl;
    printf("\n");
    DestroyList(pNode1);
    return 0;
}
