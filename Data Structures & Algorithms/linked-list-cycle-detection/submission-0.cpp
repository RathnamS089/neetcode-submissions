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
    bool hasCycle(ListNode* head) {
        set<ListNode *> s;
        ListNode *cur=head;
        bool b=false;
        while(cur!=nullptr){
          if(s.count(cur)){
            b=true;
            break;
          }
          s.insert(cur);
          cur=cur->next;
        }
        return b;
    }
};
