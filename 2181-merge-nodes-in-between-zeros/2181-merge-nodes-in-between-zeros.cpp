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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newHead = NULL, *curr = NULL;
        head=head->next;
        int num = 0;
        while(head){
            num+=head->val;
            if(head->val==0){
                if(!newHead){
                    newHead = new ListNode(num);
                    curr = newHead;
                }
                else{
                    curr->next = new ListNode(num);
                    curr = curr->next;
                } 
                num=0;
            }
            head=head->next;
        }
        return newHead;
    }
};