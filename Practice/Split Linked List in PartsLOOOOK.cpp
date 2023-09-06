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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }//calculating length

        temp = head;
        int parts = len / k;
        int extras = len % k;
        vector<ListNode*> v(k, NULL);
        int j = 0;

        while(temp){
            ListNode* dummy = new ListNode(-1); 
            ListNode* curr = dummy;

            for(int i=0; i<parts; i++){
                curr->next = new ListNode(temp->val);
                temp = temp->next;
                curr = curr->next;
            }

            if(extras){
                curr->next = new ListNode(temp->val);
                temp = temp->next;
                curr = curr->next;
                extras--;
            }

            v[j] = dummy->next;
            j++;
        }
        return v;
    }
};