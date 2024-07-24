/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (!head)
            return NULL;
        unordered_map<Node*, Node*> mp;
        Node* newHead = new Node(head->val);
        mp[head] = newHead;

        Node* oldnode = head->next;
        Node* newnode = newHead;
        //oldnode = oldnode->next;

        while (oldnode) {
            newnode->next = new Node(oldnode->val);
            mp[oldnode] = newnode->next;
            oldnode = oldnode->next;
            newnode = newnode->next;
        }

        oldnode = head;
        newnode = newHead;

        while (oldnode) {
            if (oldnode->random) {
                newnode->random = mp[oldnode->random];
            }else newnode->random = NULL;
            oldnode = oldnode->next;
            newnode = newnode->next;
        }

        return newHead;
    }
};
