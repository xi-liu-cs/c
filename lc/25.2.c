typedef struct ListNode node; 

node * rev(node * pre, int k)
{
    node * last = pre;
    for(int i = 0; i < k + 1; ++i)
    {
        last = last->next;
        if(i != k && !last) return 0;
    }
    node * tail = pre->next,
    * cur = tail->next;
    while(cur != last)
    {
        node * next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        tail->next = next;
        cur = next;
    }
    return tail;
}

node * reverseKGroup(node * head, int k)
{
    if(!head) return head;
    node hair;
    hair.next = head;
    node * pre = &hair;
    while(pre)
        pre = rev(pre, k);
    return hair.next;
}
