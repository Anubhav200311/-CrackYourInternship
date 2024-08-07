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
        stack<ListNode*> stk;

        ListNode* p = head;
        while(p){
            stk.push(p);
            p = p->next;
        }
        while(n){
            p = stk.top();
            stk.pop();
            n--;
        }
        if(stk.empty()){
            head = p->next;
            delete p;
            return head;
        }
        ListNode* prev = stk.top();
        
        prev->next = p->next;
        delete p;

        return head;
    }
};
