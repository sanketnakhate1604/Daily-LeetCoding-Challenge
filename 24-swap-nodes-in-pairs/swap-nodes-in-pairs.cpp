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
    ListNode* swapPairs(ListNode* head) {
        ListNode*temp=head;

        int n=0;

        while(temp!=NULL){
            n++;
            temp=temp->next;
        }

        if(n%2==1){
            n=n-1;
        }

        if(head==NULL && n==0){
            return head;
        }

        n=n/2;
        ListNode*curr=head;
        ListNode*front=curr->next;
        while(n--)
        {
            swap(curr->val,front->val);

            curr=front->next;
            if(front->next==NULL ){
                break;
            }
            front=front->next->next;
        }


        return head;
    }
};