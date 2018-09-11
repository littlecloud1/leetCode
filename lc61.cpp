//leetcode: 61. Rotate List
//break list into two 
//then match it back.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        int n = 1;
        ListNode* curr = head;
        ListNode* newhead = head;
        while(curr->next != NULL){
            curr = curr->next;
            n++;
        }
        curr = head;
        k = n - (k % n) - 1;
        while(k > 0 && curr->next){
            curr = curr->next;
            k--;
        }
        if(curr->next) {
            newhead = curr->next;
            while(newhead->next != NULL)newhead = newhead->next;
            newhead->next = head;
            head = curr->next;
            curr->next =NULL;
            
        }
            
            
            
        return head;
    }
};