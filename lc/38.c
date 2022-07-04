char * countAndSay(int n)
{
    if(n == 1)
        return "1";
    char * pre = countAndSay(n - 1);
    int cnt = 0;
    char cur = *pre;
    int pre_sz = strlen(pre) + 1;
    char * res = (char *)malloc(2 * pre_sz * sizeof(char));
    int res_i = 0;
    for(int i = 0; i < pre_sz; ++i)
    {
        if(pre[i] == cur)
            ++cnt;
        if(pre[i] != cur)
        {
            res[res_i++] = '0' + cnt;
            res[res_i++] = cur;
            cnt = 1;
            cur = pre[i];
        }
    }
    res[res_i] = '\0';
    return res;
}
