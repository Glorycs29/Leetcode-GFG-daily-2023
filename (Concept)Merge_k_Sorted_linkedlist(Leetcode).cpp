class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;

        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummyTail = dummyHead;

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(auto head : lists)  if(head != NULL) pq.push({head->val, head});

        while(!pq.empty()){
            ListNode* minNode = pq.top().second;
            pq.pop();
            if(minNode->next != NULL) pq.push({minNode->next->val, minNode->next});

            dummyTail->next = minNode;
            dummyTail = dummyTail->next;
        }
        return dummyHead->next;
    }
};
