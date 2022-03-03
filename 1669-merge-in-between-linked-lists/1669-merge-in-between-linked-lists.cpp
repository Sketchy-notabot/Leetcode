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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *curr = list1, *prev = NULL;
        int count = 0;
        while(count!=a){
            prev = curr;
            count++;
            curr=curr->next;
        }
        if(prev==NULL) list1 = list2;
        else prev->next = list2;
        while(count!=b){
            curr=curr->next;
            count++;
        }
        ListNode* curr2 = list2;
        while(curr2->next)
            curr2=curr2->next;
        curr2->next = curr->next;
        return list1;
    }
};