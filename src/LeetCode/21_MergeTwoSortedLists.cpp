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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    if (l1 == nullptr && l2 == nullptr)
        return nullptr;
    ListNode *dummyHead = new ListNode(0);
    ListNode *currNode = dummyHead;
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val <= l2->val)
        {
            currNode->next = l1;
            currNode = currNode->next;
            l1 = l1->next;
        }
        else if (l1->val > l2->val)
        {
            currNode->next = l2;
            currNode = currNode->next;
            l2 = l2->next;
        }
    }
    currNode->next = (l1 == nullptr) ? l2 : l1;
    return dummyHead->next;
    // ListNode *ans = dummyHead->next;
    // delete dummyHead;
    // return ans;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums1 = {1, 2, 4};
    std::vector<int> nums2 = {1, 3, 4, 8};
    ListNode *pHead1 = CreateList(nums1);
    ListNode *pHead2 = CreateList(nums2);
    std::cout << "List 1:   ";
    PrintList(pHead1);
    std::cout << "List 2:   ";
    PrintList(pHead2);

    ListNode *newHead = mergeTwoLists(pHead1, pHead2);
    std::cout << "New List:   ";
    PrintList(newHead);
    printf("\n");
    // DestroyList(pHead1);
    // DestroyList(pHead2);
    return 0;
}
