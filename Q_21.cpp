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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
        if(!list1 && list2)return list2;
        if(!list2 && list1)return list1;
        if(!list1 && !list2)return NULL;
        ListNode* final = new ListNode(min(list1->val, list2->val));
        ListNode* temp = final;

        if (final->val == list1->val)
            list1 = list1->next;
        else
            list2 = list2->next;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                ListNode* t = new ListNode(list1->val);
                temp->next = t;
                temp = temp->next;
                list1 = list1->next;
            } else {
                ListNode* t = new ListNode(list2->val);
                temp->next = t;
                temp = temp->next;
                list2 = list2->next;
            }
        }

        while (list1) {
            ListNode* t = new ListNode(list1->val);
            temp->next = t;
            temp = temp->next;
            list1 = list1->next;
        }

        while (list2) {
            ListNode* t = new ListNode(list2->val);
            temp->next = t;
            temp = temp->next;
            list2 = list2->next;
        }

        return final;
    }
};
