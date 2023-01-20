class Solution
{
    public:
    Node* n;
    bool fun(Node* cur){
        if(!cur)return true;
        bool b = fun(cur->next);
        if(b){
            cur->data =cur->data+1;
            if(cur->data >9){
                cur->data =0;
                if(cur==n){
                    n = new Node(1);
                    n->next = cur;
                }
                return true;
            } else return false;
        } else return false;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        n =head;
        fun(head);
        return n;
    }
};
