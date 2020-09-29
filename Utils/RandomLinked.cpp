#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>
struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
RandomListNode *CreateListNode(int value)
{
    RandomListNode *pNode = new RandomListNode(0);
    pNode->label = value;
    pNode->next = nullptr;
    pNode->random = nullptr;

    return pNode;
}

void ConnectListNodes(RandomListNode *pCurrent, RandomListNode *pNext, RandomListNode *pRandom)
{
    if (pCurrent == nullptr)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }
    pCurrent->next = pNext;
    pCurrent->random = pRandom;
}

void DestroyList(RandomListNode *pHead)
{
    RandomListNode *pNode = pHead;
    while (pNode != nullptr)
    {
        pHead = pHead->next;
        delete pNode;
        pNode = pHead;
    }
}

void PrintListNode(RandomListNode *pNode)
{
    if (pNode == nullptr)
    {
        printf("The node is nullptr\n");
    }
    else
    {
        printf("The key in node is %d.\n", pNode->label);
    }
}

void PrintList(RandomListNode* pHead)
{
    RandomListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        std::cout<<pNode->label<<"  ";

        if(pNode->random != nullptr)
            std::cout<<pNode->random->label<<"  ";
        else
            std::cout<<"#  ";

        pNode = pNode->next;
    }
}
// int main(int argc, char *argv[])
// {
//     RandomListNode *pNode1 = CreateListNode(1);
//     RandomListNode *pNode2 = CreateListNode(2);
//     RandomListNode *pNode3 = CreateListNode(3);
//     RandomListNode *pNode4 = CreateListNode(4);
//     RandomListNode *pNode5 = CreateListNode(5);

//     ConnectListNodes(pNode1, pNode2, pNode3);
//     ConnectListNodes(pNode2, pNode3, pNode5);
//     ConnectListNodes(pNode3, pNode4, nullptr);
//     ConnectListNodes(pNode4, pNode5, pNode2);
//     std::cout<<"print original list: "<<std::endl;
//     PrintList(pNode1);
//     std::cout<<std::endl;
    
//     RandomListNode *pNewHead;
//     pNewHead = Clone(pNode1);
//     std::cout<<"print duplicated list: "<<std::endl;
//     PrintList(pNewHead);
//     std::cout<<std::endl;
    
//     DestroyList(pNode1);
//     return 0;
// }
