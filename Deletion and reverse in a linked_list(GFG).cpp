void deleteNode(struct Node **head, int key)
{

    Node* cur=*head;
    Node* prev=NULL;
    
    while(cur->data!=key){
        prev=cur;
        cur=cur->next;
    }
    prev->next=cur->next;
    return;

}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref)
{

    Node* head = *head_ref;
    Node* cur = head->next;
    Node* prev = head;
    
    while(cur!=head){
        Node* nxt = cur->next;
        cur->next = prev;
        prev=cur;
        cur=nxt;
    }
    cur->next=prev;
    *head_ref=prev;
    return;

}
