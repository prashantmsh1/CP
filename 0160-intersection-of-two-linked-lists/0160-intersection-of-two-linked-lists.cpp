/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> hs;
        while(headA!=nullptr){
            hs.insert(headA);
            headA=headA->next;
        }
        while(headB!=nullptr){
            auto it=hs.find(headB);
            if(it!=hs.end()){
                return headB;
            }

            headB=headB->next;
        }
        return nullptr;
    }
};