#include "../Utils/LinkedTemplate.cpp"
#include <iostream>
#include <vector>

ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
{

    if (!pHead1)
        return pHead2;
    if (!pHead2)
        return pHead1;
    ListNode *pnewHead = nullptr;
    if (pHead1->val >= pHead2->val)
    {
        pnewHead = pHead2;
        pHead2 = pHead2->next;
    }
    else if (pHead1->val < pHead2->val)
    {
        pnewHead = pHead1;
        pHead1 = pHead1->next;
    }
    ListNode* curr=pnewHead;
    while (pHead1 && pHead2)
    {
        if (pHead1->val <= pHead2->val)
        {
            curr->next = pHead1;
            pHead1 = pHead1->next;
            curr=curr->next;
        }
        else if (pHead1->val > pHead2->val)
        {
            curr->next = pHead2;
            pHead2 = pHead2->next;
            curr=curr->next;

        }
    }
    if(pHead1){
        curr->next=pHead1;
    }
    if(pHead2){
        curr->next=pHead2;
    }
    return pnewHead;
}

int main()
{
    std::vector<int> vec1 = {1, 3, 5, 8};
    std::vector<int> vec2 = {2, 4, 7, 9, 10};
    ListNode *head1 = CreateList(vec1);
    ListNode *head2 = CreateList(vec2);
    ListNode *head = Merge(head1, head2);
    PrintList(head);
    return 0;
}