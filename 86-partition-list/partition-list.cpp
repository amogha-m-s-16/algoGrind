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
    ListNode* partition(ListNode* head, int x) {
        ListNode* leftNode = new ListNode(-1);
        ListNode* rightNode = new ListNode(-1);

        ListNode* left = leftNode;
        ListNode* right = rightNode;

        while(head) {
            if(head->val < x) {
                left->next = head;
                left = left->next;
            }

            else {
                right->next = head;
                right = right->next;
            }   

            head = head->next;
        }

        left->next = rightNode->next;
        right->next = NULL;

        return leftNode->next;
    }
};