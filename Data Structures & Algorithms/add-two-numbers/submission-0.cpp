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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode(0);
        ListNode *temp=dummy;
        int value=0;
        int carry=0;
        while(l1!=NULL||l2!=NULL||carry!=0){
            int value1,value2;
           if(l1==NULL){
             value1=0;
           }
           else{
            value1=l1->val;
            l1=l1->next;
           }
           if(l2==NULL){
            value2=0;
           }
           else{
            value2=l2->val;
            l2=l2->next;
           }
           value=value1+value2+carry;
           carry=value/10;
           value=value%10;
           temp->next=new ListNode(value);
           temp=temp->next;
        }
        return dummy->next;
    }
};
