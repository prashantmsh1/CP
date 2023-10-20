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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        int k=0;
        ListNode* temp=head;
        ListNode* temp1=head;
        while(temp){
            temp=temp->next;
            count++;
        }
        if(count==1 && n==1){
            return nullptr;
        }
        else if(count==1 && n==0)
        return head;
        else if((count-n)==0){
            temp1=temp1->next;
            return temp1;
        }
        else{
            while((k+1)!=(count-n)){
                temp1=temp1->next;
                k++;
            }
            temp1->next=temp1->next->next;
            return head;

        }
    }
};