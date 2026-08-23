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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;

        while(head != nullptr)
        {
            ListNode* node = head->next;

            head->next = prev;
            prev = head;

            head = node;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode* head2 = new ListNode(head->val);
        ListNode* temp1 = head->next;
        ListNode* temp2 = head2;

        while(temp1)
        {
            temp2->next = new ListNode(temp1->val);

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        head2 = reverseList(head2);

        while(head)
        {
            if(head->val != head2->val) return false;

            head = head->next;
            head2 = head2->next;
        }

        return true;
    }
};