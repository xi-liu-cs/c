typedef struct ListNode node; 

node * reverseBetween(node * head, int _left, int _right)
{
    node hair;
    hair.next = head;
    node * left_pre = &hair;
    for(int i = 0; i < _left - 1; ++i)
        left_pre = left_pre->next;
    node * cur = left_pre->next, * next;
    for(int i = 0; i < _right - _left; ++i)
    {
        next = cur->next;
        cur->next = next->next;
        next->next = left_pre->next;
        left_pre->next = next;
    }       
    return hair.next;
}
