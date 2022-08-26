struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* origin = l1;
        bool carry = false;

        // even when l2 is null, there may still be carry
        while (l1 != nullptr) {
            if (carry) {
                carry = false;
                l1->val++;
            }

            l1->val += l2->val;

            if (l1->val >= 10) {
                l1->val -= 10;
                carry = true;
            }

            // auto extend either or both numbers
            if (carry || l1->next != nullptr || l2->next != nullptr) {
                if (l1->next == nullptr) {
                    l1->next = new ListNode();
                }
                if (l2->next == nullptr) {
                    l2->next = new ListNode();
                }
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return origin;
    }
};

int main() {
    ListNode a (3);
    ListNode b (4, &a);
    ListNode c (2, &b);
    
    ListNode x (4);
    ListNode y (6, &x);
    ListNode z (5, &y);

    Solution().addTwoNumbers(&c, &z);

    return 0;
}