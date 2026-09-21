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
        auto dummy = new ListNode(INT_MIN, head);
        for(auto curPrev = head, cur = head -> next; cur;) {
            auto jPrev = dummy, j = jPrev -> next, curNext = cur -> next;
            if(cur -> val > curPrev -> val)           // cur already at correct position...so no need to update cur
                curPrev = cur;                        // only case where curPrev will need to be updated
            else {
                while(j -> val < cur -> val)
                    jPrev = j, j = j -> next;
                cur -> next = j;                      //  1️⃣
                jPrev -> next = cur;                  //  2️⃣
                curPrev -> next = curNext;            //  3️⃣    
            }
            cur = curNext;                            // move to next node now     
        }
        return dummy -> next;
    }
};