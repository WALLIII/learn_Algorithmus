#include "../Utils/LinkedTemplate.cpp"
#include <iostream>
#include <vector>

ListNode *ReverseList(ListNode *pHead)
{
    if(pHead==nullptr)
        return nullptr;
    ListNode* pre=nullptr;
    ListNode* curr=pHead;
    ListNode* pnext=curr->next;
    while(pnext){
        curr->next=pre;
        pre=curr;
        curr=pnext;
        pnext=curr->next;
    }
    curr->next=pre;
    ListNode* newHead=curr;
    return newHead;
}

int main()
{
    std::vector<int> lk = {1, 2, 3, 4, 5};
    ListNode *pHead = CreateList(lk);
    ListNode *newHead=ReverseList(pHead);
    PrintList(newHead);
    return 0;
}