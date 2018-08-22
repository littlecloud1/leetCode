//leetcode:2. Add Two Numbers
//use one while loop to finish iterating both list
//use 2 ListNode to record the result. one for remember the head.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {      
            ListNode* res = new ListNode(0);
            ListNode* l3 = res;
            int carry = 0;
        
            //iterate until finish l1 and l2
            while(l1 != NULL || l2 != NULL){
                int v1 = 0, v2 = 0;
                if (l1 != NULL ) v1 = l1->val;
                if (l2 != NULL ) v2 = l2->val;
                int sum = v1 + v2 + carry;
                if (sum < 10) carry = 0;
                else{
                    sum = sum - 10;
                    carry = 1;
                }
                res->next = new ListNode(sum);
                if (l1) l1 = l1->next;
                if (l2) l2 = l2->next;
                res = res->next;                
            }
            if(carry == 1){
                res->next = new ListNode(1);
            }
        
        return l3->next;
        
    }
};