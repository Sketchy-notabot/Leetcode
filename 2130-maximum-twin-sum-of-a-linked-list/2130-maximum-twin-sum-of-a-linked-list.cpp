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
    int maxSum = 0;
    ListNode* front;
    void pairSumUtil(ListNode* tail){
        if(!tail)
            return;
        pairSumUtil(tail->next);
        maxSum = max(maxSum, front->val + tail->val);
        front = front->next;
    }
    int pairSum(ListNode* head) {
        front = head;
        pairSumUtil(head);
        return maxSum;
    }
};