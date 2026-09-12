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
    ListNode* reverseLL(ListNode* list) {
        if(list == NULL || list->next == NULL) return list;

        ListNode* newHead = reverseLL(list->next);
        ListNode* frontNode = list->next;
        frontNode->next = list;
        list->next = NULL;

        return newHead;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        
        int carry = 0;

        ListNode* templ1 = reverseLL(l1);
        ListNode* templ2 = reverseLL(l2);

        while(templ1 || templ2 || carry) {
            int sum = 0;

            if(templ1) {
                sum += templ1->val;
                templ1 = templ1->next;
            }
            if(templ2) {
                sum += templ2->val;
                templ2 = templ2->next;
            }

            sum += carry;
            carry = sum / 10;

            ListNode* curr = new ListNode(sum % 10);
            temp->next = curr;
            temp = temp->next;
        }

        return reverseLL(dummyNode->next);
    }
};