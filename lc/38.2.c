char * countAndSay(int n)
{
    char * pre = "1";
    for(int i = 2; i <= n; ++i)
    {
        int pre_sz = strlen(pre);
        char * cur = (char *)malloc((2 * pre_sz + 1) * sizeof(char));
        int cur_i = 0, pre_i = 0, start = 0;
        while(pre_i < pre_sz)
        {
            while(pre[pre_i] == pre[start] && pre_i < pre_sz)
                ++pre_i;
            cur[cur_i++] = '0' + pre_i - start;
            cur[cur_i++] = pre[start];
            start = pre_i;
        }
        cur[cur_i] = '\0';
        pre = cur;
    }
    return pre;
}
