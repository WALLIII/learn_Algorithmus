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

void DeteleNode(ListNode **pHead, ListNode *pToBeDeleted)
{
    if (!pHead || !pToBeDeleted)
    {
        return;
    }
    // if pToBeDeleted is not tail of linked
    if (pToBeDeleted->next != nullptr)
    {
        ListNode *pNext = pToBeDeleted->next;
        pToBeDeleted->val = pNext->val;
        pToBeDeleted->next = pNext->next;

        delete pNext;
        pNext = nullptr;
    }
    // if the linked has only node-->head needs to be delete
    else if (*pHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        *pHead = nullptr;
        pToBeDeleted = nullptr;
    }
    // pToBeDeleted is the tail of linked
    else
    {
        ListNode *pNode = *pHead;
        while (pNode->next != pToBeDeleted)
        {
            pNode = pNode->next;
        }
        pNode->next = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

void DeleteDuplication(ListNode **pHead)
{
    if (pHead == nullptr || *pHead == nullptr)
    {
        return;
    }
    ListNode *pPreNode = nullptr;
    ListNode *pNode = *pHead;

    while (pNode != nullptr)
    {
        ListNode *pNext = pNode->next;
        bool needDel = false;
        if (pNext != nullptr && pNext->val == pNode->val)
            needDel = true;
        // donot need to delete pNode
        if (!needDel)
        {
            pPreNode = pNode;
            pNode = pNode->next;
        }
        else
        {
            int value = pNode->val;
            // pNode != nullptr if duplicated node is in tail of linked
            // if you delete "pNode != nullptr", and duplictaed node in tail of linked, then error
            while (pNode != nullptr && pNode->val == value)
            {
                pNext = pNode->next;
                delete pNode;
                pNode = nullptr;
                pNode = pNext;
            }
            // if duplicated node is in head of linked
            if (pPreNode == nullptr)
            {
                *pHead = pNext;
            }
            else
            {
                pPreNode->next = pNext;
            }
            pNode = pNext;
        }
    }
}
// in webside this function should return a ListNode
ListNode *DeleteDuplication(ListNode *pHead)
{
    if (pHead == nullptr)
    {
        return nullptr;
    }
    ListNode *pHeadResult = pHead;
    ListNode *pPreNode = nullptr;
    ListNode *pNode = pHeadResult;
    while (pNode != nullptr)
    {
        ListNode *pNext = pNode->next;
        bool needDel = false;
        if (pNext != nullptr && pNext->val == pNode->val)
            needDel = true;
        // donot need to delete pNode
        if (!needDel)
        {
            pPreNode = pNode;
            pNode = pNode->next;
        }
        else
        {
            int value = pNode->val;
            // pNode != nullptr if duplicated node is in tail of linked
            // if you delete "pNode != nullptr", and duplictaed node in tail of linked, then error
            while (pNode != nullptr && pNode->val == value)
            {
                pNext = pNode->next;
                delete pNode;
                pNode = nullptr;
                pNode = pNext;
            }
            // if duplicated node is in head of linked
            if (pPreNode == nullptr)
            {
                pHeadResult = pNext;
            }
            else
            {
                pPreNode->next = pNext;
            }
            pNode = pNext;
        }
    }
    return pHeadResult;
}

// void DeleteDuplication(ListNode** pHead)
// {
//     if (pHead == nullptr || *pHead == nullptr)
//     {
//         return;
//     }
//     ListNode *pPreNode = nullptr;
//     ListNode *pNode = *pHead;

//     while (pNode != nullptr)
//     {
//         ListNode *pNext = pNode->next;
//         bool needDel = false;
//         if (pNext != nullptr && pNext->val == pNode->val)
//             needDel = true;
//         // donot need to delete pNode
//         if (!needDel)
//         {
//             pPreNode = pNode;
//             pNode = pNode->next;
//             std::cout << "do not need to delete" << std::endl;
//         }
//         else
//         {
//             ListNode *pToBeDel = pNode;
//             int value = pNode->val;
//             while (pToBeDel != nullptr && pToBeDel->val == value)
//             {
//                 pNext = pToBeDel->next;
//                 delete pToBeDel;
//                 pToBeDel = nullptr;
//                 pToBeDel = pNext;
//             }
//             if (pPreNode == nullptr)
//             {
//                 *pHead = pNext;
//             }
//             else
//             {
//                 pPreNode->next = pNext;
//             }
//             pNode = pNext;
//         }
//     }
// }

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

int main(int argc, char *argv[])
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(3);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(4);
    ListNode *pHeadResult = nullptr;

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    // std::vector<int> resVec;
    PrintList(pNode1);

    // DeteleNode(pHead, pNode5);
    pHeadResult = DeleteDuplication(pNode1);

    std::cout << "after delete: ";
    std::cout << std::endl;
    PrintList(pHeadResult);

    DestroyList(pNode1);
    DestroyList(pHeadResult);
    return 0;
}
