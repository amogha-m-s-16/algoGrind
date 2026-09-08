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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;

        ListNode* temp = head;
        ListNode* dummyNode = new ListNode(-1, head);
        ListNode* prevNode = dummyNode;
        
        while(temp) {
            if(temp->val == val) prevNode->next = temp->next;

            else prevNode = temp;

            temp = temp->next;
        }

        return dummyNode->next;
    }
};