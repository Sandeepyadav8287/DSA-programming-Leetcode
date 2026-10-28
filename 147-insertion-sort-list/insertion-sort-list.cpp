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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *head1 = nullptr;
        ListNode *tail = nullptr;

        ListNode *un = head;
        while(un != nullptr){

            ListNode *forward = un -> next;
            un -> next = nullptr;
            if(head1 == nullptr){
                head1 = un;
                tail = un;
                }
            else if(un -> val < head1 -> val){
                un -> next = head1;
                head1 = un;

            } 
            else if(un -> val >= tail ->val){
                tail ->next = un;
                tail = un;
            } else{
                ListNode *temp = head1;

                while(temp ->next != nullptr && temp ->next-> val <= un -> val ){
                        temp = temp -> next;
                     }

                un -> next = temp -> next;
                temp -> next = un;

        }

        un = forward;
                

        }
        return head1;
    }
};