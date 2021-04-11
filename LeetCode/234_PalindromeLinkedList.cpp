
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

bool isPalindrome(ListNode *head)
{
    if(!head||!head->next)
        return true;
    ListNode* pmid=head, *head2=head;
    while(head2&&head2->next){
        pmid=pmid->next;
        head2=head2->next->next;

    }
  
    // 现在开始反转pmid到尾部的链表
    ListNode* curr=pmid, *pnext=pmid->next;
    
    while(pnext){
        ListNode* tmp=pnext->next;
        pnext->next=curr;
        curr=pnext;
        pnext=tmp;
    }
    // pmid->next=NULL;
    pmid->next=nullptr;

    ListNode* p1=head;
    //现在curr是后半部分链表的头
    while(p1&&curr){
        if(p1->val==curr->val){
            p1=p1->next;
            curr=curr->next;
        }
        else
            return false;
    }
    return true;

}
// bool isPalindrome(ListNode *head)
// {
//     // 方法1. 使用数组
//     /*
//         vector<int> v;
//         while(head){
//             v.push_back(head->val);
//             head = head->next;
//         }
//         // 判断是否回文
//         for(int i=0; i<v.size()/2; ++i){
//             if(v[i] != v[v.size()-1-i]){
//                 return false;
//             }
//         }
//         return true;
//         */

//     // 方法2. 反转链表
//     if (!head || !head->next)
//         return true;
//     ListNode *slow = head, *fast = head;
//     // 将slow指针移动到链表中间位置
//     while (fast && fast->next)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     // 反转后半部分
//     ListNode *curNode = slow, *nextNode = slow->next;
//     while (nextNode)
//     {
//         ListNode *tmp = nextNode->next;
//         nextNode->next = curNode;
//         curNode = nextNode;
//         nextNode = tmp;
//     }
//     slow->next = nullptr;
//     // 开始比较是否相等
//     while (head && curNode)
//     {
//         if (head->val != curNode->val)
//             return false;
//         head = head->next;
//         curNode = curNode->next;
//     }
//     return true;
// }
int main(int argc, char *argv[])
{
    std::vector<int> nums = {1, 2, 3, 5, 4, 3, 2, 1};
    ListNode *pNode1 = CreateList(nums);
    PrintList(pNode1);
    printf("\n");
    if (isPalindrome(pNode1))
        std::cout << "yes" << std::endl;
    else
        std::cout << "no" << std::endl;
    DestroyList(pNode1);
    return 0;
}
