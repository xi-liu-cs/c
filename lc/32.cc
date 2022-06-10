int longestValidParentheses(string s) 
{
    int n = s.size(); 
    if(!n) return 0;
    int max = 0;
    vector<int> dp(n, 0);
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == ')' && i - 1 >= 0 && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
        {/* dp[i] = 2 + dp[i - 1] + dp[i - dp[i - 1] - 2] */
            dp[i] = 2 + dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
            if(dp[i] > max)
                max = dp[i];
        }
    }
    return max;
}
