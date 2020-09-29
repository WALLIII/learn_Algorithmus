#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>
#include "../Utils/LinkedTemplate.cpp"
using namespace std;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    stack<ListNode *> sk1, sk2;
    ListNode *p1 = l1, *p2 = l2;
    //先把l1,l2的节点分别压栈
    while (p1)
    {
        sk1.push(p1);
        p1 = p1->next;
    }
    while (p2)
    {
        sk2.push(p2);
        p2 = p2->next;
    }

    int carry = 0, tmp = 0;
   
    ListNode *curr1 = nullptr, *curr2 = nullptr, *ans = nullptr;
    while (!sk1.empty() || !sk2.empty() || carry)
    {

        int m = (sk1.empty()) ? 0 : sk1.top()->val;
        int n = (sk2.empty()) ? 0 : sk2.top()->val;
        if(!sk1.empty())
            sk1.pop();
        if(!sk2.empty())
            sk2.pop();
        tmp = m + n + carry;
        cout << "m: " << m << " n: " << n << endl;
        carry = tmp / 10;
        ListNode *pnew = new ListNode(tmp % 10);
        pnew->next = ans;
        ans=pnew;
    }
    // ListNode* newhead=dummy->next;
    // delete dummy;
    return ans;
}
int main(int argc, char *argv[])
{
    std::vector<int> nums1 = {7, 2, 4, 3};
    std::vector<int> nums2 = {5, 6, 4};
    ListNode *head1 = CreateList(nums1);
    ListNode *head2 = CreateList(nums2);
    ListNode *res = addTwoNumbers(head1, head2);
    PrintList(res);
    return 0;
}
