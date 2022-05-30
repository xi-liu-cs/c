typedef struct ListNode node; 

node * reverseList(node * head)
{
    node * prev = 0, * cur = head, * next;
    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
