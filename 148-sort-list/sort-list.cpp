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
    ListNode *merger(ListNode *first , ListNode *second){
        ListNode *dummy = new ListNode();
        ListNode *head = dummy;

        while(first != nullptr && second != nullptr){
            if(first -> val < second -> val){
                head -> next = first;
                first = first -> next;
                
            }else {
                head -> next = second;
                second = second -> next;
            }

            head = head -> next;
        }

        if(first == nullptr){
            head -> next = second;
        }else{
            head -> next = first;
        }

        return dummy -> next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head ->next;

        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;

            fast = fast -> next -> next;
        }
        ListNode *first = head;
        ListNode *second = slow -> next;
        slow -> next = nullptr;
        ListNode *firsthead = sortList(first);
        ListNode *secondhead = sortList(second);

        return merger(firsthead,secondhead);



    }
};