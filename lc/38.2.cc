string countAndSay(int n) 
{
    string pre = "1";
    for(int i = 2; i <= n; ++i)
    {
        string cur;
        int pre_i = 0, start = 0;
        while(pre_i < pre.size())
        {
            while(pre[pre_i] == pre[start] && pre_i < pre.size())
                ++pre_i;
            cur += '0' + pre_i - start;
            cur += pre[start];
            start = pre_i;
        }
        pre = cur;
    } 
    return pre;
}
