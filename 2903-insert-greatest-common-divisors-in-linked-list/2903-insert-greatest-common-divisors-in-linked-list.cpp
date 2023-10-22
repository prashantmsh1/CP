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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* temp=head;

        while(temp->next!=nullptr){
            ListNode* gcd=new ListNode();
            gcd->val=__gcd(temp->val,temp->next->val);
            gcd->next=temp->next;
            temp->next=gcd;
            temp=temp->next->next;
        }
        return head;
    }
};