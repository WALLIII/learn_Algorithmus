#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>
#include "../Utils/LinkedTemplate.cpp"

ListNode *insertionSortList(ListNode *head)
{
    //如果是空链表或者链表只有一个元素，直接返回
    if (!head || !head->next)
        return head;
    //这个dummy->next要永远指向有序区的头部
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    //pre指向有序区的尾部，curr是无序区的第一个，是要去前面找空插入的节点
    ListNode *pre = head, *curr = head->next;
    while (curr)
    {
        //如果curr比pre小的话，就要想办法把curr放在前面的合适位置
        if (curr->val < pre->val)
        {
            ListNode *tmp = dummy;
            //从头开始找要插入curr的位置
            while (curr->val > tmp->next->val)
            {
                tmp = tmp->next;
            }
            //tmp的后面就是curr要插入的位置。
            pre->next = curr->next; // 改一下有序区的尾巴
            curr->next = tmp->next; //把curr插入tmp后。
            tmp->next = curr;
            curr = pre->next;
        }
        //如果curr比pre大的话，curr和pre都右移
        else{
            pre=pre->next;
            curr=curr->next;
        }
    }
    ListNode* newhead=dummy->next;
    delete dummy;
    return newhead;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {4, -1, 5, 3, 0};
    ListNode *phead = CreateList(nums);
    ListNode *newHead = insertionSortList(phead);
    PrintList(newHead);
    return 0;
}
