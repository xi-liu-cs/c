int longestValidParentheses(string s) 
{
    int n = s.size(), 
    m = 0;
    stack<int> stk;
    stk.push(-1);
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '(')
            stk.push(i);
        else
        {
            stk.pop();
            if(stk.empty())
                stk.push(i);
            else
                m = max(m, i - stk.top());
        }
    }
    return m;
}
