/*************************************************************************
	> File Name: intersectionOfTwoLists.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 09/10/2017 Sun 15:47:18
 ************************************************************************/

#include <iostream>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *h1 = headA, *h2 = headB;
    while (h1 != h2)
    {
        h1 = h1 == nullptr ? headB : h1->next;
        h2 = h2 == nullptr ? headA : h2->next;
    }
    return h1;
}