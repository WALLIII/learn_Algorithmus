#include <vector>
#include <iostream>
#include <stack>
#include "../Utils/LinkedTemplate.cpp"

using namespace std;

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (!head || !head->next)
        return nullptr;

    ListNode *pnew = new ListNode(0);
    pnew->next = head;
    ListNode *fast = pnew, *slow = pnew;
    for (int i = 0; i < n; ++i)
        fast = fast->next;
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode *next = slow->next->next;
    slow->next = next;
    ListNode *res = pnew->next;
    delete pnew;
    return res;
}

int main()
{

    vector<int> nums = {1, 2};
    ListNode *head = CreateList(nums);
    // PrintList(head);
    removeNthFromEnd(head, 2);
    // PrintList(head);
    return 0;
}