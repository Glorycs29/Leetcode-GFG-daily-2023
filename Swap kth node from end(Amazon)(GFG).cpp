//{ Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}

// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int n, int k)
{
    
    if(k>n)return head;
    if(k==(n-k+1))return head;
    
    // we'll make pointers ...... beg , end
    // to locate pointers let's travers
    
    //beg
    Node *beg = head, *beg_prev=NULL;
    for(int i=1;i<k;i++){
        beg_prev=beg;
        beg= beg->next;
    }
    //end
    Node *end=head, *end_prev=NULL;
    for(int i=1;i<n-k+1;i++){
        end_prev=end;
        end=end->next;
    }
    
    // now swap the beg_prev and end_prev
    // beg_prev -> next should ponit to end
    // end_prev ->next should point to beg
    
    if(beg_prev!=NULL){
        beg_prev->next = end;
    }
    if(end_prev!=NULL){
        end_prev->next = beg;
    }
    
    //now swap beg->next to end->next;
    // for that temp=beg->next
    // beg->next = end->next
    // end->next = temp
    
    Node *temp=beg->next;
    beg->next = end->next;
    end->next = temp;
    
    if(k==1){
        return head=end;
    }
    if(k==n){
        return head = beg;
    }
    
    return head;
    
}
