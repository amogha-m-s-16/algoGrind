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
    ListNode* mergeSortTwoLL(ListNode* leftSide, ListNode* rightSide) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(leftSide && rightSide) {
            if(leftSide->val <= rightSide->val) {
                temp->next = leftSide;
                leftSide = leftSide->next;
            }

            else {
                temp->next = rightSide;
                rightSide = rightSide->next;
            }

            temp = temp->next;
        }

        if(leftSide) temp->next = leftSide;
        else temp->next = rightSide;

        return dummyNode->next;
    }

    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head; 

        ListNode* middleNode = findMiddle(head);

        ListNode* leftNode = head;
        ListNode* rightNode = middleNode->next;
        middleNode->next = NULL;

        ListNode* leftSide = sortList(leftNode);
        ListNode* rightSide = sortList(rightNode);

        return mergeSortTwoLL(leftSide, rightSide);
    }
};