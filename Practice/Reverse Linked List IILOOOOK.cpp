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
private:
    ListNode* reverseList(ListNode* head, int size, ListNode* &righthead) {
        ListNode* curr = head;
        ListNode* L = NULL;
        ListNode* R = curr->next;
        while(size--){
            curr->next = L;
            L = curr;
            curr = R;
            if(R != NULL){
                R = R->next;
            }
        }
        righthead = curr;
        return L;
    }
public:
    ListNode* reverseBetween(ListNode* head, int L, int R) {
        if(head == NULL || head->next == NULL || L == R){
            return head;
        }
        ListNode* left = NULL, *curr = head;
        int size = R - L + 1;
        while(--L){
            left = curr;
            curr = curr -> next;
        }
        ListNode* righthead = NULL;
        ListNode* midhead = reverseList(curr, size, righthead);
        if(!left){
            head = midhead;
        }
        else{
            left->next = midhead;
        }

        curr->next = righthead;
        return head;
    }
};
