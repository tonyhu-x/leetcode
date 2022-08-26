using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd_dummy(-1);
        ListNode* odd = &odd_dummy;
        ListNode even_dummy(-1);
        ListNode* even = &even_dummy;

        bool is_even = false;
        while (head != nullptr) {
            if (is_even) {
                even->next = head;
                even = even->next;
            }
            else {
                odd->next = head;
                odd = odd->next;
            }
            head = head->next;
            is_even ^= 1;
        }

        // very important to avoid loops (if the original list is odd-numbered)
        even->next = nullptr;
        odd->next = even_dummy.next;
        return odd_dummy.next;
    }
};

int main() {
    ListNode a(5);
    ListNode b(4, &a);
    ListNode c(3, &b);
    ListNode d(2, &c);
    ListNode e(1, &d);

    Solution().oddEvenList(&e);
}