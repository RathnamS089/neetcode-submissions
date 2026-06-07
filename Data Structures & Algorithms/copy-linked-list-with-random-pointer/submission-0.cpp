/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> oldtocopy;
        oldtocopy.insert({NULL,NULL});
        Node *cur=head;
        if(head==nullptr){
            return nullptr;
        }
        while(cur!=nullptr){
            Node *copy=new Node(cur->val);
            oldtocopy.insert({cur,copy});
            cur=cur->next;
        }
        Node *temp=head;
        while(temp!=nullptr){
            Node *c=oldtocopy[temp];
            c->next=oldtocopy[temp->next];
            c->random=oldtocopy[temp->random];
            temp=temp->next;
        }
        return oldtocopy[head];
    }
};
