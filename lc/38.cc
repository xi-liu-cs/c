string countAndSay(int n) 
{
    if(n == 1)
        return "1";
    string pre = countAndSay(n - 1) + '\0', res;
    int cnt = 0;
    char cur = pre[0];
    for(int i = 0; i < pre.size(); ++i)
    {
        if(pre[i] == cur)
            ++cnt;
        if(pre[i] != cur)
        {
            res += '0' + cnt;
            res += cur;
            cnt = 1;
            cur = pre[i];
        }
    }
    return res;
}
