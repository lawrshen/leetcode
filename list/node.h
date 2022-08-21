#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *p) : val(x), next(p) {}
};

bool hasCycle(ListNode *head);
ListNode *sortList(ListNode *head);