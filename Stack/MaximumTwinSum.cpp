// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

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
    int pairSum(ListNode* head) {
        stack<int> s;
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        s.push(slow->val);
        slow = slow->next;
        int res = 0;
        while(!s.empty() && slow) {
            
            res = max(res, s.top() + slow->val);
            s.pop();
            slow = slow->next;
        }
        return res;
    }
};
