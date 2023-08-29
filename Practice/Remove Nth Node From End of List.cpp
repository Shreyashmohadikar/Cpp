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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* curr = head;

        while(curr){
            curr = curr->next;
            count++;
        }

        if(count == n){
            return head->next;
        }

        int num = count - n - 1;
        ListNode* temp = head;
        for(int i=0; i<num; i++){
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};