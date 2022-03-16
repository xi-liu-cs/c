    typedef struct ListNode node;

    node * getIntersectionNode(node * head_a, ListNode * head_b)
    {
        unordered_set<node *> memo;
        node * a = head_a, * b = head_b;
        while(a)
        {
            memo.insert(a);
            a = a->next;
        }
        while(b)
        {
            if(memo.count(b) >= 1)
                return b;
            b = b->next;
        }
        return 0;
    }
