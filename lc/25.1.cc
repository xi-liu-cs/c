typedef struct ListNode node; 

node * reverseKGroup(node * head, int k) 
{
    if(!head) return head;
    node hair;
    hair.next = head;
    node * cur = &hair, 
    * next = head;
    stack<node *> s;
    while(next)
    {
        for(int i = 0; i < k && next; ++i)
        {
            s.push(next);
            next = next->next;
        }
        if(s.size() != k) break;
        while(!s.empty())
        {
            cur->next = s.top(); s.pop();
            cur = cur->next;
        }
        cur->next = next;
    }
    return hair.next;
}
