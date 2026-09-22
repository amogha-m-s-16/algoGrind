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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = head;
        ListNode* tempNode = head;

        while(temp) {
            while(tempNode) {
                if(temp->val < tempNode->val) swap(temp->val, tempNode->val);
                tempNode = tempNode->next;
            }

            temp = temp->next;
            tempNode = head;
        }

        return head;
    }
};