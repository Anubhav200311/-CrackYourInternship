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

        if(!head)return head;
        ListNode* p= head;
        while(head->next){
            if(head->val == head->next->val){
                ListNode* temp = head->next;
                head->next = head->next->next;
                delete temp;
            }else head = head->next;
        }

        return p;
    }
};
