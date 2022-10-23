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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* tor = head;
        ListNode* prevtor = NULL;
        ListNode* rab = head;
        while(rab->next !=NULL && (rab->next)->next !=NULL){
            prevtor = tor;
            tor = tor->next;
            rab = rab->next->next;
        }
        if(rab->next ==NULL && rab==head){
            return NULL;
        }
        if(rab->next == NULL) 
        {
            prevtor->next = tor->next;
        }
        else
        {
            tor->next = tor->next->next;
        }
        return head;
    }
};
