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
    bool isPalindrome(ListNode* head) {
         ListNode* temp=head;
    bool flag=true;
    vector<int> arr;
    while(temp){
        if(temp->val>=0)
        arr.push_back(temp->val);
        
        temp=temp->next;
    }
    int j=0;
    for(int i=arr.size()-1;i>=0;i--){
        
        if(arr[i]!=arr[j] && i>=j){
            flag=false;
        }
        j++;
    }
    return flag;
    }
};