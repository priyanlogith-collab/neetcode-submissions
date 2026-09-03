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
    void reorderList(ListNode* head) {
        // First we need to figure out the middle node and split it

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;

        // secondly we need to reverse the second list 

        ListNode* prev = nullptr;
        ListNode* curr = head2;
        while(curr != nullptr){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        head2 = prev;

        // Step 3 : we need to merge the two list to do so, we need inner pointer namely phead, qhead;
        while(head2 != nullptr){
            ListNode* phead = head->next;
            ListNode* qhead = head2->next;
            head->next = head2;
            head2->next = phead;
            head = phead;
            head2 = qhead;
        }
    }
};
