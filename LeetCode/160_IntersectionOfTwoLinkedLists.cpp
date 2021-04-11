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

ListNode *CreateList(std::vector<int> nums)
{
    if (nums.size() <= 0)
        return nullptr;
    ListNode *pHead = new ListNode(nums[0]);
    ListNode *pre = pHead;
    for (int i = 1; i < nums.size(); ++i)
    {
        ListNode *pNew = new ListNode(nums[i]);
        pre->next = pNew;
        pre = pNew;
    }
    return pHead;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB)
        return nullptr;
    int leA = 0, leB = 0;
    ListNode *pA = headA;
    ListNode *pB = headB;
    for (pA = headA; pA; pA = pA->next)
        ++leA;
    for (pB = headB; pB; pB = pB->next)
        ++leB;
    if (leA > leB)
    {
        while (leA - leB)
        {
            headA = headA->next;
            leA--;
        }
    }
    else if (leA < leB)
    {
        while (leB - leA)
        {
            headB = headB->next;
            leB--;
        }
    }
    pA = headA;
    pB = headB;
    while (pA)
    {
        if (pA == pB)
            return pA;
        pA = pA->next;
        pB = pB->next;
    }
    return nullptr;
}
int main(int argc, char *argv[])
{
    ListNode *pNode1 = CreateListNode(4);
    ListNode *pNode2 = CreateListNode(1);

    ListNode *pNode3 = CreateListNode(8);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ListNode *pNode6 = CreateListNode(5);
    ListNode *pNode7 = CreateListNode(0);
    ListNode *pNode8 = CreateListNode(1);
    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);
    ConnectListNodes(pNode8, pNode5);


    ListNode *commen = getIntersectionNode(pNode1, pNode6);
    if (commen)
        std::cout << commen->val << std::endl;
    else
        std::cout<<"not finded"<<std::endl;

    return 0;
}
