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

// find the first node of value and delete it
void RemoveNode(ListNode **pHead, int value)
{
    if (pHead == nullptr || *pHead == nullptr)
    {
        return;
    }
    ListNode *pToBeDelete = nullptr;
    if ((*pHead)->val == value)
    {
        pToBeDelete = *pHead;
        *pHead = (*pHead)->next;
    }
    else
    {
        ListNode *pNode = *pHead;
        while (pNode->next != nullptr && pNode->next->val != value)
        {
            pNode = pNode->next;
        }
        if (pNode->next != nullptr && pNode->next->val == value)
        {
            pToBeDelete = pNode->next;
            pNode->next = pNode->next->next;
        }
    }
    if (pToBeDelete != nullptr)
    {
        delete pToBeDelete;
        pToBeDelete = nullptr;
    }
}


std::vector<int> PrintListReversingly_iteratively(ListNode *pHead)
{
    std::vector<int> resVec;
    std::stack<ListNode *> nodes;
    ListNode *pNode = pHead;
    while (pNode != nullptr)
    {
        nodes.push(pNode);
        pNode = pNode->next;
    }
    while (!nodes.empty())
    {
        resVec.push_back(nodes.top()->val);
        // std::cout << "  " << pNode->val;
        nodes.pop();
    }
    return resVec;
}
void PrintListReversingly_recursively(ListNode *pHead)
{
    if (pHead != nullptr)
    {
        if (pHead->next != nullptr)
        {
            PrintListReversingly_recursively(pHead->next);
        }
        std::cout << "  " << pHead->val;
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

void Test(ListNode *pHead)
{
    PrintList(pHead);
    PrintListReversingly_iteratively(pHead);
    printf("\n");
    PrintListReversingly_recursively(pHead);
}

// 1->2->3->4->5
void Test1()
{
    printf("\nTest1 begins.\n");

    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1);

    DestroyList(pNode1);
}

void Test2()
{
    printf("\nTest2 begins.\n");

    ListNode *pNode1 = CreateListNode(1);

    Test(pNode1);

    DestroyList(pNode1);
}

void Test3()
{
    printf("\nTest3 begins.\n");

    Test(nullptr);
}

int main(int argc, char *argv[])
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    std::vector<int> resVec;
    PrintList(pNode1);
    resVec = PrintListReversingly_iteratively(pNode1);
    for (auto v : resVec)
    {
        std::cout << v << "  ";
    }
    printf("\n");
    // PrintListReversingly_recursively(pNode1);
    DestroyList(pNode1);
    return 0;
}
