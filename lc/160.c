typedef struct ListNode node;

node * getIntersectionNode(node * head_a, node * head_b)
{
    if(!head_a || !head_b)
        return 0;
    node * a = head_a, * b = head_b;
    while(a != b)
    {
        a = a ? a->next : head_b;
        b = b ? b->next : head_a;
    }
    return a;
}

class {
    public:
    int a = c;
}
