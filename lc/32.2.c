int longestValidParentheses(char * s)
{
    int n = strlen(s), m = 0,
    stk[n + 1], top = -1;
    stk[++top] = -1;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '(')
            stk[++top] = i;
        else
        {
            --top;
            if(top == -1)
                stk[++top] = i;
            else
                m = fmax(m, i - stk[top]);
        }
    }
    return m;
}
