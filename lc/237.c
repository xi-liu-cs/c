typedef struct ListNode node;

void deleteNode(node * n) 
{
    n->val = n->next->val;
    n->next = n->next->next;
}
