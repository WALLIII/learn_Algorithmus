#include "../Utils/LinkedTemplate.cpp"

using namespace std;
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    ListNode *dummy = new ListNode(-1);
    ListNode *curr = dummy;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else if (l1->val > l2->val)
        {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    if (l1)
        curr->next = l1;
    if (l2)
        curr->next = l2;
    ListNode *res = dummy->next;
    delete dummy;
    return res;
}

ListNode *merge(vector<ListNode *> &lists, int l, int r)
{
    if (l > r)
        return nullptr;
    if (l == r)
        return lists[l];
    int mid=(l+r)>>1;
    return mergeTwoLists(merge(lists, l, mid), merge(lists, mid+1, r));
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    return merge(lists, 0, lists.size() - 1);
}
int main(int argc, char *argv[])
{
    std::vector<int> nums1 = {1, 4, 5};
    std::vector<int> nums2 = {1, 3, 4};
    std::vector<int> nums3 = {3, 6};
    ListNode *head1 = CreateList(nums1);
    ListNode *head2 = CreateList(nums2);
    ListNode *head3 = CreateList(nums3);
    vector<ListNode *> lists = {head1, head2, head3};
    ListNode *res = mergeKLists(lists);
    // ListNode* res=mergeTwoLists(head1, head2);
    PrintList(res);
    printf("\n");
    DestroyList(head1);
    DestroyList(head2);
    DestroyList(head3);
    return 0;
}