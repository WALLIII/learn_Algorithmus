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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ansHead = new ListNode(0);
    ListNode *curr = ansHead;
    if (l1 == nullptr || l2 == nullptr)
        return ansHead;
    int carry = 0, sum = 0;
    while (l1 || l2 || carry)
    {
        sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum / 10;
        ListNode *tmpNode = new ListNode(sum % 10);
        curr->next = tmpNode;
        curr = curr->next;
        l1 = (l1 ? l1->next : l1);
        l2 = (l2 ? l2->next : l2);
    }
    return ansHead->next;
}
int main(int argc, char *argv[])
{
    ListNode *pNode1 = CreateListNode(2);
    ListNode *pNode2 = CreateListNode(4);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode7 = CreateListNode(6);

    ListNode *pNode4 = CreateListNode(5);
    ListNode *pNode5 = CreateListNode(6);
    ListNode *pNode6 = CreateListNode(4);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode7);

    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);

    PrintList(addTwoNumbers(pNode1, pNode4));

    printf("\n");
    DestroyList(pNode1);
    DestroyList(pNode4);
    return 0;
}
