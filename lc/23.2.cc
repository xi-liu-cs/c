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

node * merge(vector<node *> lists, int l, int r)
{
    if(l == r)
        return lists[l];
    if(l > r)
        return nullptr;
    int mid = l + ((r - l) >> 1); 
    return merge_two_lists(merge(lists, l, mid), merge(lists, mid + 1, r));
}

node * mergeKLists(vector<node *> & lists) 
{
    return merge(lists, 0, lists.size() - 1);
}
