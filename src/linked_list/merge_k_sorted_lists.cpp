#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Ingenious solution by someone else in discussion.
 */
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
        return nullptr;
    }
    int n = lists.size();
    while (n > 1) {
        for (int i = 0; i < n / 2; i++) {
            lists[i] = mergeTwoLists(lists[i], lists[n - 1 - i]);
        }
        n = (n + 1) / 2;
    }
    return lists[0];
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l2->next, l1);
        return l2;
    }
}

/**
 * Improvement over version A.
 */
ListNode* mergeTwoListsB(ListNode* l1, ListNode* l2) {
    ListNode dummy(-1);
    ListNode* node = &dummy;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            node->next = l1;
            node = node->next;
            l1 = l1->next;
        }
        else {
            node->next = l2;
            node = node->next;
            l2 = l2->next;
        }
    }
    if (l1) {
        node->next = l1;
    }
    else {
        node->next = l2;
    }
    return dummy.next;
}

/**
 * This implementation is very inelegant.
 * It is also inefficient if one of the lists becomes empty first.
 * 
 * This can be improved by changing the while loop condition to
 * check that both lists are non-empty.
 */
ListNode* mergeTwoListsA(ListNode* l1, ListNode* l2) {
    ListNode* root = nullptr;
    ListNode* head = nullptr;

    while (l1 != nullptr || l2 != nullptr) {
        ListNode* selected = nullptr;
        if (l1 == nullptr) {
            selected = l2;
        }
        else if (l2 == nullptr) {
            selected = l1;
        }
        else {
            selected = l1->val > l2->val ? l2 : l1;
        }
        // advance pointer
        if (selected == l1) {
            l1 = l1->next;
        }
        else {
            l2 = l2->next;
        }
        if (root == nullptr) {
            root = selected;
            head = selected;
        }
        else {
            head->next = selected;
            head = head->next;
        }
    }
    return root;
}

int main() {
    ListNode a(4);
    ListNode b(2, &a);
    ListNode c(1, &b);
    ListNode x(5);
    ListNode y(3, &x);
    ListNode z(1, &y);

    ListNode* done = mergeTwoListsA(&c, &z);
    return 0;
}