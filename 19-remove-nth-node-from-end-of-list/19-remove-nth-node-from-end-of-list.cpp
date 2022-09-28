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
        ListNode *prev=NULL, *curr;
        curr = head;
        int length=0;
        while(curr){
            length++;
            curr=curr->next;
        }
        curr=head;
        int to_remove = length-n;
        while(to_remove--!=0){
            prev=curr;
            curr=curr->next;
        }
        if(prev)
            prev->next=curr->next;
        else
            head=head->next;
        return head;
    }
};