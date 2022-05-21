typedef struct ListNode node; 

node * removeNthFromEnd(node * head, int n)
{
    node * head_prev = (node *)malloc(sizeof(node));
    head_prev->val = 0, head_prev->next = head;
    node * left = head_prev, * right = head; 
    for(int i = 0; i < n; ++i)
        right = right->next; /* distance between left and right is n steps */
    while(right)
    {
        left = left->next;
        right = right->next;
    }
    node * tmp = left->next;
    left->next = left->next->next;
    node * ret = head_prev->next;
    free(tmp);
    free(head_prev);
    return ret;
}
