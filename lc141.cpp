//leetcode:141. Linked List Cycle
//use the cycle detection algorithm

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
    bool hasCycle(ListNode *head) {
        if(head){
            ListNode* walk = head;
            ListNode* jump = head;
            while(jump != NULL && jump->next != NULL){
                walk = walk->next;
                jump = jump->next->next;
                if (walk == jump) return true;
            }
        }
        return false;
    }