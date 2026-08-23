class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }

        l2->next = mergeTwoLists(l2->next, l1);
        return l2;
    }
    
    ListNode* Partition(int s, int e, vector<ListNode*>& lists)
    {
        if(s == e) return lists[s];

        int mid = s + (e - s) / 2;

        ListNode* l1 = Partition(s, mid, lists);
        ListNode* l2 = Partition(mid+1, e, lists);

        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if(k == 0) return nullptr;

        return Partition(0, k-1, lists);
    }
};