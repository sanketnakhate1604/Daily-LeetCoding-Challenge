/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;

        ListNode* a=head;

        while(a!=NULL){
            len=len+1;
            a=a->next;
        }
      if (n == len) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }


        ListNode*curr=head;
        ListNode*prev=NULL;
        len=len-n;
        while(len!=0){
            prev=curr;
            curr=curr->next;
            len--;
        }

        prev->next=curr->next;
        delete curr;

        return head;
    }
};