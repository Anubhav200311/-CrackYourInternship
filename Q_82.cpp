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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* p = head;
        bool flag = false;
        while (p) {
            // prev = p;
            int val = p->val;
            // ListNode* prev = p;
            ListNode* q = p->next;
            while (q && q->val == val) {
                if (!flag)
                    flag = true;
                p->next = q->next;
                delete q;
                q = p->next;
            }
            if (flag) {
                if (!prev) {
                    prev = head;
                    head = head->next;
                    p = head;
                    delete prev;
                    prev = nullptr;
                    flag = false;
                } else {
                    prev->next = p->next;
                    delete p;
                    p = prev->next;
                    flag = false;
                }

            } else {
                prev = p;
                p = p->next;
            }
        }

        return head;
    }
};
