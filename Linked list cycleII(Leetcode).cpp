
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // by using two pointer approach
        ListNode *slow=head, *fast=head; //bool loop=false;
        // now check for loop // move fast twice as slow
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) break;
        }
        // if loop is true 
        // now our task is to find the position of begining of cycle
        if(!(fast && fast->next)) return NULL;
        while(head!=slow){
            head=head->next;
            slow=slow->next;
        }
        return head;

    }
};
