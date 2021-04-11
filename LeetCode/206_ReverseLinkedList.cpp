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

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr)
        return nullptr;
    ListNode *nextNode = nullptr;
    ListNode *currNode = head;
    ListNode *preNode = nullptr;
    while (currNode)
    {
        nextNode = currNode->next;
        currNode->next = preNode;
        preNode = currNode;
        if (nextNode)
            currNode = nextNode;
        else
            return currNode;
    }
    return nullptr;
}

// ListNode *reverseList(ListNode *head)
// {
    // if (!head || !head->next)
    //     return head;

    // ListNode *t = reverseList(head->next);
    // head->next->next = head;
    // head->next = NULL;

    // return t;
// }

int main(int argc, char *argv[])
{
    // ListNode *pNode1 = CreateListNode(1);
    // ListNode *pNode2 = CreateListNode(2);
    // ListNode *pNode3 = CreateListNode(3);
    // ListNode *pNode4 = CreateListNode(4);
    // ListNode *pNode5 = CreateListNode(5);

    // ConnectListNodes(pNode1, pNode2);
    // ConnectListNodes(pNode2, pNode3);
    // ConnectListNodes(pNode3, pNode4);
    // ConnectListNodes(pNode4, pNode5);
    std::vector<int> nums = {0, 1, 2, 3, 4};
    ListNode *pNode1 = CreateList(nums);
    PrintList(pNode1);
    ListNode *newHead = reverseList(pNode1);
    PrintList(newHead);
    printf("\n");
    DestroyList(pNode1);
    return 0;
}
