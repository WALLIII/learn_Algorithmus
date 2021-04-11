#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>
#include "../Utils/LinkedTemplate.cpp"
ListNode *cut(ListNode *head, int size)
{
    ListNode *curr = head;
    int i=size-1;
    while (i && curr)
    {
        curr = curr->next;
        --i;
       
    }
    //如果当前head是链表最后一个或者切到最后一个就返回空指针
    if (!curr)
        return nullptr;
    ListNode *pnext = curr->next;
    curr->next = nullptr;
    return pnext;
}
ListNode *merge(ListNode *head1, ListNode *head2)
{
    ListNode* dummy=new ListNode(0);
    ListNode* curr=dummy;
    while(head1&&head2){
        if(head1->val<head2->val){
            curr->next=head1;
            curr=head1;
            head1=head1->next;            
        }
        else{
            curr->next=head2;
            curr=head2;
            head2=head2->next;
        }
    }
    curr->next=head1?head1:head2;
    ListNode* res=dummy->next;
    delete dummy;
    return res;
}

ListNode *sortList(ListNode *head)
{
    //如果是空链表或者链表只有一个元素，直接返回
    if (!head || !head->next)
        return head;
    int length = 0;
    ListNode *dummy = new ListNode(0);
    ListNode *curr = head;
    dummy->next = head;
    while (curr)
    {
        ++length;
        curr = curr->next;
    }
    for (int size = 1; size < length; size <<= 1)
    {
        ListNode *curr = dummy->next, *tail = dummy;
        while (curr)
        {
            ListNode *left = curr;
            //cut(head,n)用于切掉链表head的前n个节点。返回后半部分链表头。
            ListNode *right = cut(left, size);
            curr = cut(right, size);
            //现在切下来两段，他们的头分别是left和right。对这两段进行两路归并
            tail->next = merge(left, right);
            //会停留在right这个链表的尾部
            while (tail->next)
                tail = tail->next;
        }
    }
    ListNode* res=dummy->next;
    delete dummy;
    return res;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {4, 3, 1, 7, 8, 9, 2, 11, 5, 6};
    ListNode *phead = CreateList(nums);
    ListNode *newHead = sortList(phead);
    PrintList(newHead);
    return 0;
}
