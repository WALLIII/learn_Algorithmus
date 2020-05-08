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

ListNode *rotateRight(ListNode *head, int k)
{
    if(head==nullptr)
        return nullptr;
    ListNode* p1=head;
    ListNode* p2=head;
    int n=0;
    for(auto p=head;p;p=p->next) n++;
    k=k%n;
    while(k--){
        p1=p1->next;
    }
    while(p1->next){
        p2=p2->next;
        p1=p1->next;
    }
    // ListNode* pNewHead = new ListNode(0);
    p1->next=head;
    head=p2->next;
    p2->next=nullptr;
    return head;
}
// ListNode *rotateRight(ListNode *head, int k)
// {
//     if (!head)
//         return NULL;
//     int n = 0;
//     for (auto p = head; p; p = p->next)
//         n++;
//     k %= n;
//     std::cout << "k:  " << k << " n: " << n << std::endl;
//     auto first = head, second = head;
//     while (k--)
//     {
//         first = first->next;
//     }
//     while (first->next)
//     {
//         first = first->next;
//         second = second->next;
//     }
//     first->next = head;
//     head = second->next;
//     second->next = NULL;
//     return head;
// }
int main(int argc, char *argv[])
{
    std::vector<int> nums1 = {1};

    ListNode *pHead1 = CreateList(nums1);
    std::cout << "List 1:   ";
    PrintList(pHead1);
    ListNode *res = rotateRight(pHead1, 1);
    PrintList(res);
    printf("\n");
    DestroyList(pHead1);

    return 0;
}
