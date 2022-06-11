int longestValidParentheses(char * s)
{
    int n = strlen(s), m = 0,
    left = 0, right = 0;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '(')
            ++left;
        else if(s[i] == ')')
            ++right;
        if(left == right)
            m = fmax(m, 2 * left);
        else if(right > left)
            left = right = 0;
    }
    left = right = 0;
    for(int i = n - 1; i >= 0; --i)
    {
        if(s[i] == '(')
            ++left;
        else if(s[i] == ')')
            ++right;
        if(left == right)
            m = fmax(m, 2 * left);
        else if(left > right)
            left = right = 0;
    }
    return m;
}
