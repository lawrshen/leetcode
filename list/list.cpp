#include "node.h"

// 141 https://leetcode.cn/problems/linked-list-cycle/
bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode *slow = head, *fast = head->next;
    while (slow != fast) {
        if (!fast || !fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }
    return true;
}

// 206 https://leetcode.cn/problems/reverse-linked-list/
ListNode *reverseList(ListNode *head) {
    if (!head)
        return {};
    ListNode *pre = nullptr, *ptr = head;
    while (ptr->next != nullptr) {
        ListNode *nxt = ptr->next;
        ptr->next = pre;
        pre = ptr;
        ptr = nxt;
    }
    ptr->next = pre;
    return ptr;
}

// 234 https://leetcode.cn/problems/palindrome-linked-list/
bool isPalindrome(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *nxt = fast ? slow->next : slow;// fast != nullptr odd:even
    ListNode *rhead = reverseList(nxt);
    for (ListNode *ptr = head; ptr != slow; ptr = ptr->next, rhead = rhead->next) {
        if (ptr->val != rhead->val) {
            return false;
        }
    }
    return true;
}

// 2 https://leetcode.cn/problems/add-two-numbers/
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dumpy = new ListNode();
    ListNode *ptr = dumpy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int l1val = l1 ? l1->val : 0;
        int l2val = l2 ? l2->val : 0;
        int sumval = l1val + l2val + carry;
        carry = sumval / 10;
        sumval %= 10;
        ptr->next = new ListNode(sumval);
        ptr = ptr->next;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    return dumpy->next;
}

void reverse(ListNode *head, ListNode *last) {
    ListNode *pre = nullptr, *ptr = head;
    while (ptr != last) {
        ListNode *nxt = ptr->next;
        ptr->next = pre;
        pre = ptr;
        ptr = nxt;
    }
    ptr->next = pre;
}

// 25 https://leetcode.cn/problems/reverse-nodes-in-k-group/
ListNode *reverseKGroup(ListNode *head, int k) {
    int cnt = 0;
    ListNode *begin = nullptr, *last = nullptr;
    ListNode *cur = head;
    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next) {
        cnt++;
        if (cnt % k == 0) {
            ListNode *nxt = ptr->next;
            reverse(cur, ptr);
            if (begin == nullptr) {
                begin = ptr;
            }
            if (last == nullptr) {
                last = cur;
            } else {
                last->next = ptr;
                last = cur;
            }
            cur->next = nxt;
            ptr = cur;
            cur = nxt;
        }
    }
    return begin;
}

ListNode *cut(ListNode *cur, int step) {
    ListNode *ptr = cur;
    for (; ptr != nullptr; ptr = ptr->next) {
        step--;
        if (!step) {
            break;
        }
    }
    if (ptr == nullptr)
        return {};
    ListNode *nxt = ptr->next;
    ptr->next = nullptr;
    return nxt;
}

ListNode *merge(ListNode *left, ListNode *right) {
    ListNode *dummy = new ListNode();
    ListNode *res = dummy;
    while (left && right) {
        if (left->val < right->val) {
            res->next = left;
            res = res->next;
            left = left->next;
        } else {
            res->next = right;
            res = res->next;
            right = right->next;
        }
    }
    res->next = left ? left : right;
    return dummy->next;
}

// 148 https://leetcode.cn/problems/sort-list/    https://leetcode.cn/problems/7WHec2/
ListNode *sortList(ListNode *head) {
    ListNode *dummy = new ListNode(0, head);
    int length = 0;
    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next) {
        length++;
    }
    for (int step = 1; step < length; step *= 2) {
        ListNode *tail = dummy, *cur = dummy->next;
        while (cur) {
            ListNode *left = cur, *right = cut(cur, step);
            cur = cut(right, step);
            tail->next = merge(left, right);
            while (tail->next) {
                tail = tail->next;
            }
        }
    }
    return dummy->next;
}

// 24 https://leetcode.cn/problems/swap-nodes-in-pairs/
ListNode *swapPairs(ListNode *head) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *pre = dummy, *ptr = dummy->next;
    while (ptr && ptr->next) {
        ListNode *cur = ptr->next, *nxt = ptr->next->next;
        cur->next = ptr;
        pre->next = cur;
        ptr->next = nxt; // pre [ cur ptr ] nxt
        pre = ptr;
        ptr = nxt;
    }
    return dummy->next;
}

// 61 https://leetcode.cn/problems/rotate-list/
ListNode *rotateRight(ListNode *head, int k) {
    if (!head)
        return {};
    int length = 0;
    ListNode *tail = head, *cur = head;
    for (; tail->next != nullptr; tail = tail->next) {
        length++;
    }
    k %= (length + 1);
    int cnt = 1;
    while (cnt < length - k) {
        cnt++;
        cur = cur->next;
    }
    tail->next = head;
    ListNode *res = cur->next;
    cur->next = nullptr;
    return res;
}