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
    int getDecimalValue(ListNode* head) {
       
        string binary_string ="";
        while(head){
           binary_string += to_string(head->val);
           head = head->next;
        }
        bitset<30>binary_number(binary_string);

        int number = 0;

        for(int i = 0 ; i <= 30 ; i++){
            if(binary_number[i])number += pow(2 , i);
        }

        return number;

    }
};
