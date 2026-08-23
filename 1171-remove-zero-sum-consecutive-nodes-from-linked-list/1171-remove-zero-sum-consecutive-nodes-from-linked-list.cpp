class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {

        unordered_map<int,ListNode*> mp;

        ListNode* dummy = new ListNode(0);
        mp[0] = dummy;

        dummy->next = head;

        int sum = 0;
        while(head)
        {
            sum += head->val;

            if(mp.find(sum) != mp.end())
            {
                ListNode* temp = mp[sum]->next;
                int s = sum;

                while(temp != head)
                {
                    s += temp->val;
                    mp.erase(s);
                    temp = temp->next;
                }

                ListNode* node = mp[sum];
                node->next = head->next;
            }
            else mp[sum] = head;

            head = head->next;
        }

        return dummy->next;
    }
};