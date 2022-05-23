typedef struct ListNode node;

node * merge_two_lists(node * a, node * b)
{
    if(!a || !b) return a ? a : b;
    node head, * tail = &head, * a_ptr = a, * b_ptr = b;
    while(a_ptr && b_ptr)
    {
        if(a_ptr->val < b_ptr->val)
        {
            tail->next = a_ptr;
            a_ptr = a_ptr->next;
        }
        else
        {
            tail->next = b_ptr;
            b_ptr = b_ptr->next;
        }
        tail = tail->next;
    }
    tail->next = a_ptr ? a_ptr : b_ptr;
    return head.next;
}

node * mergeKLists(vector<node *> & lists) 
{
    node * ret = nullptr;
    for(int i = 0; i < lists.size(); ++i)
        ret = merge_two_lists(ret, lists[i]);
    return ret;
}
