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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr ){
            return nullptr;
        }
       // int length = 1;
        ListNode *temp = head;
       for(int i = 0;i< k ;i++){
        if(temp == nullptr){
            return head;
        }
        temp = temp -> next;
       }
        
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *forward = curr -> next;
        int count = 0;
        while( count < k){
          forward = curr -> next;
            curr -> next = prev;
            prev = curr ;
            curr = forward;
            count++;
        }

        head -> next = reverseKGroup(forward ,k);

        return prev;

    }
};