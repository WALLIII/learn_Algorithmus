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

// ListNode *merge(ListNode *l1, ListNode *l2)
// {
//     ListNode *dummy = new ListNode(0);
//     ListNode *p = dummy;
//     while (l1 && l2)
//     {
//         if (l1->val > l2->val)
//         {
//             p->next = l2;
//             p = p->next;
//             l2 = l2->next;
//         }
//         else
//         {
//             p->next = l1;
//             p = p->next;
//             l1 = l1->next;
//         }
//     }
//     //最后一定要加这两句
//     if (NULL == l1)
//         p->next = l2;
//     if (NULL == l2)
//         p->next = l1;
//     return dummy->next;
// }
// ListNode *sortList(ListNode *head)
// {
//     if (!head || !head->next)
//         return head;
//     //通过以下的循环找到链表的中点，将链表分为两个部分
//     ListNode *slow = head, *fast = head;
//     while (slow->next != NULL && fast->next != NULL && fast->next->next != NULL)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     ListNode *last = slow->next;
//     slow->next = NULL;
//     ListNode *pre = sortList(head);
//     ListNode *las = sortList(last);
//     return merge(pre, las);
// }

ListNode *merge(ListNode *head1, ListNode *head2)
//将两个有序链表合并成为一个有序链表，返回链表的头指针
{
    ListNode *dummyhead = new ListNode(-1);
    ListNode *currents = dummyhead;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->val <= head2->val)
        //每次取出head1节点与head2节点中的较小值
        //将其放插入合并的链表之中
        {
            currents->next = new ListNode(head1->val);
            head1 = head1->next;
            currents = currents->next;
        }
        else
        {
            currents->next = new ListNode(head2->val);
            head2 = head2->next;
            currents = currents->next;
        }
    }
    while (head1 != NULL)
    //如果其中还有节点的数值未被放完的时候
    {
        currents->next = new ListNode(head1->val);
        currents = currents->next;
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        currents->next = new ListNode(head2->val);
        currents = currents->next;
        head2 = head2->next;
    }
    currents->next = NULL;
   
    return dummyhead->next;
    //返回合并链表的头指针
}

ListNode *cuts(ListNode *head, int steps)
{
    //切除链表，返回下一个链表的头指针
    ListNode *dummyhead = new ListNode(-1);
    dummyhead->next = head;
    ListNode *currents = dummyhead;
    for (int i = 0; i < steps; i++)
    {
        if (currents->next == NULL)
        //放置链表的末尾有长度不够step的部分
        {
            break;
        }
        currents = currents->next;
    }
    ListNode *u = currents->next;
    //提前保存下一个链表的头指针
    currents->next = NULL;
    //将链表切断
    return u;
    //返回下一个链表的头指针
}

ListNode *sortList(ListNode *head)
{
    ListNode *dummyhead = new ListNode(-1);
    dummyhead->next = head;
    ListNode *currents = head;
    int total = 0;
    while (currents)
    {
        total++;
        currents = currents->next;
    }
    ListNode *lefts;
    ListNode *rights;
    ListNode *nextleft;
    lefts = dummyhead->next;
    ListNode *tail = dummyhead;
    for (int step = 1; step < total; step = step * 2)
    {
        tail = dummyhead;
        //tail保存合并链表的头指针
        lefts = dummyhead->next;
        //两两合并，lefts指向第一个链表
        while (lefts != NULL)
        {
            // 若只剩下最后一个，rights和nextleft均为null，left为0的节点
            rights = cuts(lefts, step);
            //切割后返回下一个链表的头指针
            nextleft = cuts(rights, step);
            // 举个例子，在-1->4 并和完之后，tail移动到了4节点的位置，现在merge返回的是
            // 3-->5，这时候要将4指向3，链表才能连起来。
            tail->next = merge(lefts, rights);
            //将lefts链表与rights链表合并
            while (tail->next != NULL)
            {
                tail = tail->next;
            }
            //尾指针后移，变为下一个节点的头指针
            lefts = nextleft;
            //lefts变为下一个合并链表的头指针
        }
    }
    return dummyhead->next;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {4,-1,5,3,0};
    ListNode *phead = CreateList(nums);
    ListNode *newHead = sortList(phead);
    PrintList(newHead);
    return 0;
}
