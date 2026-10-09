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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr ||  right == left){
            return head;

        }
        ListNode *prev = nullptr;
        ListNode *curr = head;
      //  ListNode *forward = curr -> next;
        int i = 1;
       
        while(i < left){
            i++;
            prev = curr;
            curr = curr -> next;
            
        }
         ListNode *temp = curr;

        int j = left;
        ListNode *rightcurr = nullptr;
        ListNode *rightforw = nullptr;
        while(j <= right){
            rightcurr = curr -> next ;
            curr -> next= rightforw;
            rightforw = curr;
            curr = rightcurr;
            j++;
        }
       if(prev != nullptr){
        prev -> next = rightforw;
       }else{
        head = rightforw;
       }

       temp -> next = curr;

        return head;


    }
};