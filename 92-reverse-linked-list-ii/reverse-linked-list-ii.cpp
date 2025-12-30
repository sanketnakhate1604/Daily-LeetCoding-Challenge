class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* curr = head;
        ListNode* prev = NULL;

        int l = left;   // store original left

        // move curr to left position
        while (l > 1) {
            prev = curr;
            curr = curr->next;
            l--;
        }

        ListNode* start = curr; // left-th node
        ListNode* end = prev;   // node before left

        ListNode* front = NULL;
        int cnt = right - left + 1;   // ✅ correct count

        // reverse sublist
        while (cnt--) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        // reconnect
        if (end != NULL) {
            end->next = prev;   // ✅ correct
        } else {
            head = prev;        // left == 1 case
        }

        start->next = curr;

        return head;
    }
};
