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
       ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()){
            return nullptr;
        }
        int remaining = lists.size();
        while(remaining > 1){
            for(int i = 0; i < remaining / 2; i++) {
                auto merged = mergeTwoLists(lists[2*i], lists[2*i+1]);
                lists[i] = merged;
            }
            if(remaining%2 == 1) {
                lists[remaining/2] = lists[remaining - 1];
                remaining = remaining/2+1;
            } else {
                remaining = remaining/2;
            }
        }
        return lists.front();
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