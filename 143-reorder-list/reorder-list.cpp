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
private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseLL(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* newHead = reverseLL(head->next);
        
        ListNode* frontNode = head->next;
        frontNode->next = head;
        head->next = NULL;

        return newHead;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* temp = head;

        ListNode* middleNode = findMiddle(head);

        ListNode* reverseHead = reverseLL(middleNode);

        while(temp && reverseHead) {
            ListNode* tempNext = temp->next;
            ListNode* reverseNext = reverseHead->next;

            temp->next = reverseHead;
            reverseHead->next = tempNext;

            reverseHead = reverseNext;
            temp = tempNext;
        }
  
    }
};