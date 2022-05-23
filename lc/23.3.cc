typedef struct ListNode node;

struct status
{   
    node * ptr;
    bool operator < (const status & other) const
    {/* return true whenever "this" struct has lower priority than "other" struct */ 
        return ptr->val > other.ptr->val;   
    }
};

priority_queue<status> q;

node * mergeKLists(vector<node *> & lists) 
{
    for(int i = 0; i < lists.size(); ++i)
        if(lists[i]) q.push({lists[i]});
    node head, * tail = &head;
    while(!q.empty())
    {
        status min = q.top(); q.pop();
        tail->next = min.ptr;
        tail = tail->next;
        if(min.ptr->next) q.push({min.ptr->next});
    }
    return head.next;
}
