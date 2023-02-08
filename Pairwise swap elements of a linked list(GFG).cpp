class Solution
{
    public:
Node* pairWiseSwap(struct Node* head) 
    {
        if(!head||!(head->next))return head;
        Node* cur = head;
        Node* root = head->next;
        Node* prev = NULL;
        while(cur&&cur->next){
            Node* tmp = cur->next->next;
            if(prev){prev->next = cur->next;}
            prev = cur;
            cur->next->next = cur;
            cur->next = tmp;
            cur = tmp;
        }
        return root;
    }
};
