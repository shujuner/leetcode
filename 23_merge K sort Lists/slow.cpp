/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
        {
            return nullptr;
        }
        ListNode *left,*right;
        left=lists[0];
        for(int i=1;i<lists.size();++i)
        {
            left=mergeTwoLists(left,lists[i]);
        }
        return left;
        
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *newHead=new ListNode(0);
        ListNode *tail=newHead;
        while(l1&&l2)
        {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return newHead->next;
    }
};