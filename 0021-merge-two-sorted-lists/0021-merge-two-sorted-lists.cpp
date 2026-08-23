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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                ListNode* node = list1->next;
                curr->next = list1;
                list1->next = nullptr;
                list1 = node;
            }
            else
            {
                ListNode* node = list2->next;
                curr->next = list2;
                list2->next = nullptr;
                list2 = node;
            }

            curr = curr->next;
        }
        if(list1) curr->next = list1;
        if(list2) curr->next = list2;

        return dummy->next;
    }
};