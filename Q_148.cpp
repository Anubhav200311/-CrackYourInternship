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
    ListNode* sortList(ListNode* head) {
        priority_queue<int , vector<int> , greater<int>>pq;

        ListNode* p = head;
        while(p){
            pq.push(p->val);
            p = p->next;
        }
        p = head;
        while(p){
            p->val = pq.top();
            pq.pop();
            p = p->next;
        }

        return head;
    }
};
