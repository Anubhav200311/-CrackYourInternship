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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        if (!l1 && !l2)
            return head;
        if (l1 && !l2)
            return l1;
        if (l2 && !l1)
            return l2;
        head = new ListNode(-1);
        ListNode* p = head;
        int flag = 0;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        while (h1 && h2) {
            ListNode* temp = new ListNode(h1->val + h2->val + flag);

            flag = temp->val / 10;
            temp->val = temp->val % 10;

            flag = 0;

            p->next = temp;
            p = p->next;
            h1 = h1->next;
            h2 = h2->next;
        }
        // if (!h1 && !h2 && flag) {
        //     ListNode* temp = new ListNode(flag);
        //     p->next = temp;
        //     p = p->next;
        // }
        if (h1) {
            while (h1) {
                ListNode* temp = new ListNode(h1->val + flag);
                if (temp->val > 9) {
                    flag = temp->val / 10;
                    temp->val = temp->val % 10;
                } else
                    flag = 0;
                p->next = temp;
                p = p->next;
                h1 = h1->next;
            }
        } else if (h2) {
            while (h2) {
                ListNode* temp = new ListNode(h2->val + flag);
                if (temp->val > 9) {
                    flag = temp->val / 10;
                    temp->val = temp->val % 10;
                } else
                    flag = 0;
                p->next = temp;
                p = p->next;
                h2 = h2->next;
            }
        }
        if (flag) {
            ListNode* temp = new ListNode(flag);
            p->next = temp;
            p = p->next;
        }

        return head->next;
    }
};
