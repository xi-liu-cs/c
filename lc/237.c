typedef struct ListNode node;

void deleteNode(node * n) 
{
    *n = *n->next;
}
