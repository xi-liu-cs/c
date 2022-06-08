bool valid(string s)
{
    int n = s.size();
    stack<char> sk;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '(')
            sk.push('(');
        else if(!sk.empty() && sk.top() == '(' && s[i] == ')')
            sk.pop();
        else
            return false;
    }
    return sk.empty();
}

int longestValidParentheses(string s) 
{
    int n = s.size();
    if(n < 2) return 0;
    for(int i = n % 2 ? n - 1 : n; i >= 0; i -= 2)
        for(int j = 0; j < n - i + 1; ++j)
            if(valid(s.substr(j, i)))
                return i;
    return 0;
}
