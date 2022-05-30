/* record left_node_prev, left_node, right_node
l = left_node...right_node
rev_head = reverselist(l)
left_node_prev->next = rev_head
left_node->next = right_node->next */

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

node * reverseBetween(node * head, int _left, int _right)
{
    node hair;
    hair.next = head;
    node * cur, * left_pre, * left, * right, * right_next;
    left_pre = &hair;
    for(int i = 0; i < _left - 1; ++i)
        left_pre = left_pre->next; /* node before left */
    right = left_pre;
    for(int i = 0; i < _right - _left + 1; ++i)
        right = right->next;
    left = left_pre->next,
    right_next = right->next;
    left_pre->next = 0;
    right->next = 0; 
    reverseList(left);
    left_pre->next = right;
    left->next = right_next;
    return hair.next; 
}
