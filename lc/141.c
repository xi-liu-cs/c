typedef struct ListNode node;

bool hasCycle(node * head) 
{
    node * fast = head, * slow = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return true;
    }
    return false;
}
