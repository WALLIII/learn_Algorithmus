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

ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if (!head || m < 1 || n < 1 || m > n)
    {
        return nullptr;
    }
    if(m==n)
        return head;

    auto *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *pPre = dummy;
    ListNode *q = dummy;
   
    for (int i = 0; i < m - 1; ++i)
    {
        pPre = pPre->next;
    }
    for (int i = 0; i < n; ++i)
    {
        q = q->next;
    }
    ListNode *p = pPre->next;
    ListNode *qNext = q->next;

    auto pre = p, curr = pre->next;
   
    while(curr!=qNext) {
        auto tmp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = tmp;
    }
    pPre->next = q;
    p->next = qNext;
    return dummy->next;
    
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {1};
    ListNode *head = CreateList(nums);

    ListNode *newH = reverseBetween(head, 1, 1);
    PrintList(newH);
    return 0;
}
