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
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;

        }

        ListNode *curr = slow -> next;
        slow -> next = nullptr;
        ListNode *prev = nullptr;
        while(curr != nullptr ){
            ListNode *forward = curr -> next;
            curr -> next = prev;
            prev= curr ;
            curr = forward;
        }

        ListNode *first = head;
        ListNode *second = prev;

        while(second != nullptr){
            ListNode *tm1 = first -> next;
            ListNode *tm2 = second -> next;

            first -> next = second;
            second -> next = tm1;

            first = tm1 ;
            second = tm2;
        }

    }
};