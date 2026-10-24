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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* before = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            before = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr;

        if (fast == nullptr) {
            curr = slow;
            before->next = nullptr;
        } else {
            curr = slow->next;
            slow->next = nullptr;
        }

        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        ListNode* temp2 = prev;

        while (temp2 != nullptr) {
            if (temp2->val != temp->val)
                return false;

            temp2 = temp2->next;
            temp = temp->next;
        }

        return true;
    }
};